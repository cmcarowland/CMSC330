/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * The entry point of the application.
 * It reads an input file named "input.txt" containing
 * statements with expressions and variable assignments. The program parses
 * each line, evaluates the expressions, and handles exceptions related to
 * invalid operators, double definitions of variables, and undefined variables.
 *
 * The SymbolTable class is used to manage variable assignments. The
 * `parseAssignments` function reads and stores variable values from the
 * input stream. The program continues processing lines until the end of the
 * file, outputting results or error messages as necessary.
 */



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include "exceptions.h"

SymbolTable symbolTable;

int main() {
	const int SIZE = 256;
	Expression* expression;
    char paren, comma, line[SIZE];
 
	ifstream fin;
	fin = ifstream("input.txt");
	if (!(fin.is_open())) {
		cout << "File did not open" << endl;
		system("pause");
		return 1;
	}

	while (true) {
        fin.getline(line, SIZE);
		if (!fin)
			break;

		symbolTable.clear();
		stringstream in(line, ios_base::in); 
		in >> paren;
		cout << line << " ";
		try {
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			double result = expression->evaluate();
			cout << "Value = " << result << endl;
		} catch(const InvalidOperatorException& e) {
			cout << endl << endl << "** " << e.what() << endl;
		} catch(const DoubleDefinedException& e) {
			cout << endl << "** " << e.what() << " Expression aborted" << endl;
    	} catch(const UnefinedException& e) {
			cout << endl << "** " << e.what() << " Expression aborted" << endl;
    	}
	}

	system("pause");
	return 0;
}
