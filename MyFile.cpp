#include <iostream>
#include <fstream>
#include "MyFile.h"

MyFile::MyFile(std::string path_) : path(path_), size(0), exist(false) {
    std::ifstream fileStream(path_);
    if (fileStream) {
        exist = true;
        fileStream.seekg(0, std::ios::end);
        size = fileStream.tellg();
    }
}

void MyFile::UpdateExist(bool exist_) {
    exist = exist_;
    if (exist) {
        std::cout << "File now exists" << std::endl;
    } else {
        std::cout << "File now doesn't exist" << std::endl;
    }
}

void MyFile::UpdateSize(int size_) {
    if (exist) {
        size = size_;
        std::cout << "File size is " << size << " bytes now" << std::endl;
    }
}
