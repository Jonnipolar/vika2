#include "InvalidSSNException.h"

InvalidSSNException::InvalidSSNException(){
    _message = "SSN must contain 10 numbers to be valid.\nPlease enter a valid SSN: ";
}

string InvalidSSNException::get_message(){
    return _message;
};
