/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * Class Mod: Inherits from SubExpression.
 * 
 * This class performs the modulus operation between a left expression 
 * and the first right expression. The evaluate method computes the 
 * remainder of the division of the evaluated values, casting them to 
 * integers before performing the modulus operation.
 */

#pragma once

class Mod: public SubExpression {
public:
    Mod(Expression* left, vector<Expression*> right): SubExpression(left, right) {}
    
    double evaluate() {
       return (int)left->evaluate() % (int)right.front()->evaluate();
    }
};