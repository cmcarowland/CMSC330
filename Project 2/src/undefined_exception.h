#include <iostream>
#include <string>

using namespace std;

class UnefinedException : public exception
{
public:
    UnefinedException(const string& msg);
    ~UnefinedException();

    virtual const char* what() const throw (); 
    
    const string m_msg;
};