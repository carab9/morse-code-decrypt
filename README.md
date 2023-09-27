# morse-code-decrypt
This project is a Morse Code decryption program.  It reads a encrypted binary file, Morse.bin, encrypted by Morse Code bit patterns, stores it in a database, and then decrypts it to the original text and prints the decrypted text to stdout.

![image](https://github.com/carab9/morse-code-decrypt/blob/main/morse_code1.png?raw=true)

![image](https://github.com/carab9/morse-code-decrypt/blob/main/morse_code3.png?raw=true)

![image](https://github.com/carab9/morse-code-decrypt/blob/main/morse_code2.png?raw=true)

![image](https://github.com/carab9/morse-code-decrypt/blob/main/morse_code4.png?raw=true)

## Architecture
The main program uses a FileIO class object to read a encrypted binary file and store the data in a DataBase class object. After that, it uses a Decrypt class object to decrypt the encrypted binary data and print the decrypted text to stdout.

## Requirements
C++ and C++ libraries: iostream, string, fstream, vector, tuple, algorithm, iterator, bitset, sstream, smart pointer.

## Technical Skills
Decryption algorithm for Morse Code encryption using C++ smart pointers, bitset (for bit level data operation), sstream, iterator, and also C++ STL containers, such as vector, and tuple, and STL algorithms.

## Results
The decrypted text printed in stdout.

![image](https://github.com/carab9/morse-code-decrypt/blob/main/morse_code_decrypted.png?raw=true)
