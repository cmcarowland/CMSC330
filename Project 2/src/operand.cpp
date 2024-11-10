// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the function parseName contained in the Operand class. That function
// parses the next token. When the next non-whitespace character is a digit, it assumes a literal is next. 
// When the next character is a left parenthesis, a recursive call is made to parse the subexpression.
// Otherwise the next token is assumed to a variable. No checks are made to ensure correct syntax.

#include "operand.h"

Expression* Operand::parse(stringstream& in) {
    char paren;
    double value;

    in >> ws;
    if (isdigit(in.peek()) || in.peek() == '-') {
        in >> value;
        Expression* literal = new Literal(value);
        return literal;
    }

    if (in.peek() == '(') {
        in >> paren;
        return SubExpression::parse(in);
    }
    else
        return new Variable(parseName(in));
        
    return 0;
}