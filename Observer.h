#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void UpdateExist(bool exist) = 0;
    virtual void UpdateSize(int size) = 0;
};

#endif // OBSERVER_H
