//
// Created by alessio on 26/08/18.
//

#ifndef TIMERAPPLICATION_DATE_H
#define TIMERAPPLICATION_DATE_H

#include <QtCore/QString>

class Date{

public:
    Date();

    void setDate(int d, int m, int y);
    void setDay(int d);
    void setLeapYear(bool leap);
    void setFormat(std::string f);

    Date &getDate();
    int getDay();
    int getMonth();
    int getYear();
    std::string &getDateString();
    std::string &getMonthOf();
    std::string &getdayof();
    bool getLeapYear();

    std::string &getDateFormat();
    bool checkLeapYear(int y);
    void checkMonthOf();
    void checkDayOf();

private:
    int day;
    int month;
    int year;
    int dayOf;
    std::string dateFormat;
    bool leapYear;
    std::string monthOf;
    std::string strDayOf;
    std::string strDate;

};

#endif //TIMERAPPLICATION_DATE_H
