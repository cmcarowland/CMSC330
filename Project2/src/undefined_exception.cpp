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


#include "undefined_exception.h"

UnefinedException::UnefinedException(const string& msg) : m_msg(msg) {}

UnefinedException::~UnefinedException() {}

const char* UnefinedException::what() const throw ()
{
    return m_msg.c_str();
}