#ifndef SYNTAXNODE_H
#define SYNTAXNODE_H
#include <string>
#include <vector>
#include "token.h"

enum NodeType {
	EXPRESSION, // Math expression, e.g. x + y
	FUNCTION, // Function call, e.g. func()
	DECLARATIVE, // Variable declaration, e.g. x <= int 15
	LITERAL, // Stand-alone string or number, e.g. "String" or 7
	CONDITIONAL, // Condition, such as an if statement
	BLOCK // Code block
};

class Node {
	private:
		NodeType type;
		std::vector<Node> children;

		// For expressions
		Token op = Token(TokenType::TK_EMPTY, " ");

		// Value
		std::string value;

	public:
		Node(NodeType type);

		void createChild(Node child);

		Node left();

		Node right();

		int n_children() const;

		void setOperator(Token token);

		Token getOperator() const;

		void assignValue(std::string string);
};
#endif