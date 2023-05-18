#include <iostream>
#include <string>
#include "FileSubject.h"

int main() {
    std::setlocale(LC_ALL, "Russian");
    std::string filepath = "D:\\test.txt";  // Путь к файлу
    FileSubject fileSubject(filepath);  // Создаем объект FileSubject с указанным путем
    fileSubject.Monitor();  // Запускаем мониторинг файла
    return 0;
}
