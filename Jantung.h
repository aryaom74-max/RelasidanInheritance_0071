#ifndef JANTUNG_H
#define JANTUNG_H

#include <iostream> // Library wajib untuk cout

class jantung {
public:
    jantung() {
        std::cout << "jantung dihidupkan\n";
    }
    ~jantung() {
        std::cout << "jantung dimatikan\n";
    }
};

#endif
