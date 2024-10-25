/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * The Ternary class extends the SubExpression class to implement a ternary
 * conditional evaluation based on the result of a left expression.
 * 
 * It takes a left Expression and a vector of right Expressions. The
 * `evaluate` method evaluates the left expression and returns the result
 * of one of the right expressions based on the value of the left
 * expression:
 * - If the result is zero, it evaluates and returns the first right
 *   expression.
 * - If the result is non-zero, it evaluates and returns the second right
 *   expression.
 */

#pragma once

class Ternary: public SubExpression {
public:
    Ternary(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
        double result = left->evaluate();
        return result == 0 ? right[0]->evaluate() : right[1]->evaluate();
    }
};