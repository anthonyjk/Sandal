#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "syntaxNode.h"

Node::Node(NodeType type) : type(type), children({}) {
}


// Node Assignment
void Node::createChild(Node child) {
	children.push_back(child);
}

Node Node::left() {
	if (children.size() > 0) {
		return children[0];
	} else {
		throw std::runtime_error("No Left Child");
	}
}

Node Node::right() {
	if (children.size() > 1) {
		return children[1];
	} else {
		throw std::runtime_error("No Right Child");
	}
}

int Node::n_children() const {
	return children.size();
}

// EXPRESSION Nodes
void Node::setOperator(Token token) {
	if(type == EXPRESSION) {
		op = token;
	} else {
		throw std::runtime_error("Cannot assign operator to non-expression node.");
	}
}

Token Node::getOperator() const {
	if(op.getType() != TK_EMPTY) {
		return op;
	} else {
		throw std::runtime_error("No operator found.");
	}
}

void Node::assignValue(std::string new_value) {
	value = new_value;
}

