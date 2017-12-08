#ifndef GETTIME_H
#define GETTIME_H
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


class GetTime
{
    public:
        GetTime();
        int get_month();
        int get_year();
        string get_full_date(); ///Skilar streng hh:mm dd/mm/yyyy

    protected:

    private:
};

#endif // GETTIME_H
