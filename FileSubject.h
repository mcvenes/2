#ifndef FILESUBJECT_H
#define FILESUBJECT_H

#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include "Subject.h"
#include "MyFile.h"

class FileSubject {
private:
    std::string filepath;
    MyFile observed_file;
    Subject subj;
    bool old_exist;
    int old_size;

public:
    FileSubject(std::string filepath_);
    void Monitor();
};

#endif // FILESUBJECT_H
