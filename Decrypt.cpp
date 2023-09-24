#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <bitset>
#include <sstream>
#include "Decrypt.h"
using namespace std;

Decrypt::Decrypt() {
    morse_translation.push_back(make_tuple('A', ".-", "1001"));
    morse_translation.push_back(make_tuple('B', "-...", "01101010"));
    morse_translation.push_back(make_tuple('C', "-.-.", "01100110"));
    morse_translation.push_back(make_tuple('D', "-..", "011010"));
    morse_translation.push_back(make_tuple('E', ".", "10"));
    morse_translation.push_back(make_tuple('F', "..-.", "10100110"));
    morse_translation.push_back(make_tuple('G', "--.", "010110"));
    morse_translation.push_back(make_tuple('H', "....", "10101010"));
    morse_translation.push_back(make_tuple('I', "..", "1010"));
    morse_translation.push_back(make_tuple('J', ".---", "10010101"));
    morse_translation.push_back(make_tuple('K', "-.-", "011001"));
    morse_translation.push_back(make_tuple('L', ".-..", "10011010"));
    morse_translation.push_back(make_tuple('M', "--", "0101"));
    morse_translation.push_back(make_tuple('N', "-.", "0110"));
    morse_translation.push_back(make_tuple('O', "---", "010101"));
    morse_translation.push_back(make_tuple('P', ".--.", "10010110"));
    morse_translation.push_back(make_tuple('Q', "--.-", "01011001"));
    morse_translation.push_back(make_tuple('R', ".-.", "100110"));
    morse_translation.push_back(make_tuple('S', "...", "101010"));
    morse_translation.push_back(make_tuple('T', "-", "01"));
    morse_translation.push_back(make_tuple('U', "..-", "101001"));
    morse_translation.push_back(make_tuple('V', "...-", "10101001"));
    morse_translation.push_back(make_tuple('W', ".--", "100101"));
    morse_translation.push_back(make_tuple('X', "-..-", "01101001"));
    morse_translation.push_back(make_tuple('Y', "-.--", "01100101"));
    morse_translation.push_back(make_tuple('Z', "--..", "01011010"));
    morse_translation.push_back(make_tuple('Ä', ".-.-", "10011001"));
    morse_translation.push_back(make_tuple('Ö', "---.", "01010110"));
    morse_translation.push_back(make_tuple('Ü', "..--", "10100101"));
    morse_translation.push_back(make_tuple('Š', "----", "01010101"));
    morse_translation.push_back(make_tuple('0', "-----", "0101010101"));
    morse_translation.push_back(make_tuple('1', ".----", "1001010101"));
    morse_translation.push_back(make_tuple('2', "..---", "1010010101"));
    morse_translation.push_back(make_tuple('3', "...--", "1010100101"));
    morse_translation.push_back(make_tuple('4', "....-", "1010101001"));
    morse_translation.push_back(make_tuple('5', ".....", "1010101010"));
    morse_translation.push_back(make_tuple('6', "-....", "0110101010"));
    morse_translation.push_back(make_tuple('7', "--...", "0101101010"));
    morse_translation.push_back(make_tuple('8', "---..", "0101011010"));
    morse_translation.push_back(make_tuple('9', "----.", "0101010110"));
    morse_translation.push_back(make_tuple('.', ".-.-.-", "100110011001"));
    morse_translation.push_back(make_tuple(',', "--..--", "010110100101"));
    morse_translation.push_back(make_tuple('?', "..--..", "101001011010"));
    morse_translation.push_back(make_tuple('!', "..--.", "1010010110"));
    morse_translation.push_back(make_tuple(':', "---...", "010101101010"));
    morse_translation.push_back(make_tuple('\"', ".-..-.", "100110100110"));
    morse_translation.push_back(make_tuple('\'', ".----.", "100101010110"));
    morse_translation.push_back(make_tuple('=', "-...-", "0110101001"));

    for (size_t i = 0; i < morse_translation.size(); i++) {
        const tuple<char, string, string>& atuple = morse_translation[i];
        //cout << "morse code " << get<0>(atuple) << endl;
        //cout << "morse code " << get<1>(atuple) << endl;
        //cout << "morse code " << get<2>(atuple) << endl;
    }
}

void Decrypt::run(const vector<unsigned char>& db)
{
    string char_code;
    for (int i = 0; i < db.size(); i++) {
        //cout << bitset<8>(db[i]) << endl;
        bitset<8> bits(db[i]);
        //cout << bs;

        for (int j = bits.size() - 1; j >= 0; j -= 2) {
            //cout << bits.test(j) << '\n';
            //cout << bits.test(j-1) << '\n';

            if (bits.test(j) == 0 && bits.test(j - 1) == 1) {
                char_code += "-";
            }
            else if (bits.test(j) == 1 && bits.test(j - 1) == 0) {
                char_code += ".";
            }
            else if (bits.test(j) == 0 && bits.test(j - 1) == 0) {
                for (size_t k = 0; k < morse_translation.size(); k++) {
                    if (char_code == get<1>(morse_translation[k])) {
                        data.push_back(get<0>(morse_translation[k]));
                        char_code.clear();
                        break;
                    }
                }
            }
            else if (bits.test(j) == 1 && bits.test(j - 1) == 1) {
                data.push_back(' ');
            }
        }
    }

    for (const char& c : data) {
        cout << c;
    }
}
