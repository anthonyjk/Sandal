#include "token.h"
#include "parser.h"
#include "syntaxNode.h"
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), nodes({}), pointer(0) {
}

std::vector<Node> Parser::parse() {
	while(pointer < tokens.length()) {
		nodes.push_back(readLine());
	}
}

void Parser::advance() {
    pointer++;
}

Node Parser::readLine() {
	while(tokens[pointer].getType() != TK_SEMI) {
		switch(tokens[pointer].getType()) {

			case TK_ID:

				// Assignment with ID
				if(tokens[pointer + 1].getType() == TK_ASSIGN) {
					if(tokens[pointer + 2].getType() == TK_INT || tokens[pointer + 2].getType() == TK_STR ) {
						Node left = Node(NodeType::IDENTIFIER);
						left.assignValue(tokens[pointer].getValue());

						Node right = Node(NodeType::LITERAL);
						right.assignValue(tokens[pointer + 2].getValue());

						Node center = Node(NodeType::DECLARATIVE);
						center.createChild(left);
						center.createChild(right);

						return center; // UPDATE CODE TO ACCOUNT FOR EXPR SUCH AS: x <= 5 + 5 + 5 + 5 + 5;
					}
				}

				// Other with ID
				//pass
				break;

			case TK_ASSIGN:
				break;
		}
		advance();
	}
}
