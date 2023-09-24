#include <iostream>
#include <vector>
#include <fstream>
#include "DataBase.h"
#include "FileIO.h"
using namespace std;

void DataBase::build(const char* data_file) {
    FileIO file;
    auto v = file.read_file(data_file);
    if (v) {
        db = *v;
    }
}
