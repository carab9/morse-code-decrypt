#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
using namespace std;

class DataBase {
private:
    vector<unsigned char> db;

public:
    DataBase() {}

    void build(const char* data_file);

    const vector<unsigned char>& get_DB() const {
        return db;
    }
};

#endif // DATABASE_H
