/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * The Divide class extends the SubExpression class to implement division
 * between the evaluation of a left expression and the first right expression.
 * 
 * It takes a left Expression and a vector of right Expressions. The
 * `evaluate` method performs the division by evaluating the left
 * expression and dividing it by the result of the first right expression.
 */

#pragma once

class Divide: public SubExpression {
public:
    Divide(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return left->evaluate() / right.front()->evaluate();
    }
};