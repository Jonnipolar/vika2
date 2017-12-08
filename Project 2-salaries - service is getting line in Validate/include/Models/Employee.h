#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <sstream>
#include <iostream>



using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string name, string ssn, string salary, string month, string year);
        string get_name();
        string get_ssn();
        int get_salary();
        int get_month();
        int get_year();
        void set_salary(int salary);


        friend ostream& operator << (ostream& outs, Employee& employee);


    private:
        string _name;
        string _ssn;
        int _salary;
        int _month;
        int _year;
};
#endif // EMPLOYEE_H
