#include "EmployeeService.h"
#include "EmployeeRepo.h"
#include <string>
#include <sstream>
#include <GetTime.h>


using namespace std;

EmployeeService::EmployeeService() //mainly used for validation
{
    ///kannski tharf ad laga parameters her, ef thad refinar ekki employee rett (og tha nota set_shit)

};

vector <Employee> EmployeeService::create_employee(string name, string ssn, string salary, string month, string year)
{
    int check = 0;
    stringstream converty(year);
    int yearInt;
    converty >> yearInt;
    stringstream convertm(month);
    int monthInt;
    convertm >> monthInt;
    Employee employees(name, ssn, salary, month, year);
    vector <Employee> employee = repo.get_employee();
    for(unsigned int i = 0; i < employee.size();i++) {
        if(employee[i].get_ssn() == ssn) {
            if(employee[i].get_year() == yearInt) {
                if(employee[i].get_month() == monthInt) {
                    employee[i] = employees;
                    check = 1;
                }
            }
        }
    }
    if(check == 0){
        employee.push_back(employees);
    }
    repo.Write_to_file(employee);

    return employee;
};



char EmployeeService::Validate_UI_Menupick(char items_in_menu) throw (InvalidNumberException)
{
    char selection;
    bool valid = false;
    do {
        cin >> selection;
        try {
            if(selection>'0' && selection<=items_in_menu) { //hversu morg items
                valid = true;
            } else {
                throw InvalidNumberException();
            };
        } catch(InvalidNumberException e) {
            cout << e.get_message();
        }
    } while(valid == false);

    return selection;
}

string EmployeeService::Validate_UI_name(string& name, bool& is_valid) throw (InvalidNameException)
{
    unsigned int min_name_length = 3;

    if(name[0] == '\\') {
    } else {
        try {
            for(unsigned int i = 0; i < name.length(); i++) {
                if((isalpha(name[i]) || isspace(name[i])) && name.length()>=min_name_length) {
                    is_valid = true;
                } else {
                    throw InvalidNameException();
                };
            }
        } catch(InvalidNameException e) {
            is_valid = false;
            stringstream errorstream(e.get_message());
            string error;
            getline(errorstream, name, '!'); // vil thetta taki alla skrana therefore nonexistant delimiter
        }
    }
    return name;
}

string EmployeeService::Validate_UI_SSN(string& ssn, bool& is_valid) throw (InvalidSSNException)
{
    if(ssn[0] == '\\') { //breakout loop to go back to menu
        is_valid = true;
    } else {
        try {
            for(unsigned int i = 0; i < sizeof(ssn); i++) {
                if(isdigit(ssn[i]) && ssn.length() == 10) {
                    is_valid = true; // endar a return
                } else {
                    throw InvalidSSNException();
                };
            }
        } catch(InvalidSSNException e) {
            is_valid = false;
            stringstream errorstream(e.get_message());
            string error;
            getline(errorstream, ssn, '!'); // vil thetta taki alla skrana therefore nonexistant delimiter
        }
    }
    return ssn;
}

string EmployeeService::Validate_UI_Salary(string& salary, bool& is_valid) throw (InvalidSalaryException)
{
    if(salary[0] == '\\') { //breakout loop to go back to menu
        is_valid = true;
    } else {
        try {
            for(unsigned int i = 0; i < salary.length(); i++) {
                if((isdigit(salary[i]))) {
                    is_valid = true;
                } else {

                    throw InvalidSalaryException();
                };
            }
        } catch(InvalidSalaryException e) {
            is_valid = false;
            stringstream errorstream(e.get_message());
            string error;
            getline(errorstream, salary, '!'); // vil thetta taki alla skrana therefore nonexistant delimiter
        }
    }
    return salary;
}

