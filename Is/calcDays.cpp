#include <iostream>
#include "Date.h"
#include "calcDays.h"

int calcDays(const Date& day1, const Date& day2) 
{
    int daysDiff1;
    int daysDiff2;

    if (day1.getMonth() == 1)
    {
        daysDiff1 = day1.getDay(); 
    }
    else if (day1.getMonth() == 2)
    {
        daysDiff1 = 31 + day1.getDay();
    }
    else if (day1.getMonth() == 3)
    {
        daysDiff1 = 59 + day1.getDay();
    }
    else if (day1.getMonth() == 4)
    {
        daysDiff1 = 90 + day1.getDay();
    }
    else if (day1.getMonth() == 5)
    {
        daysDiff1 = 120 + day1.getDay();
    }
    else if (day1.getMonth() == 6)
    {
        daysDiff1 = 151 + day1.getDay();
    }
    else if (day1.getMonth() == 7) 
    {
        daysDiff1 = 181 + day1.getDay();
    }
    else if (day1.getMonth() == 8)
    {
        daysDiff1 = 212 + day1.getDay();
    }
    else if (day1.getMonth() == 9)
    {
        daysDiff1 = 243 + day1.getDay();
    }
    else if (day1.getMonth() == 10)
    {
        daysDiff1 = 273 + day1.getDay();
    }
    else if (day1.getMonth() == 11)
    {
        daysDiff1 = 304 + day1.getDay();
    }
    else if (day1.getMonth() == 12)
    {
        daysDiff1 = 334 + day1.getDay();
    }

    if (day2.getMonth() == 1)
    {
        daysDiff2 = day2.getDay(); 
    }
    else if (day2.getMonth() == 2)
    {
        daysDiff2 = 31 + day2.getDay();
    }
    else if (day2.getMonth() == 3)
    {
        daysDiff2 = 59 + day2.getDay();
    }
    else if (day2.getMonth() == 4)
    {
        daysDiff2 = 90 + day2.getDay();
    }
    else if (day2.getMonth() == 5)
    {
        daysDiff2 = 120 + day2.getDay();
    }
    else if (day2.getMonth() == 6)
    {
        daysDiff2 = 151 + day2.getDay();
    }
    else if (day2.getMonth() == 7) 
    {
        daysDiff2 = 181 + day2.getDay();
    }
    else if (day2.getMonth() == 8)
    {
        daysDiff2 = 212 + day2.getDay();
    }
    else if (day2.getMonth() == 9)
    {
        daysDiff2 = 243 + day2.getDay();
    }
    else if (day2.getMonth() == 10)
    {
        daysDiff2 = 273 + day2.getDay();
    }
    else if (day2.getMonth() == 11)
    {
        daysDiff2 = 304 + day2.getDay();
    }
    else if (day2.getMonth() == 12)
    {
        daysDiff2 = 334 + day2.getDay();
    }

    return daysDiff1 - daysDiff2;
}
