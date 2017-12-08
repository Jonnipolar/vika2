#include "InvalidNumberException.h"

InvalidNumberException::InvalidNumberException(){
    _message = "Not a valid number, please select an option from the list\n"
               "Please enter a valid option: ";
}

string InvalidNumberException::get_message(){
    return _message;
};
