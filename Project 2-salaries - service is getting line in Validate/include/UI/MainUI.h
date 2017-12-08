#ifndef MAINUI_H
#define MAINUI_H
#include "SubUI.h"
#include <iostream>
#include "InvalidNumberException.h"
#include "EmployeeService.h"
#include <vector>
using namespace std;


class MainUI
{
    public:
        MainUI();
        void run_UI() throw (InvalidNumberException);
    protected:

    private:
        EmployeeService emp;
};

#endif // MAINUI_H
