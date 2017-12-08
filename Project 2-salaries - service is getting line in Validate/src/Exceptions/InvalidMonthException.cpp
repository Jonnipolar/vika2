#include "InvalidMonthException.h"

InvalidMonthException::InvalidMonthException(){
    _message = "Please input month as a one or two numbers, e.g. 1, 2, or 12\n"
               "Please input a valid month: ";
}



string InvalidMonthException::get_message(){
    return _message;
};
