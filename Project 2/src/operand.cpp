/**
 * Raymond Rowland
 * 10 Nov 24
 * Project 2
 * 
 * The Operand class provides a method to parse an input stream to create
 * different types of expressions, such as literals, sub-expressions, or variables.
 * 
 * The parse method reads from a stringstream, identifies the type of operand,
 * and constructs the appropriate expression object to be returned.
 */

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