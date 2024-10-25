/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * The Quaternary class extends the SubExpression class to implement a
 * conditional evaluation based on the result of a left expression.
 * 
 * It takes a left Expression and a vector of right Expressions. The
 * `evaluate` method evaluates the left expression and returns the
 * result of one of the right expressions based on the value of the
 * left expression:
 * - If the result is negative, it evaluates and returns the first
 *   right expression.
 * - If the result is zero, it evaluates and returns the second right
 *   expression.
 * - If the result is positive, it evaluates and returns the third
 *   right expression.
 */

#pragma once

class Quaternary: public SubExpression {
public:
    Quaternary(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
        double result = left->evaluate();
        if(result < 0)
            return right[0]->evaluate();
        else if(result == 0)
            return right[1]->evaluate();
        else
            return right[2]->evaluate();
    }
};