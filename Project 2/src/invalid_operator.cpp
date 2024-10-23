#include "invalid_operator.h"

InvalidOperatorException::InvalidOperatorException(const string& msg) : m_msg(msg) {}

InvalidOperatorException::~InvalidOperatorException() {}

const char* InvalidOperatorException::what() const throw ()
{
    return m_msg.c_str();
}