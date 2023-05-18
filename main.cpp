#include <string>
#include <thread>
#include <fstream>

#include "FileSubject.h"

int main() {
    std::string filepath = "D:\\test.txt";
    FileSubject fileSubject(filepath);
    fileSubject.Monitor();

    return 0;
}
