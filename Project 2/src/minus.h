/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * Added header guard and modified right to be a vector of expressions
 * 
 * This code defines a `Minus` class that inherits from the `SubExpression` class. 
 * The constructor takes a left-hand side `Expression` pointer and a vector of right-hand side `Expression` pointers, 
 * which are passed to the base class `SubExpression` constructor.
 * The `evaluate()` function implements the subtraction operation, 
 * returning the result of subtracting the evaluation of the first element in the `right` vector 
 * from the evaluation of the `left` expression.
 */


#pragma once

class Minus: public SubExpression {
public:
    Minus(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return left->evaluate() - right.front()->evaluate();
    }
};