/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * The Literal class inherits from the Operand class and represents a literal numeric value.
 * 
 * This class is used to encapsulate and evaluate a specific numeric value.
 * 
 * Public methods:
 * - Constructor: Takes a double value and initializes the member variable.
 * - evaluate: Returns the stored numeric value.
 * 
 * Private members:
 * - value: A double that holds the numeric value represented by this literal.
 */

#pragma once
#include "operand.h"

class Literal: public Operand {
public:
    Literal(double value) {
        this->value = value;
    }
    double evaluate() {
        return value;
    }
private:
    double value;
};