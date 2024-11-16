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

#include "parse.h"

extern SymbolTable symbolTable;

string parseName(stringstream& in) {
    char alnum;
    string name = "";

    in >> ws;
    while (isalnum(in.peek()) || in.peek() == '_') {
        in >> alnum;
        name += alnum;
    }
    if(name[0] == '_')
        throw InvalidNameException("Name cannot start with an underscore!");
        
    return name;
}

void parseAssignments(stringstream& in) {
	char assignop, delimiter;
    string variable;
    double value;

    do {
        variable = parseName(in);
        in >> ws >> assignop >> value >> delimiter;
		try{
        	symbolTable.insert(variable, value);
		} catch (DoubleDefinedException e) {
			throw;
        }
    } while (delimiter == ',');
}