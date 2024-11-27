#include "lexer.h"
#include "token.h"
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

	Lexer myLexer(code);

	myLexer.lex();

	myLexer.displayTokens();

	return 0;
}
	
