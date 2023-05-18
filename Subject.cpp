#include "Subject.h"

void Subject::Attach(MyFile* file) {
    files.push_back(file);
}

void Subject::Detach(MyFile* file) {
    files.erase(std::remove(files.begin(), files.end(), file), files.end());
}

void Subject::NotifyExist(bool exist) {
    for (auto iter = files.begin(); iter != files.end(); ++iter) {
        if (*iter != nullptr) {
            (*iter)->UpdateExist(exist);
        }
    }
}

void Subject::NotifySize(int size) {
    for (auto iter = files.begin(); iter != files.end(); ++iter) {
        if (*iter != nullptr) {
            (*iter)->UpdateSize(size);
        }
    }
}
