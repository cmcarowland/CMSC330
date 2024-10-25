// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SymbolTable class. The insert function 
// inserts a new variable symbol and its value into the symbol table and the lookUp function returns
// that value of the supplied variable symbol name.

#include "symboltable.h"

void SymbolTable::insert(string variable, double value) {
    double element = -1;
    if(lookUp(variable) != -1) {
        stringstream ss;
        ss << variable << " Was previously defined"; 
        throw DoubleDefinedException(ss.str().c_str());
    }

    const Symbol& symbol = Symbol(variable, value);
    elements.push_back(symbol);
}

double SymbolTable::lookUp(string variable) const {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
             return elements[i].value;

    return -1;
}

void SymbolTable::clear()
{
    elements.clear();
}
