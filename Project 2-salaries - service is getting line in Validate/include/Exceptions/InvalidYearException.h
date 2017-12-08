#ifndef INVALIDYEAREXCEPTION_H
#define INVALIDYEAREXCEPTION_H
#include <string>
using namespace std;

class InvalidYearException
{
    public:
        InvalidYearException();
        string get_message();

    private:
        string  _message;
};

#endif // INVALIDYEAREXCEPTION_H
