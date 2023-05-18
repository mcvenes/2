#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include <vector>
#include <algorithm>
#include "MyFile.h"

class Subject : public QObject {
    Q_OBJECT

private:
    std::vector<MyFile*> files;  // Вектор указателей на объекты MyFile

signals:
    void onExist(MyFile* file);  // Сигнал для оповещения о состоянии существования файла

public:
    void Attach(MyFile* file);  // Метод для присоединения наблюдателя (файла)
    void Detach(MyFile* file);  // Метод для отсоединения наблюдателя (файла)
    void NotifyExist(bool exist);  // Метод для оповещения о состоянии существования файла
    void NotifySize(int size);  // Метод для оповещения о размере файла
};

#endif // SUBJECT_H
