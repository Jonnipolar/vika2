#include "InvalidNameException.h"

InvalidNameException::InvalidNameException(){
    _message = "Names cannot include numbers, punctuations, or funky foreign letters.\n"
    "Names must also be at least three letters in length.\n"
    // "Please capitalize the letters /// eda lata program laga???
    "Please enter a valid name: ";
}

string InvalidNameException::get_message(){
    return _message;

};
