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

#ifndef IBU_H
#define IBU_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward Declaration: Memberitahu kompiler bahwa class anak akan ada nanti
class anak; 

class ibu {
public:
    string nama;
    vector<anak*> daftar_anak;

    ibu(string pNama) : nama(pNama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    }

    ~ibu() {
        cout << "Ibu \"" << nama << "\" tidak ada\n";
    }

    void tambahAnak(anak*);
    void cetakAnak();
};

// Catatan: Implementasi fungsi di bawah ini sebaiknya diletakkan di file .cpp 
// atau pastikan class anak sudah didefinisikan lengkap sebelum fungsi ini dipanggil.

void ibu::tambahAnak(anak* pAnak) {
    daftar_anak.push_back(pAnak);
}

void ibu::cetakAnak() {
    cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
    for (int i = 0; i < daftar_anak.size(); i++) {
        // Kita butuh definisi lengkap class anak untuk mengakses member .nama
        // Jika kode ini di file header, pastikan sudah #include "anak.h"
        cout << daftar_anak[i]->nama << endl; 
    }
    cout << endl;
}

#endif

