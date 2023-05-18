#ifndef MYFILE_H
#define MYFILE_H

#include "Observer.h"
#include <string>

class MyFile : public Observer {
private:
    std::string path;
    int size;
    bool exist;

public:
    MyFile(std::string path_);
    void UpdateExist(bool exist_) override;
    void UpdateSize(int size_) override;
};

#endif // MYFILE_H
