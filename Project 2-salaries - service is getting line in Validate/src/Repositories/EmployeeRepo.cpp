#include "EmployeeRepo.h"

EmployeeRepo::EmployeeRepo()
{

}

void EmployeeRepo::Write_to_file(vector<Employee> employee){

    ofstream fout;

    fout.open("EmployeeDatabase.txt");
        if(fout.is_open()) {
            for(unsigned int i = 0; i < employee.size();i++) {
                fout << employee[i];
            }
        } else {
            cout << "File error please contact a hacker";
        }
        fout.close();
}
vector <Employee> EmployeeRepo::get_employee() {
    vector <Employee> employees;
    string str;
    ifstream fin("EmployeeDatabase.txt");
    if(fin.is_open()) {
        while (getline(fin,str)) {
            int index = str.find(';');
            int index_second = str.find(';', index + 1);
            int index_third = str.find(';', index_second + 1);
            int index_fourth = str.find(';', index_third + 1);
            int index_fifth = str. find(';', index_fourth + 1);
            string name = str.substr(0, index);
            string ssn = str.substr(index + 1, (index_second - 1) - index);
            string salary = str.substr(index_second + 1, (index_third - 1) - index_second);
            string month = str.substr(index_third + 1, (index_fourth - 1) - index_third);
            string year = str.substr(index_fourth + 1, (index_fifth - 1) - index_fourth);
            Employee employee(name, ssn, salary, month, year);
            employees.push_back(employee);
        }
        fin.close();
    }
    return employees;
}
