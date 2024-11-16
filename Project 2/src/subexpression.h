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
#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

#include "exceptions.h"
#include "expression.h"
#include "operand.h"

class SubExpression: public Expression {
public:
    SubExpression(Expression* left, Expression* right);
    SubExpression(Expression* left, vector<Expression*>& right);
    static Expression* parse(stringstream& in);
protected: 
    Expression* left;
    vector<Expression*> right;
};    