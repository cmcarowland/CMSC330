/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *
 * Class DoubleDefinedException: Inherits from std::exception.
 * 
 * This class represents a custom exception for handling cases of 
 * double definitions. It includes a constructor that accepts a message 
 * and overrides the what() method to return the exception message.
 */

#pragma once

#include <iostream>
#include <string>

using namespace std;

class DoubleDefinedException : public exception
{
public:
    DoubleDefinedException(const string& msg);
    ~DoubleDefinedException();

    virtual const char* what() const throw (); 
    
    const string m_msg;
};