#include "token.h"
#include "parser.h"
#include "ASTNode.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), nodes({}), pointer(0) {
}

std::vector<Node> Parser::parse() {
	while(pointer < tokens.size()) {
		nodes.push_back(readLine());
	}
}

void Parser::advance() {
    pointer++;
}

Node Parser::readLine() {
	return expression();
}

Node Parser::expression() {
	Node node = term();
	if(tokens[pointer].getType() == TK_PLUS || tokens[pointer].getType() == TK_MINUS){
		Node op = Node(NodeType::EXPRESSION);
		op.setOperator(tokens[pointer].getType())
		op.createChild(node); //left
		op.createChild(term());
		return op;
	}
	return node;
}

Node Parser::term() {
	Node node = factor();
	if(tokens[pointer].getType() == TK_MULTIPLY || tokens[pointer].getType() == TK_DIVIDE) {
		Node op = Node(NodeType::EXPRESSION);
		op.setOperator(tokens[pointer].getType())
		op.createChild(node); // left
		op.createChild(factor()); // right
		return op;
	}
	return node;
}

Node Parser::factor() {
	Token token = tokens[pointer];
	if(token.getType() == TK_INT) {
		advance();
		Node node = Node(NodeType::LITERAL);
		node.assignValue(token.getValue());
		return node;
	} else if(token.getType() == TK_LPAREN) {
		advance();
		Node node = expression();
		advance();
	} else {
		// error
	}
}