string EmployeeService::Validate_UI_Year(string& year, bool& is_valid, bool& chose_current_year) throw (InvalidYearException) // allt otharflega flokid held eg
{

    GetTime getTime;


    stringstream verify_yearStr(year);
    int verify_yearInt;

    if(year[0] == '\\') { //breakout loop to go back to menu
        is_valid = true;
    } else {
        verify_yearStr >> verify_yearInt;
        try {

            if(verify_yearInt == getTime.get_year()) { //gettime.) { ///gera svo thu getir ekki gert t.d. manud fram i timann (mida vid ar og manud tha(
                chose_current_year = true;
                is_valid = true; // endar a return;

            } else if(verify_yearInt >= 1900  &&  verify_yearInt <= getTime.get_year()) {

                is_valid = true;
            } else {

                throw InvalidYearException();
            };

        } catch(InvalidYearException e) {
            is_valid = false;
            stringstream errorstream(e.get_message());
            string error;
            getline(errorstream, year, '!'); // vil thetta taki alla skrana therefore nonexistant delimiter
        }
    }

    return year;
}

string EmployeeService::Validate_UI_Month(string& month, bool& is_valid, bool chose_current_year) throw (InvalidMonthException)
{
    GetTime getTime;

        stringstream verify_monthStr(month);
        int verify_monthInt;

        if(month[0] == '\\') { //breakout loop to go back to menu
            is_valid = true;
        } else {
            verify_monthStr >> verify_monthInt;
            try {
                if(verify_monthInt >= 1  &&  verify_monthInt <= 12 && chose_current_year == false ) { ///gera svo thu getir ekki gert t.d. manud fram i timann (mida vid ar og manud tha(

                    is_valid = true; // endar a return
                } else if((verify_monthInt >= 1 ||  verify_monthInt <= getTime.get_month()) && chose_current_year == true) {

                    is_valid = true;
                } else {

                    throw InvalidMonthException();
                };

            } catch(InvalidMonthException e) {
            is_valid = false;
            stringstream errorstream(e.get_message());
            string error;
            getline(errorstream, month, '!'); // vil thetta taki alla skrana therefore nonexistant delimiter
            }
        }

    return month;
}
vector <Employee> EmployeeService::get_employee() {
    vector <Employee> employees = repo.get_employee();
    return employees;
}
vector <Employee> EmployeeService::get_by_ssn(string ssn) {
    vector <Employee> employees = repo.get_employee();
    vector <Employee> ssn_employee;
    for(unsigned int i = 0; i < employees.size(); i++) {
        if(ssn == employees[i].get_ssn()) {
            ssn_employee.push_back(employees[i]);
        }
    }
    return ssn_employee;
}
vector <Employee> EmployeeService::get_by_ssn_year(string ssn, string year) {
    stringstream converty(year);
    int yearInt;
    converty >> yearInt;
    vector <Employee> employees = repo.get_employee();
    vector <Employee> ssn_year_employee;
    for(unsigned int i = 0; i < employees.size(); i++) {
        if(ssn == employees[i].get_ssn()) {
            if(yearInt == employees[i].get_year()){
                ssn_year_employee.push_back(employees[i]);
            }
        }
    }
    return ssn_year_employee;
}
vector <Employee> EmployeeService::highest_year_salary(string year){
    stringstream converty(year);
    int yearInt;
    converty >> yearInt;
    int total = 0;
    vector <Employee> employees = repo.get_employee();
    vector <Employee> year_employee;
    vector <Employee> highest_year_employee;
    for(unsigned int i = 0; i < employees.size(); i++) {
        if(yearInt == employees[i].get_year()){
            year_employee.push_back(employees[i]);
        }
    }
    for(unsigned int i = 0; i < year_employee.size();i++) {
        for(unsigned int j = i+1; j < year_employee.size();j++) {
            if(year_employee[i].get_ssn() == year_employee[j].get_ssn()) {
                int sum = (year_employee[j].get_salary() + year_employee[i].get_salary());
                year_employee[i].set_salary(sum);
            }
        }
        if(year_employee[i].get_salary() > total) {
            if(total != 0) {
                highest_year_employee.pop_back();
            }
            total = year_employee[i].get_salary();
            highest_year_employee.push_back(year_employee[i]);
        }
    }

    return highest_year_employee;
}
