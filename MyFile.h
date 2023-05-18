#ifndef MYFILE_H
#define MYFILE_H

#include <string>
#include "Observer.h"

class MyFile : public Observer {
private:
    std::string path;    // Путь к файлу
    int size;            // Размер файла
    bool exist;          // Флаг существования файла

public:
    MyFile(std::string path_);      // Конструктор класса MyFile
    void UpdateExist(bool exist_) override;  // Метод для обновления состояния существования файла
    void UpdateSize(int size_) override;     // Метод для обновления размера файла
    std::string getPath() const;             // Метод для получения пути к файлу
    int getSize() const;                     // Метод для получения размера файла
    bool getExist() const;                   // Метод для получения состояния существования файла
};

#endif // MYFILE_H
