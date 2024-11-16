/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 * 
 * The UnefinedException class represents an exception thrown when an
 * undefined variable is encountered during expression evaluation.
 * 
 * - The constructor initializes the exception with a specific message.
 * - The destructor ensures proper cleanup.
 * - The `what` method returns the error message as a C-style string,
 *   providing information about the exception when it is thrown.
 */

#pragma once

#include <iostream>
#include <string>

using namespace std;

class UnefinedException : public exception
{
public:
    UnefinedException(const string& msg);
    ~UnefinedException();

    virtual const char* what() const throw (); 
    
    const string m_msg;
};