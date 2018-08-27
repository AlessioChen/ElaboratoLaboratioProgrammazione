//
// Created by alessio on 27/08/18.
//

#ifndef TIMERAPPLICATION_SUBJECT_H
#define TIMERAPPLICATION_SUBJECT_H

#include "Observer.h"

class Subject{
public:
    virtual void subscribe(Observer *o) = 0;
    virtual void unsubscribe(Observer *o) = 0;
    virtual void notify() = 0;

    virtual ~Subject(){ }
};

#endif //TIMERAPPLICATION_SUBJECT_H
