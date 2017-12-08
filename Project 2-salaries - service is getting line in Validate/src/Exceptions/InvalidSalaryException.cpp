#include "InvalidSalaryException.h"

InvalidSalaryException::InvalidSalaryException()
{
        _message = "Salary should be entered as an integer.\n"
                    "Please type a valid integer (numbers only): ";
}

string InvalidSalaryException::get_message(){
    return _message;
}
