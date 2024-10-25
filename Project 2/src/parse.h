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
 */

#pragma once

#include <cctype>
#include <sstream>
#include <string>
using namespace std;

string parseName(stringstream& in);