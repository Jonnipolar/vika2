#include "Salary.h"

Salary::Salary()
{/*
    _year = year;
    _month = month;
    _salary = salary;
    */
};

Salary::Salary(string salary, string month, string year){
    stringstream convert(month);
  int monthInt;
convert >> monthInt;

//cout << "converter para";
    _year = year;
    _month = monthInt;
    _salary = salary;
};

int Salary::get_month(){
//    stringstream convert(month);
//    int monthInt;
//    convert >> monthInd
    return _month;
};

string Salary::get_year(){
    return _year;
        };

string Salary::get_salary(){
    return _salary;
};

ostream & operator << (ostream& outs, Salary salary){
   outs << salary._salary << " " <<
   salary._month << " " << salary._year;
    return outs;
};

istream & operator >> (ostream& ins, Salary& salary){

};

