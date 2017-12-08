#ifndef EMPLOYEESERVICE_H
#define EMPLOYEESERVICE_H
#include <string>
#include <iostream>
#include "InvalidNameException.h"
#include "InvalidSSNException.h"
#include "InvalidYearException.h"
#include "InvalidNumberException.h"
#include "InvalidMonthException.h"
#include "InvalidSalaryException.h"
#include "Employee.h"
#include "EmployeeRepo.h"



class EmployeeService
{
    public:
        EmployeeService();



        vector <Employee> create_employee(string name, string ssn, string salary, string month, string year); //skapar employee??
        vector <Employee> get_employee();
        vector <Employee> get_by_ssn(string ssn);
        vector <Employee> get_by_ssn_year(string ssn, string year);
        vector <Employee> highest_year_salary(string year);

        string Validate_UI_name(string& name, bool &is_valid ) throw (InvalidNameException);
        string Validate_UI_SSN(string& ssn, bool &is_valid ) throw (InvalidSSNException);
        char Validate_UI_Menupick(char items_in_menu) throw (InvalidNumberException);
        string Validate_UI_Year(string& year, bool& is_valid, bool& chose_current_year) throw (InvalidYearException);
        string Validate_UI_Month(string& month, bool& is_valid, bool chose_current_year) throw (InvalidMonthException);
        string Validate_UI_Salary(string& salary, bool& is_valid) throw (InvalidSalaryException);


    private:
        Employee employee;
        EmployeeRepo repo;

};


#endif // EMPLOYEESERVICE_H
