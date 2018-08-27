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
    void setFormat(QString f);

    Date &getDate();
    int getDay();
    int getMonth();
    int getYear();
    std::string &getMonthOf();
    std::string &getdayof();
    bool getLeapYear();

    QString &getDateFormat();
    bool checkLeapYear(int y);
    void checkMonthOf();
    void checkDayOf();

private:
    int day;
    int month;
    int year;
    int dayOf;
    QString dateFormat;
    bool leapYear;
    std::string monthOf;
    std::string strDayOf;

};

#endif //TIMERAPPLICATION_DATE_H
