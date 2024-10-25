/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * Class Invert: Inherits from SubExpression.
 * 
 * This class represents the negation of a left expression. The evaluate 
 * method computes the result by negating the evaluated value of the left 
 * expression.
 */

#pragma once

class Invert: public SubExpression {
public:
    Invert(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
        return -(left->evaluate());
    }
};