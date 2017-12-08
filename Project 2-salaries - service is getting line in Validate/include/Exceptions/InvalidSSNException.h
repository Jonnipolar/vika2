#ifndef INVALIDSSNEXCEPTION_H
#define INVALIDSSNEXCEPTION_H
#include <string>
using namespace std;

class InvalidSSNException
{
    public:
        InvalidSSNException();
        string get_message();

    private:
        string _message;
};

#endif // INVALIDSSNEXCEPTION_H
