/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * Class Max: Inherits from SubExpression.
 * 
 * This class calculates the maximum value between a left expression and 
 * the first right expression. The evaluate method returns the larger of 
 * the evaluated values using the max function.
 */

#pragma once

class Max: public SubExpression {
public:
    Max(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return max(left->evaluate(), right.front()->evaluate());
    }
};