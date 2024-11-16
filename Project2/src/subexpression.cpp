/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * The SubExpression class serves as a base for expressions that consist of
 * a left operand and one or more right operands. It provides two constructors
 * for initializing the left and right expressions.
 * 
 * The `parse` method reads an input stream to construct an expression.
 * It first parses a left operand, then reads an operator followed by a
 * series of right operands until a closing parenthesis is encountered.
 * Based on the operator, it creates and returns the appropriate expression
 * object (e.g., Plus, Minus, Multiply, etc.).
 * 
 * If an unsupported operator is encountered, an InvalidOperatorException
 * is thrown with a relevant error message.
 */

#include "subexpressions.h"

SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = vector<Expression*>{right};
}

SubExpression::SubExpression(Expression* left, vector<Expression*>& right) {
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    vector<Expression*> right;
    char operation, paren;
    
    left = Operand::parse(in);
    in >> operation;
    in >> ws;
    while(in.peek() != ')'){
        right.push_back(Operand::parse(in));
        in >> ws;
    }
    in >> paren;

    switch (operation) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Multiply(left, right);
        case '/':
            return new Divide(left, right);
        case '%':
            return new Mod(left, right);
        case '^':
            return new Exponent(left, right);
        case '<':
            return new Min(left, right);
        case '>':
            return new Max(left, right);
        case '&':
            return new Avg(left, right);
        case '~':
            return new Invert(left, right);
        case '?':
            return new Ternary(left, right);
        case '#':
            return new Quaternary(left, right);
    }

    stringstream ss;
    ss << operation << " is not supported yet";
    throw InvalidOperatorException(ss.str().c_str());
}
        