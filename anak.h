#ifndef ANAK_H
#define ANAK_H

#include <iostream> // Dibutuhkan untuk cout
#include <string>   // Dibutuhkan untuk string

using namespace std; // Agar tidak perlu menulis std::string atau std::cout

class anak {
public:

    string nama;
    
    // Constructor
    anak(string pNama) : nama(pNama) {
        cout << "Anak \"" << nama << "\" ada\n";
    }
    
    // Destructor
    ~anak() {
        cout << "Anak \"" << nama << "\" tidak ada\n";
    }
};

#endif