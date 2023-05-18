#include "FileSubject.h"

FileSubject::FileSubject(std::string filepath_) : filepath(filepath_), observed_file(filepath_), old_exist(false), old_size(0) {
    subj.Attach(&observed_file);
}

void FileSubject::Monitor() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::ifstream file(filepath);
        bool new_exist = file.good();
        int new_size = 0;

        if (new_exist) {
            file.seekg(0, std::ios::end);
            new_size = file.tellg();
        }

        if (new_exist != old_exist)
            subj.NotifyExist(new_exist);
        if (new_exist && new_size != old_size)
            subj.NotifySize(new_size);

        old_exist = new_exist;
        old_size = new_size;

        file.close();
    }
}
