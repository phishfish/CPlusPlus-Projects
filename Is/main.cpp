#include <iostream>
#include <string>
#include "Date.h"
#include "calcDays.h"
using namespace std;

int main()
{
    string testResult,
    exposedResult,
    vacStatus;
    int dayNum,
    monthNum,
    yearNum;
    int dayNum2,
    monthNum2,
    yearNum2;
    Date date1;
    Date date2;

    cout << "What was your test result (positive or negative)? ";
    cin >> testResult;

    if (testResult == "positive")
    {
        cout << "On what month were you exposed (enter a number)? ";
        cin >> monthNum;

        cout << "On what day were you exposed (enter a number)? ";
        cin >> dayNum;

        cout << "In what year were you exposed (enter as 20XX)? ";
        cin >> yearNum;
        date1 = Date(dayNum, monthNum, yearNum);
        
        

        cout << "Test Result: " << testResult << endl;
        cout << "Date tested Positive: " << date1.showDate() << endl;
        cout << "Length of Isolation: 5 days\n";
    }
    else 
    {
        cout << "Were you exposed to someone who tested positive (Yes or No)? ";
        cin >> exposedResult;

        if (exposedResult == "No")
        {
            cout << "Test Result: " << testResult << endl;
            cout << "Exposed to Positive Case: " << exposedResult << endl;
            cout << "Length of Isolation: 0 days\n";
        }
        else if (exposedResult == "Yes")
        {
            cout << "On what month were you exposed (enter a number)? ";
            cin >> monthNum;
            date1.setMonth(monthNum);

            cout << "On what day were you exposed (enter a number)? ";
            cin >> dayNum;
            date1.setDay(dayNum, date1.getMonth());

            cout << "In what year were you exposed (enter as 20XX)? ";
            cin >> yearNum;
            date1.setYear(yearNum);

            cout << "Have you recieved the second dose of the COVID-19 vaccine (enter Yes or No)? ";
            cin >> vacStatus;

            if (vacStatus == "No")
            {
                cout << "Test Result: " << testResult << endl;
                cout << "Date tested Positive: " << date1.showDate() << endl;
                cout << "Second Vaccine Dose Recieved: " << vacStatus << endl;
                cout << "Vaccination status at time of exposure: not fully vaccinated\n";
                cout << "Length of isolation: 10 days\n";
            }
            else
            {
                cout << "In what month did you receive the vaccine (enter a number)? ";
                cin >> monthNum2;
                date2.setMonth(monthNum2);

                cout << "In what day did you recieve the vaccine (enter a number)? ";
                cin >> dayNum2;
                date2.setDay(dayNum2, date2.getMonth());

                cout << "In what year did you receive the vaccine (enter as 20XX)? ";
                cin >> yearNum2;
                date2.setYear(yearNum2);

                date2 = Date(dayNum2, monthNum2, yearNum2);
                if (calcDays(date1, date2) >= 14)
                {
                    cout << "Test Result: " << testResult << endl;
                    cout << "Date tested Positive: " << date1.showDate() << endl;
                    cout << "Second Vaccine Dose Recieved: " << vacStatus << endl;
                    cout << "Date second vaccination dose received: " << date2.showDate() << endl;
                    cout << "Vaccination status at time of exposure: fully vaccinated\n";
                    cout << "Length of isolation: 5 days\n";
                }
                else
                {
                    cout << "Test Result: " << testResult << endl;
                    cout << "Date tested Positive: " << date1.showDate() << endl;
                    cout << "Second Vaccine Dose Recieved: " << vacStatus << endl;
                    cout << "Date second vaccination dose received: " << date2.showDate() << endl;
                    cout << "Vaccination status at time of exposure: not fully vaccinated\n";
                    cout << "Length of isolation: 10 days\n";
                }
            }
        }
    }

    return 0;
}