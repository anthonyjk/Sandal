#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum TokenType {
	TK_ID, // Identifier Token
	// Data Types
	TK_STR,
	TK_INT,
	TK_FLOAT,
	// Operators
	TK_ASSIGN, // Assigns (var <- int)
	TK_EQUALS, // Assigns (var = int)
	TK_POINT, // Operates (data => mean)
	// Conditions
	TK_IF,
	TK_FOR,
	TK_WHILE,
	// Comparsions,
	TK_LESS,
	TK_GREATER,
	TK_IS, // var is 5
	TK_ISNT, // var isnt 5
	// Other
	TK_NEWLINE,
	TK_EOF
};

class Token {
public:
	Token(TokenType type, const std::string& value);
	TokenType type() const;
	std::string value() const;
	void show() const;

private:
	TokenType type;
	std::string value;
};

#endif
