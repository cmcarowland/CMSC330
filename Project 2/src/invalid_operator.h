/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * Class InvalidOperatorException: Inherits from std::exception.
 * 
 * This class represents a custom exception for handling invalid operator 
 * cases. It includes a constructor that takes a message and overrides the 
 * what() method to return that message when the exception is thrown.
 */

#pragma once

#include <iostream>
#include <string>

using namespace std;

class InvalidOperatorException : public exception
{
public:
    InvalidOperatorException(const string& msg);
    ~InvalidOperatorException();

    virtual const char* what() const throw (); 
    
    const string m_msg;
};