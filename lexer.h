#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "token.h"

class Lexer {
private:
	std::vector<Token> tokens;
	std::string code;
	int pointer = 0;

public:
	Lexer(const std::string& code);

	void displayTokens() const;

	std::vector<Token> lex();

	void advance();

	void skipEmpty();

	void skipLine();

	Token getNextToken();
};

#endif
