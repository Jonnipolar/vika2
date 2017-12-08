#include "MainUI.h"
#include "SubUI.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include "InvalidNumberException.h"
#include <EmployeeService.h>
#include <GetTime.h>
using namespace std;

GetTime getTime; ///kannski faera thar sem tekur minna minni

SubUI::SubUI()
{
}

void SubUI::view_records_UI() throw (InvalidNumberException)
{
    system("CLS");
    cout << "===================================================================\n";
    cout << "MoneyManager3500: View salary records.\n";
    cout << "===================================================================\n";
    cout << "Choose 1 to look up records of employee by SSN (kennitala). \n";
    cout << "Choose 2 to look up records of employee by SSN and year.\n";
    cout << "Choose 3 to view highest paid employee for a given year.\n";
    cout << "Choose 4 to go back to 'main menu'\n";
    cout << "===================================================================\n";
    cout << "Selection: ";

    EmployeeService employeeService;
    char items_in_menu = '4';
    char selection = employeeService.Validate_UI_Menupick(items_in_menu); //nenni ekki ad validate-a selsection serstaklega

    switch(selection) {
    case '1' :
        v_lookup_SSN_UI();
        break;
    case '2' :
        v_lookup_year_and_SSN_UI();
        break;
    case '3' :
        v_lookup_highest_UI();
        break; /// setja inn High pay funtion
    case '4' :
        break;
    default  :
        throw InvalidNumberException();
    }
}

void SubUI::add_records_UI()
{
    system("CLS");
    cout << "===================================================================\n";
    cout << "MoneyManager3500: Add employee record to database.\n";
    cout << "===================================================================\n";
    cout << "Typing \\ at beginning of input will cancel operation and return to main menu.\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "Enter employee information: \n";

    EmployeeService employeeService;
    bool is_valid = false;

    string name;
    cout << "Name: ";
    do {
        getline(cin, name);
        employeeService.Validate_UI_name(name, is_valid);
        if(name[0] == '\\') {
            return;

        } else if(is_valid == false) {
            cout << name;
        };
    } while(is_valid == false);

    ///ssn
    is_valid = false;
    string ssn;
    cout << "Social security number (kennitala): ";
    do {
        cin >> ssn;
        employeeService.Validate_UI_SSN(ssn, is_valid);
        if(ssn[0] == '\\') {
            return;
        } else if(is_valid == false) {
            cout << ssn;
        }
        ;
    } while(is_valid == 0);

    ///Salary
    is_valid = false;
    cout << "Salary: ";
    string salary;
    do{
    cin >> salary;
    employeeService.Validate_UI_Salary(salary, is_valid);


    if(salary[0] == '\\') {
        return;
    } else if(is_valid == false){
        cout << salary;
    };}while (is_valid == false);

    ///year
    bool chose_current_year = false;
    is_valid = false;
    string year;
    cout << "Year: ";

    do{
    cin >> year;
    employeeService.Validate_UI_Year(year, is_valid, chose_current_year);
    if(year[0] == '\\') {
        return;
    } else if(is_valid == false){
        cout << year;
    };}while(is_valid == false);

    ///month
    is_valid = false;

    string month;
    cout << "Month: ";
    do {
        cin >> month;
        employeeService.Validate_UI_Month(month, is_valid, chose_current_year);
        if(ssn[0] == '\\') {
            return;
        } else if(is_valid == false) {
            cout << month;

        };
    } while(is_valid == false);

    ///endar ad set employee_set_employee og svo print to file function

    emps.create_employee(name, ssn, salary, month, year);
    cout << "Employee created. Push any key to continue back to main menu.";
    getch(); // system pause
}


void SubUI::v_lookup_SSN_UI()
{
    system("CLS");
    cout << "===================================================================\n";
    cout << "MoneyManager3500: Look up all record for SSN (kennitala).\n";
    cout << "===================================================================\n";
    cout << "Type employees SSN or kennitala: ";
    EmployeeService employeeService;
    ///ssn
    bool is_valid = false;
    string ssn;
    do {
        cin >> ssn;
        employeeService.Validate_UI_SSN(ssn, is_valid);
        if(ssn[0] == '\\') {
            return;
        } else if(is_valid == true) {
            vector <Employee> employee = emps.get_by_ssn(ssn);
            for(unsigned int i = 0; i < employee.size(); i++) {
                cout << "Name: " << employee[i].get_name() << " SSN: " <<employee[i].get_ssn() << " Salary: " << employee[i].get_salary()
                << " Month: " << employee[i].get_month()
                << " Year: " << employee[i].get_year() << endl;
            }
            getch();
        }
        ;
    } while(is_valid == false);

};
void SubUI::v_lookup_year_and_SSN_UI()
{
    system("CLS");
    cout << "===================================================================\n";
    cout << "MoneyManager3500: Look up record by SSN (kennitala) and year.\n";
    cout << "==================================================================\n";
    EmployeeService employeeService;
    ///Year
    bool chose_current_year = false;
    bool is_valid = false;
    string year;
    cout << "Year: ";
    int total = 0;

    do{
    cin >> year;
    employeeService.Validate_UI_Year(year, is_valid, chose_current_year);
    if(year[0] == '\\') {
        return;
            return;
        } else if(is_valid == true) {
            cout << "Type employees SSN or kennitala: ";

            ///ssn
            is_valid = false;
            string ssn;
            do {
                cin >> ssn;
                employeeService.Validate_UI_SSN(ssn, is_valid);
                if(ssn[0] == '\\') {
                    return;
                } else if(is_valid == true) {
                    int k;
                    vector <Employee> employee = emps.get_by_ssn_year(ssn, year);
                    for(unsigned int i = 0; i < employee.size(); i++) {
                        total += employee[i].get_salary();
                        k = i;
                    }
                    cout << employee[k].get_name() << "'s total salary for year " << year << " is: " << total;
                    getch();
                }
            } while(is_valid == false);
        }
    } while(is_valid == false);

};
void SubUI::v_lookup_highest_UI()
{
    system("CLS");
    cout << "===================================================================\n";
    cout << "MoneyManager3500: Look up record by SSN (kennitala) and year.\n";
    cout << "==================================================================\n";
    EmployeeService employeeService;
    ///Year
    bool chose_current_year = false;
    bool is_valid = false;
    string year;
    cout << "Year: ";

    do{
    cin >> year;
    employeeService.Validate_UI_Year(year, is_valid, chose_current_year);
    if(year[0] == '\\') {
        return;
            return;
        } else if(is_valid == true) {
            vector <Employee> employee = emps.highest_year_salary(year);
            cout << employee[0].get_name() << " has the highest income for the year " << year << " with the total of " << employee[0].get_salary() << " kr.";
            getch();
        }
    } while(is_valid == false);

};
