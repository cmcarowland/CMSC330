/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * This code defines an abstract base class named `Expression`. 
 * It declares a pure virtual function `evaluate()`, which must be implemented by any derived class. 
 * The `evaluate()` function is expected to return a `double` value, 
 * likely representing the result of evaluating the expression.
 */

#pragma once

class Expression {
public: 
    virtual double evaluate() = 0;
};