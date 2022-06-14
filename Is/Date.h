#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
    private:
    int day {1},
    month {1},
    year {2021};

    public:
    Date() = default;
    Date(int d, int m, int y) : day{1}, month{1}, year{2021}  
    {
        
        if (!setDay(d, m) || !setMonth(m) || !setYear(y))
        {
            day = 1;
            month = 1;
            year = 2021;
        }
    }
    bool setDay (int d, int m);
    bool setMonth (int m);
    bool setYear (int y);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    string showDate();
};

#endif