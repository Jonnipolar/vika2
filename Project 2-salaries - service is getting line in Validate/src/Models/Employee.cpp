#include "Employee.h"



//using namespace std;

Employee::Employee() //mainly used for validation
{

};

Employee::Employee(string name, string ssn, string salary, string month, string year){
    stringstream convertm(month);
    int monthInt;
    convertm >> monthInt;
    stringstream converts(salary);
    int salaryInt;
    converts >> salaryInt;
    stringstream converty(year);
    int yearInt;
    converty >> yearInt;
    _name = name;
    _ssn = ssn;
    _salary = salaryInt;
    _month = monthInt;
    _year = yearInt;

};
string Employee::get_name() {
    return _name;
}
string Employee::get_ssn() {
    return _ssn;
}
int Employee::get_salary() {
    return _salary;
}
int Employee::get_month() {
    return _month;
}
int Employee::get_year() {
    return _year;
}
void Employee::set_salary(int salary) {
    _salary = salary;
}
ostream& operator << (ostream& outs, Employee& employee) {
    outs << employee._name << ";" << employee._ssn << ";" << employee._salary << ";" << employee._month << ";" << employee._year << endl;
    return outs;
}


