#include "double_defined.h"

DoubleDefinedException::DoubleDefinedException(const string& msg) : m_msg(msg) {}

DoubleDefinedException::~DoubleDefinedException() {}

const char* DoubleDefinedException::what() const throw ()
{
    return m_msg.c_str();
}