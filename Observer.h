#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>

class Observer : public QObject {
    Q_OBJECT

public:
    virtual void UpdateExist(bool exist) = 0;  // Виртуальный метод для обновления состояния существования файла
    virtual void UpdateSize(int size) = 0;    // Виртуальный метод для обновления размера файла
};

#endif // OBSERVER_H
