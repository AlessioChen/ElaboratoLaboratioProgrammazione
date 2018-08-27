//
// Created by alessio on 26/08/18.
//

#include "Date.h"
#include "QDate"

Date::Date(){
    QDate c = QDate::currentDate();
    day = c.day();
    month = c.month();
    year = c.year();
    dayOf = c.dayOfWeek();
    leapYear = c.isLeapYear(year);
    checkDayOf();
    checkMonthOf();

}

void Date::checkDayOf(){
    switch ( dayOf ) {
        case 1:
            strDayOf = "lunedì";
            break;
        case 2:
            strDayOf = "martedì";
            break;
        case 3:
            strDayOf = "mercoledì";
            break;
        case 4:
            strDayOf = "giovedì";
            break;
        case 5:
            strDayOf = "venerdì";
            break;
        case 6:
            strDayOf = "sabato";
            break;
        case 7:
            strDayOf = "domenica";
            break;
    }

}

void Date::checkMonthOf(){
    switch ( month ) {
        case 1:
            monthOf = "gennaio";
            break;
        case 2:
            monthOf = "febbraio";
            break;
        case 3:
            monthOf = "marzo";
            break;
        case 4:
            monthOf = "aprile";
            break;
        case 5:
            monthOf = "maggio";
            break;
        case 6:
            monthOf = "giugno";
            break;
        case 7:
            monthOf = "lugio";
            break;
        case 8:
            monthOf = "agosto";
            break;
        case 9:
            monthOf = "settembre";
            break;
        case 10:
            monthOf = "ottobre";
            break;
        case 11:
            monthOf = "novembre";
            break;
        case 12:
            monthOf = "dicembre";
            break;
    }
}

void Date::setDate(int d, int m, int y){
    if ( y >= 0 )
        year = y;
    else
        year = QDate::currentDate().year();

    leapYear = checkLeapYear(year);

    if ( m < 0 || m > 12 )
        month = QDate::currentDate().month();
    else
        month = m;

    if ( d < 0 || d > 31 )
        day = QDate::currentDate().day();
    else
        day = d;

    if (( month == 4 || month == 6 || month == 9 || month == 11 ) && d == 31 )
        day = QDate::currentDate().day();
    if ( month == 2 && leapYear == false && d >= 29 )
        day = QDate::currentDate().day();

    checkMonthOf();
    checkDayOf();

}

bool Date::checkLeapYear(int y){
    if (( y % 4 == 0 && y % 100 && y % 400 ) || ( y % 4 == 0 && y % 100 != 0 ))
        return true;
    else
        return false;

}

QString &Date::getDateFormat(){
    return dateFormat;
}

bool Date::getLeapYear(){
    return leapYear;
}

std::string &Date::getdayof(){
    return strDayOf;
}

std::string &Date::getMonthOf(){
    return monthOf;
}

int Date::getYear(){
    return year;
}

int Date::getMonth(){
    return month;
}

int Date::getDay(){
    return day;
}

Date &Date::getDate(){
    return *this;
}

void Date::setDay(int d){
    day = d;

}

void Date::setLeapYear(bool l){
    leapYear = l;

}

void Date::setFormat(QString f){
    dateFormat = f;

}




