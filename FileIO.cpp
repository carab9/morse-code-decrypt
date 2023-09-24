#include <iostream>
#include <vector>
#include <fstream>
#include "FileIO.h"
using namespace std;

unique_ptr<vector<unsigned char>> FileIO::read_file(const char* filename) {
    auto data = make_unique<vector<unsigned char>>();
    string line;

    ifstream file;
    file.open(filename, ios::out | ios::binary);

    if (file.is_open()) {
        data->insert(data->begin(),
            istream_iterator<char>(file),
            istream_iterator<char>());
        file.close();
    }

    //for (int i = 0; i < data->size(); i++) {
        //cout << data->at(i);
    //}
    //cout << endl;

    return data;

}
