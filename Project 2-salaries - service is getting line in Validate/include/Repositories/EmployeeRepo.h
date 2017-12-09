#ifndef EMPLOYEEREPO_H
#define EMPLOYEEREPO_H
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <Employee.h>

class EmployeeRepo
{
    public:
        EmployeeRepo();
        void Write_to_file(vector<Employee> employee);
        vector <Employee> get_employee();
    private:
};

#endif // EMPLOYEEREPO_H
