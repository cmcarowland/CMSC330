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

#include "parse.h"

string parseName(stringstream& in) {
    char alnum;
    string name = "";

    in >> ws;
    while (isalnum(in.peek()) || (name.length() > 0 && in.peek() == '_')) {
        in >> alnum;
        name += alnum;
    }
    return name;
}