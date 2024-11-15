/*
 * Raymond Rowland
 * 25 OCT 24
 * Project 2
 *

 */

#pragma once

#include <iostream>
#include <string>

using namespace std;

class InvalidNameException : public exception
{
public:
    InvalidNameException(const string& msg);
    ~InvalidNameException();

    virtual const char* what() const throw (); 
    
    const string m_msg;
};