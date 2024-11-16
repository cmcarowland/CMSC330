/**
 * Raymond Rowland
 * 10 Nov 24
 * Project 2
 * 
 * The Operand class provides a method to parse an input stream to create
 * different types of expressions, such as literals, sub-expressions, or variables.
 * 
 * The parse method reads from a stringstream, identifies the type of operand,
 * and constructs the appropriate expression object to be returned.
 */

#pragma once

#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "parse.h"

class Operand: public Expression {
public:
    static Expression* parse(stringstream& in);
};

#include "literal.h"
#include "variable.h"
