#include "GetTime.h"
#include <ctime>


GetTime::GetTime()
{

}

int GetTime::get_month(){
    time_t timestamp = time(0);
    char time_buffer[80];

    strftime(time_buffer, sizeof(time_buffer), "%m", localtime(&timestamp));
    stringstream stringtime(time_buffer);

    int time;
    stringtime >> time;

    return time;
};
int GetTime::get_year(){
    time_t timestamp = time(0);
    char time_buffer[80];

    strftime(time_buffer, sizeof(time_buffer), "%Y", localtime(&timestamp));
    stringstream stringtime(time_buffer);


    int year = 0;
    stringtime >> year;

    return year;
};

string GetTime::get_full_date(){
    time_t timestamp = time(0);
    char time_buffer[80];

    strftime(time_buffer, sizeof(time_buffer), "%H:%M %d/%m/%Y", localtime(&timestamp));
    string time(time_buffer);

    return time;
}
