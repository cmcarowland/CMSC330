/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * Class Multiply: Inherits from SubExpression.
 * 
 * This class performs multiplication between a left expression and 
 * the first right expression. The evaluate method returns the product 
 * of the evaluated values of both expressions.
 */

#pragma once

class Multiply: public SubExpression {
public:
    Multiply(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return left->evaluate() * right.front()->evaluate();
    }
};