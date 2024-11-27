#include "lexer.h"
#include "token.h"
#include "syntaxNode.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main() {
	std::ifstream codefile("script.sand");
	std::string str;
	std::string code;
	while (std::getline(codefile, str)) {
		code += str;
		code.push_back('\n');
	}

	//std::cout << code <<std::endl;

	//Lexer myLexer(code);

	//myLexer.lex();

	//myLexer.displayTokens();

	Token seven = Token(TokenType::TK_INT, "7"); 

	Token times = Token(TokenType::TK_MULTIPLY, "*");

	Token three = Token(TokenType::TK_INT, "3");

	Node syn = Node(NodeType::EXPRESSION);

	Node left_node = Node(NodeType::LITERAL);
	left_node.assignValue(seven.getValue());
	Node right_node = Node(NodeType::LITERAL);
	right_node.assignValue(three.getValue());
	syn.createChild(left_node);
	syn.createChild(right_node);

	syn.setOperator(times);

	syn.getOperator().show();

	std::cout << syn.n_children();

	return 0;
}
	
