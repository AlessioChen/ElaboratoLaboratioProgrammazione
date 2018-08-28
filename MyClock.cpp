//
// Created by alessio on 28/08/18.
//

#include "MyClock.h"

MyClock::MyClock(Counter *counter, QWidget *parent){
    date.setGeometry(210, 20, 260, 40);
    time.setGeometry(475, 0, 120, 80);

    date.setParent(parent);
    time.setParent(parent);
    date.setAlignment(Qt::AlignCenter);
    time.setAlignment(Qt::AlignCenter);

    QFont dateTimeFont;
    dateTimeFont = time.font();
    dateTimeFont.setPointSize(14);

    dateTimeFont = date.font();
    dateTimeFont.setPointSize(14);

    selectDateFormat.setParent(parent);
    selectDateFormat.setGeometry(20, 10, 160, 30);

    selectDateFormat.addItem("day-month-year");
    selectDateFormat.addItem("dd-mm-yyyy");
    selectDateFormat.addItem("yyyy-mm-dd");

    selectTimeFormat.setParent(parent);
    selectTimeFormat.setGeometry(20, 40, 160, 30);

    selectTimeFormat.addItem("hh:mm:ss");
    selectTimeFormat.addItem("hh::mm");

    myCounter = counter;
    attach();

}

void MyClock::update(){
    time.setText(QString::fromStdString(myCounter->getStringTime()));
    date.setText(QString::fromStdString(myCounter->getStringDate()));

    QString form;
    switch ( selectTimeFormat.currentIndex()) {
        case 0:
            form = "hh::mm::ss";
            break;
        case 1:
            form = "hh::mm";
            break;
        default:
            form = "hh::mm::ss";
    }
    myCounter->setTimeFormat(form);

    switch ( selectDateFormat.currentIndex()) {
        case 0:
            form = "day-month-year";
            break;
        case 1:
            form = "dd-mm-yyyy";
            break;
        case 2:
            form = "mm-dd-yyyy";
            break;
        default:
            form = "day-month-year";
            break;

    }
    myCounter->setDateFormat(form);

}

void MyClock::attach(){
    myCounter->subscribe(this);

}

void MyClock::detach(){
    myCounter->unsubscribe(this);
}

void MyClock::changeFormat(){
    QString form = selectTimeFormat.currentText();
    myCounter->setTimeFormat(form);

}


