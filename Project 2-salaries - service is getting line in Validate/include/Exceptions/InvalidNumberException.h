#ifndef INVALIDNUMBEREXCEPTION_H
#define INVALIDNUMBEREXCEPTION_H
#include <string>
using namespace std;


class InvalidNumberException
{
    public:
        InvalidNumberException();
        string get_message();
    private:
        string _message;
};

#endif // INVALIDNUMBEREXCEPTION_H
