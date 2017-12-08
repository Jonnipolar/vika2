#include "InvalidYearException.h"

InvalidYearException::InvalidYearException(){
    _message = "Please input year as a four letter number, e.g. 1997\n"
               "Note that you cannot look into the future, nor further back than 1900.\n"
               "Please input a valid year: ";
}


string InvalidYearException::get_message(){
    return _message;
};
