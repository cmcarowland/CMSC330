/*
 * Raymond Rowland
 * 15 NOV 24
 * Project 2
 *
 *
 */

#include "invalid_name.h"

InvalidNameException::InvalidNameException(const string& msg) : m_msg(msg) {}

InvalidNameException::~InvalidNameException() {}

const char* InvalidNameException::what() const throw ()
{
    return m_msg.c_str();
}