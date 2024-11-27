#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "lexer.h"
#include "token.h"

Lexer::Lexer(const std::string& code) : code(code), pointer(0), tokens({}) {
}

// Debug Functions
void Lexer::displayCode() const {
	std::cout << code << std::endl;
}

void Lexer::displayTokens() const {
	for(const auto& token : tokens)
	{
		token.show();
	}
}

std::vector<Token> Lexer::lex() {
	while (pointer < code.length()) {
		tokens.push_back(nextToken());
		advance();
	}

	return tokens;
}

void Lexer::advance() {
	pointer++;
}

void Lexer::devance() {
	pointer--;
}

Token Lexer::nextToken() {

	// Skip empty space
	while(code[pointer] == '\t' || code[pointer] == ' ') {
		advance();
	}
	char ch = code[pointer];

	switch(ch) {
		case '\n':
			return Token(TokenType::TK_NEWLINE, "\n");
			break;
		case '(':
			return Token(TokenType::TK_LPAREN, "(");
			break;
		case ')':
			return Token(TokenType::TK_RPAREN, ")");
			break;
		case '{':
			return Token(TokenType::TK_LCURLY, "{");
			break;
		case '}':
			return Token(TokenType::TK_RCURLY, "}");
			break;
		case '[':
			return Token(TokenType::TK_LBRACKET, "[");
			break;
		case ']':
			return Token(TokenType::TK_RBRACKET, "]");
			break;
		case ':':
			return Token(TokenType::TK_COLON, ":");
			break;
		case '"':
			return Token(TokenType::TK_STR, collectString());
			break;
		case '+':
			return Token(TokenType::TK_PLUS, "+");
			break;
		case '-':
			return Token(TokenType::TK_MINUS, "-");
			break;
		case '*':
			return Token(TokenType::TK_MULTIPLY, "*");
			break;
		case '/':
			return Token(TokenType::TK_DIVIDE, "/");
			break;
		case '=':
			// Check for type
			if (pointer + 1 < code.length()) {
				std::string expr = code.substr(pointer, 2);

				// Prevent issues

				if(expr == "<=") {
					advance();
					return Token(TokenType::TK_ASSIGN, "<=");
				} else if (expr == "=>") {
					advance();
					return Token(TokenType::TK_POINT, "=>");
				} else {
					return Token(TokenType::TK_EQUALS, "=");
				}
			} else {
				return Token(TokenType::TK_EQUALS, "=");
			}
			break;
		default:
			if(isdigit(ch)) {
				return Token(TokenType::TK_INT, collectNumeric()); // Will add more datatypes later
			} else {
				return Token(TokenType::TK_ID, collectIdentifier());
			}
			break;
		}
}

std::string Lexer::collectString() {
	std::string str;

	advance(); // Skip first quote

	while (pointer < code.length() && code[pointer] != '"') {
		str += code[pointer];
		advance();
	}

	// no overstepping prevention needed here since it will skip the last quotation

	return str;
}

std::string Lexer::collectIdentifier() {
	std::string id;

	while(pointer < code.length() && isalnum(code[pointer])) {
		id += code[pointer];
		advance();
	}

	devance(); // prevent overstepping

	return id;
}

std::string Lexer::collectNumeric() {
	std::string num;

	while(pointer < code.length() && code[pointer] != ' ' && isdigit(code[pointer])) {
		num += code[pointer];
		advance();
	}

	devance(); // prevent overstepping

	return num;
}

// Lexing Functions
// Main Lex