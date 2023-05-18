#include "FileSubject.h"
#include <iostream>
#include <string>
#include <locale>

FileSubject::FileSubject(std::string filepath_) : filepath(filepath_), observed_file(filepath_), old_exist(false), old_size(0) {
    subj.Attach(&observed_file);  // Прикрепляем наблюдателя observed_file к объекту subj
    connect(&subj, &Subject::onExist, this, &FileSubject::print); // Соединяем сигнал onExist с методом print
}

void FileSubject::Monitor() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Приостанавливаем выполнение на 100 миллисекунд

        std::ifstream file(filepath);  // Открываем файл для чтения
        bool new_exist = file.good();  // Проверяем, существует ли файл
        int new_size = 0;

        if (new_exist) {
            file.seekg(0, std::ios::end);  // Переходим в конец файла
            new_size = file.tellg();  // Получаем текущую позицию в файле, что соответствует размеру файла
        }

        if (new_exist != old_exist)
            subj.NotifyExist(new_exist);  // Оповещаем subj о изменении состояния существования файла
        if (new_exist && new_size != old_size)
            subj.NotifySize(new_size);  // Оповещаем subj о изменении размера файла

        old_exist = new_exist;  // Обновляем значения old_exist и old_size
        old_size = new_size;

        file.close();  // Закрываем файл
    }
}

void FileSubject::print(MyFile* file) {
    setlocale(LC_ALL, "Russian");
    // Выводим информацию о файле
    std::cout << "File Information:" << std::endl;
    std::cout << "Path: " << file->getPath() << std::endl;
    std::cout << "Size: " << file->getSize() << " bytes" << std::endl;
    std::cout << "Exists: " << (file->getExist() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
}
