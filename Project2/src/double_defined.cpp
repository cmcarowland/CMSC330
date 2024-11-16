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

#include "double_defined.h"

DoubleDefinedException::DoubleDefinedException(const string& msg) : m_msg(msg) {}

DoubleDefinedException::~DoubleDefinedException() {}

const char* DoubleDefinedException::what() const throw ()
{
    return m_msg.c_str();
}