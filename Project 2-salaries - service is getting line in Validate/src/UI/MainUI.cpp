#include "MainUI.h"
#include "SubUI.h"
#include <cstdlib>
#include <stdlib.h>
#include "InvalidNumberException.h"
#include "GetTime.h"
#include "EmployeeService.h"
#include "Employee.h"
MainUI::MainUI()
{

}

void MainUI::run_UI() throw (InvalidNumberException)
{
    char selection; // verd ad bua thetta til her svo while-lykkja virki
    do { //Negli thessu i do-while svo ad madur thurfi ad fara manually ur program, annars MainMenu
        system("CLS");
        cout << "===================================================================\n";
        cout << "MoneyManager3500: Main menu\n";
        cout << "===================================================================\n";
        cout << "Choose 1 to view records. \n";
        cout << "Choose 2 to add/modify staff member record.\n";
        cout << "Choose 3 to exit program.\n";
        cout << "===================================================================\n";
        cout << "Selection: ";

        SubUI subUI;
        EmployeeService employeeService;

        char items_in_menu = '3'; //
        selection = employeeService.Validate_UI_Menupick(items_in_menu);

        switch(selection) {
        case '1' : // View_records
            subUI.view_records_UI();
            break;
        case '2' : //Add_records
            subUI.add_records_UI();
            break;
        case '3' : //Exit
            exit(1);
        }

    } while(selection != '3');
}

