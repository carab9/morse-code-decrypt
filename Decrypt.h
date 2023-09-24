#ifndef DECRYPT_H
#define DECRYPT_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class Decrypt {
private:
    vector<tuple<char, string, string>> morse_translation;
    vector<unsigned char> data;

public:
    Decrypt();

    void run(const vector<unsigned char>& db);

};

#endif // DECRYPT_H