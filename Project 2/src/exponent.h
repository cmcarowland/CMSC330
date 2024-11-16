/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *  
 * Class Exponent: Inherits from SubExpression.
 * 
 * This class represents the exponentiation of a left expression raised 
 * to the power of the first right expression. The evaluate method computes 
 * the result using the pow function on the evaluated values of the two 
 * expressions.
 */

#pragma once

class Exponent: public SubExpression {
public:
    Exponent(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return pow(left->evaluate(), right.front()->evaluate());
    }
};