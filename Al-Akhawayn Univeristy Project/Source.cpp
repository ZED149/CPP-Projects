

#include <iostream>
#include "myread.h"
#include <string>
#include "my_time.h"
using namespace std;



MyTime& elapsed_time(MyTime start_time, MyTime end_time)
{
    // This function works on 24 hour format time 
    // e.g 13:00:32 or 22::30:24


    // creating the return object
    MyTime T;

    // first i need to check which time hour is greater
    if (start_time.hours > end_time.hours)
    {
        // if start time is greater
        T.hours = (start_time.hours - end_time.hours) + 24;
    }
    else
    {
        T.hours = end_time.hours - start_time.hours;
    }

    // now checking which minutes are greater in magnitude
    if (start_time.minutes > end_time.minutes)
    {
        // if starting time minute are greater
        T.minutes = (start_time.minutes - end_time.minutes);
    }
    else
    {
        T.minutes = end_time.minutes - start_time.minutes;
    }

    // now checking which seconds are greater
    if (start_time.seconds > end_time.seconds)
    {
        // if starting time secondsare greater
        T.seconds = (start_time.seconds - end_time.seconds);

    }
    else
    {
        T.seconds = end_time.seconds - start_time.seconds;
    }


    // Returning the object
    return T;
}

int main()
{
    MyTime f, l;
    f.hours = 8;
    f.minutes = 23;
    f.seconds = 12;

    l.hours = 14;
    l.minutes = 30;
    l.seconds = 23;

    MyTime T = elapsed_time(f, l);
    cout << "Hours are: " << T.hours << endl;
    cout << "Minutes are: " << T.minutes << endl;
    cout << "Seconds are: " << T.seconds << endl;
}