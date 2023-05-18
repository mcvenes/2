#include "Subject.h"

void Subject::Attach(MyFile* file) {
    files.push_back(file);  // Добавляем указатель на файл в вектор наблюдателей
}

void Subject::Detach(MyFile* file) {
    files.erase(std::remove(files.begin(), files.end(), file), files.end());  // Удаляем указатель на файл из вектора наблюдателей
}

void Subject::NotifyExist(bool exist) {
    for (auto iter = files.begin(); iter != files.end(); ++iter) {
        if (*iter != nullptr) {
            (*iter)->UpdateExist(exist);  // Вызываем метод обновления состояния существования файла у каждого наблюдателя
            emit onExist(*iter); // Генерируем сигнал onExist для оповещения об изменении состояния существования файла
        }
    }
}

void Subject::NotifySize(int size) {
    for (auto iter = files.begin(); iter != files.end(); ++iter) {
        if (*iter != nullptr) {
            (*iter)->UpdateSize(size);  // Вызываем метод обновления размера файла у каждого наблюдателя
        }
    }
}
