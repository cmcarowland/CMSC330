/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * Moved imports to the header file and added a header guard
 * 
 * This code defines a `Variable` class, which inherits from the `Operand` class. 
 * The class represents a variable with a name, and it stores this name as a `string` member variable.
 * The constructor takes a `string` representing the variable's name and initializes the `name` member.
 * The `evaluate()` function looks up the value of the variable in a global `SymbolTable` using its `name` 
 * and returns the corresponding value.
 * The `SymbolTable` is assumed to manage variable bindings and is externally declared with `extern`.
 */


#pragma once

#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "operand.h"
#include "symboltable.h"

class Variable: public Operand {
public:
    Variable(string name) {
        this->name = name;
    }
    double evaluate();
private:
    string name;
};