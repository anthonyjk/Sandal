#include "token.h"
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

Token::Token(TokenType type, const std::string& value)
	: type(type), value(value) {}

TokenType Token::type() const {
	return type;
}

std::string Token::value() const {
	return value;
}

void Token::show() const {
	std::stringstream ss;
	ss << type << ", " << value;

	std::string self = ss.str();
	std::cout << self << std::endl;
}