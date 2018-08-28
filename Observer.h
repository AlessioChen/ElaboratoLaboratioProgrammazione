//
// Created by alessio on 26/08/18.
//

#ifndef TIMERAPPLICATION_OBSERVER_H
#define TIMERAPPLICATION_OBSERVER_H

class Observer{
public:
    virtual void update() = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;

    virtual ~Observer(){ };
};

#endif //TIMERAPPLICATION_OBSERVER_H
