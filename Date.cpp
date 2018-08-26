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
    //TODO

}



