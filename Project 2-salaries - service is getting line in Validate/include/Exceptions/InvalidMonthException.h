#ifndef INVALIDMONTHEXCEPTION_H
#define INVALIDMONTHEXCEPTION_H
#include <string>
using namespace std;

class InvalidMonthException
{
    public:
        InvalidMonthException();
        string get_message();

    private:
        string  _message;
};

#endif // INVALIDMONTHEXCEPTION_H
