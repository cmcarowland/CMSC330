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

#include "invalid_operator.h"

InvalidOperatorException::InvalidOperatorException(const string& msg) : m_msg(msg) {}

InvalidOperatorException::~InvalidOperatorException() {}

const char* InvalidOperatorException::what() const throw ()
{
    return m_msg.c_str();
}