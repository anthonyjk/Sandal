#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum TokenType {
	TK_EMPTY,
	TK_ID, // Identifier Token
	// Data Types
	TK_STR,
	TK_INT,
	TK_FLOAT,
	// Operators
	TK_ASSIGN, // Assigns (var <= int)
	TK_EQUALS, // Assigns (var = int)
	TK_POINT, // Operates (data => mean)
	TK_PLUS,
	TK_MINUS,
	TK_MULTIPLY,
	TK_DIVIDE,
	TK_COLON,
	// Conditions
	TK_IF,
	TK_FOR,
	TK_WHILE,
	// Comparsions,
	TK_LESS,
	TK_GREATER,
	TK_IS, // var is 5
	TK_ISNT, // var isnt 5
	// Syntax
		// Parens & Similar
	TK_LPAREN,
	TK_RPAREN,
	TK_LBRACKET,
	TK_RBRACKET,
	TK_LCURLY,
	TK_RCURLY,
	// Other
	TK_SEMI, // Semi-colon
	TK_EOF
};

class Token {
	public:
		Token(TokenType type, const std::string& value);
		TokenType getType() const;
		std::string getValue() const;
		void show() const;

	private:
		TokenType type;
		std::string value;
};

#endif
