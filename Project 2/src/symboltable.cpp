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

#include "symboltable.h"

void SymbolTable::insert(string variable, double value) {
    if(hasSymbol(variable)) {
        stringstream ss;
        ss << variable << " Was previously defined"; 
        throw DoubleDefinedException(ss.str().c_str());
    }

    const Symbol& symbol = Symbol(variable, value);
    elements.push_back(symbol);
}

bool SymbolTable::hasSymbol(string variable) {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
             return true;

    return false;
}

double SymbolTable::lookUp(string variable) const {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
             return elements[i].value;

    stringstream ss;
    ss << variable << " was never defined for this equation"; 
    throw UnefinedException(ss.str().c_str());
}

void SymbolTable::clear()
{
    elements.clear();
}
