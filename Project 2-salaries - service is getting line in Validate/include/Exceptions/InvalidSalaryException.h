#ifndef INVALIDSALARYEXCEPTION_H
#define INVALIDSALARYEXCEPTION_H
#include <string>
using namespace std;


class InvalidSalaryException
{
    public:
        InvalidSalaryException();
        string get_message();
    private:
        string _message;
};

#endif // INVALIDSALARYEXCEPTION_H
