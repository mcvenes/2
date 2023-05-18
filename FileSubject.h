#ifndef FILESUBJECT_H
#define FILESUBJECT_H

#include <QObject>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include "Subject.h"
#include "MyFile.h"

class FileSubject : public QObject {
    Q_OBJECT

private:
    std::string filepath;        // Путь к файлу
    MyFile observed_file;        // Наблюдаемый файл
    Subject subj;                // Предмет (наблюдатель)
    bool old_exist;              // Предыдущее состояние существования файла
    int old_size;                // Предыдущий размер файла

public slots:
    void print(MyFile* file);    // Слот для вывода информации о файле

public:
    FileSubject(std::string filepath_);  // Конструктор класса FileSubject
    void Monitor();                      // Метод для мониторинга изменений в файле
};

#endif // FILESUBJECT_H
