#include "undefined_exception.h"

UnefinedException::UnefinedException(const string& msg) : m_msg(msg) {}

UnefinedException::~UnefinedException() {}

const char* UnefinedException::what() const throw ()
{
    return m_msg.c_str();
}