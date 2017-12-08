#ifndef SUBUI_H
#define SUBUI_H
#include "InvalidNumberException.h"
#include "InvalidNameException.h"
#include "InvalidSSNException.h"
#include <conio.h>
#include <vector>
#include "EmployeeService.h"
#include "Employee.h"

class SubUI
{
    public:
        SubUI();
        void view_records_UI() throw (InvalidNumberException); ///View 1
        void add_records_UI(); ///Add 1

    private: //set restina af UI follunum i private thar sem hin 2 eru eina sem MM gaeti thurft ad kalla i.
        void v_lookup_SSN_UI();
        void v_lookup_year_and_SSN_UI();
        void v_lookup_highest_UI();
        EmployeeService emps;
};

#endif // SUBUI_H
