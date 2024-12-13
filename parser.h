#ifndef PARSER_H
#define PARSER_H
#include "syntaxNode.h"
#include "token.h"
#include <vector>
#include <string>

class Parser {
private:
    std::vector<Token> tokens;
    std::vector<Node> nodes;
    int pointer;

public:
    Parser(const std::vector<Token>& tokens);

    std::vector<Node> parse();

    void advance();

    Node readLine();
};
#endif
