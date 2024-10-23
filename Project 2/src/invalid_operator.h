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