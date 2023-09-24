#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
using namespace std;

class FileIO {
public:
    FileIO() {}

    unique_ptr<vector<unsigned char>> read_file(const char* filename);
};

#endif // FILEIO_H