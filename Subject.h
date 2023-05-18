#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <algorithm>
#include "MyFile.h"

class Subject {
    std::vector<MyFile*> files;

public:
    void Attach(MyFile* file);
    void Detach(MyFile* file);
    void NotifyExist(bool exist);
    void NotifySize(int size);
};

#endif // SUBJECT_H
