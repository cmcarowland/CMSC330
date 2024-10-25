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