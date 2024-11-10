/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * The parseName function reads from a stringstream to extract a valid
 * identifier (name) that consists of alphanumeric characters and underscores.
 * 
 * It ignores leading whitespace and then constructs the name by appending
 * characters as long as the next character is alphanumeric or, if the name
 * has already started, the character is an underscore. The function
 * returns the constructed name as a string.
 *
 * The parseAssignments function processes a stringstream to read and handle
 * a series of assignments. It ensures that each assignment follows proper
 * syntax rules and interacts with the symbol table as necessary. This function
 * is used for parsing assignment expressions and updating symbols accordingly.
 */

#pragma once

#include <cctype>
#include <sstream>
#include <string>
using namespace std;

#include "exceptions.h"
#include "symboltable.h"

string parseName(stringstream& in);
void parseAssignments(stringstream& in);