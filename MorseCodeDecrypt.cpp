// MorseCodeDecrypt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "DataBase.h"
#include "Decrypt.h"
using namespace std;

int main()
{
    DataBase db;
    db.build("Morse.bin");

    Decrypt decrypt;
    decrypt.run(db.get_DB());

    return 0;
}
