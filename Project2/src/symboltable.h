/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * The SymbolTable class manages a collection of variable symbols and their
 * associated values, providing methods for insertion, lookup, and checking
 * for variable existence.
 * 
 * - `insert`: Adds a new variable and its value to the table. If the
 *   variable already exists, a DoubleDefinedException is thrown.
 * 
 * - `lookUp`: Retrieves the value of a variable from the table. If the
 *   variable is not found, it throws an UndefinedException with an error
 *   message.
 * 
 * ADDED METHODS
 * - `hasSymbol`: Checks if a given variable is already defined in the
 *   symbol table, returning true if it exists, false otherwise.
 * 
 * - `clear`: Empties the symbol table, removing all defined variables.
 */

#pragma once

#include <string>
#include <vector>
#include <sstream>
using namespace std;

#include "exceptions.h"

class SymbolTable {
public:
    SymbolTable() {}
    void insert(string variable, double value);
    double lookUp(string variable) const;
    void clear();
private:
    bool hasSymbol(string variable);
    struct Symbol {
        Symbol(string variable, double value) {
            this->variable = variable;
            this->value = value;
        }
        string variable;
        double value;
    };
    vector<Symbol> elements;
};


