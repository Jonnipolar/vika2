#ifndef SALARY_H
#define SALARY_H
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


class Salary
{
    public:
        Salary();
        Salary(string salary, string month, string year);
        friend ostream & operator << (ostream& outs, const Salary salary);
        friend istream & operator >> (ostream& ins, Salary& salary);

        int get_month();
        string get_year();
        string get_salary();

    private:
        string _year;
        int _month;
        string _salary;

};

#endif // SALARY_H
