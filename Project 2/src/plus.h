/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * Added header guard and modified right to be a vector of expressions
 * 
 * This code defines a `Plus` class that inherits from the `SubExpression` class. 
 * The constructor takes a left-hand side `Expression` pointer and a vector of right-hand side `Expression` pointers, 
 * which are passed to the base class `SubExpression` constructor.
 * The `evaluate()` function implements the addition operation, 
 * returning the result of adding the evaluation of the first element in the `right` vector 
 * to the evaluation of the `left` expression.
 */


#pragma once

class Plus: public SubExpression {
public:
    Plus(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate()  {
       return left->evaluate() + right.front()->evaluate();
    }
};