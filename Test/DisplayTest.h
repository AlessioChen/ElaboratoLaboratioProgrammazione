//
// Created by alessio on 01/09/18.
//

#ifndef TIMERAPPLICATION_TESTDISPLAY_H
#define TIMERAPPLICATION_TESTDISPLAY_H

#include <QtCore/QObject>

class DisplayTest: public QObject{
Q_OBJECT

private slots:
    void generateDisplay();

};

#endif //TIMERAPPLICATION_TESTDISPLAY_H
