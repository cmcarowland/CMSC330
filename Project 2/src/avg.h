/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * Added Pragma once header guard
 * 
 * The Avg class extends the SubExpression class to implement the
 * calculation of an average based on the evaluation of a left expression
 * and the first right expression.
 * 
 * It takes a left Expression and a vector of right Expressions. The
 * `evaluate` method computes the average by adding the result of the
 * left expression to the result of the first right expression and
 * dividing the sum by 2.0.
 */

#pragma once

class Avg: public SubExpression {
public:
    Avg(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return (left->evaluate() + right.front()->evaluate()) / 2.0;
    }
};