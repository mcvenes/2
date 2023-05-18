#include <iostream>
#include <fstream>
#include "MyFile.h"
#include <locale>

MyFile::MyFile(std::string path_) : path(path_), size(0), exist(false) {
    std::ifstream fileStream(path_);  // Открываем файл для чтения
    if (fileStream) {  // Если файл успешно открыт
        exist = true;  // Устанавливаем флаг существования файла в true
        fileStream.seekg(0, std::ios::end);  // Перемещаем указатель в конец файла
        size = fileStream.tellg();  // Получаем текущую позицию указателя, которая является размером файла
    }
}

void MyFile::UpdateExist(bool exist_) {
    setlocale(LC_ALL, "Russian");
    exist = exist_;  // Обновляем значение флага существования файла
    if (exist) {
        std::cout << "File now exist" << std::endl;  // Если файл существует, выводим сообщение
    } else {
        std::cout << "File now doesn't exist" << std::endl;  // Если файл не существует, выводим сообщение
    }
}

void MyFile::UpdateSize(int size_) {
    if (exist) {  // Если файл существует
        size = size_;  // Обновляем размер файла
        std::cout << "File size is " << size << " bytes now" << std::endl;  // Выводим сообщение о новом размере файла
    }
}

std::string MyFile::getPath() const {
    return path;  // Возвращаем путь к файлу
}

int MyFile::getSize() const {
    return size;  // Возвращаем размер файла
}

bool MyFile::getExist() const {
    return exist;  // Возвращаем флаг существования файла
}
