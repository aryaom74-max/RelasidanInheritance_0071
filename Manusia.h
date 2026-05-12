#ifndef MANUSIA_H
#define MANUSIA_H

#include <iostream>
#include <string>
#include "jantung.h" // Wajib disertakan karena ada variabel varJantung

class manusia {
public:
    std::string name;
    jantung varJantung; // Objek jantung sebagai bagian integral dari manusia

    manusia(std::string pName) : name(pName) {
        std::cout << name << " hidup\n";
    }

    ~manusia() {
        std::cout << name << " mati\n";
    }
};

#endif

