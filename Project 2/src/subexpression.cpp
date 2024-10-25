// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

#include "invalid_operator.h"
#include "expression.h"
#include "subexpression.h"
#include "operand.h"

#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "mod.h"
#include "min.h"
#include "max.h"
#include "exponent.h"
#include "avg.h"
#include "invert.h"

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
    cout << endl;
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
    }

    stringstream ss;
    ss << operation << " is not supported yet";
    throw InvalidOperatorException(ss.str().c_str());
}
        