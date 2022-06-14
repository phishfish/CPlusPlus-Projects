#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
using namespace std;

bool Date::setDay(int d, int m)
{
    if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 0 && d < 32))
    {
        day = d;
        return true;
    }
    else if (m == 2 && (d > 0 && d < 29))
    {
        day = d;
        return true;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 0 && d < 31))
    {
        day = d;
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::setMonth(int m)
{
    if (m > 0 && m < 13)
    {
        month = m;
        return true;
    }
    else
    {
        return false;
    }
}

bool Date::setYear(int y)
{
    if ((y == 2021) || (y == 2022))
    {
        year = y;
        return true;
    }
    else 
    {
        return false;
    }
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

string Date::showDate()
{
    string date;

    if (month < 10)
    {
        date += '0' + to_string(month);
    }
    else 
    {
        date = to_string(month);
    }
    
    date += '/';
    if (day < 10)
    {
        date += '0' + to_string(day);
    }
    else 
    {
        date += to_string(day);
    }

    date +=  '/' + to_string(year); 

    return date;
}