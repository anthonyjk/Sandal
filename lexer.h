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

	void displayCode() const;

	void displayTokens() const;

	void advance();

	void devance();

	std::vector<Token> lex();

	Token nextToken();

	std::string collectString();

	std::string collectIdentifier();

	std::string collectNumeric();
};

#endif
