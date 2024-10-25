// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SymbolTable class. The insert function 
// inserts a new variable symbol and its value into the symbol table and the lookUp function returns
// that value of the supplied variable symbol name.

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
