#include <iostream>
#include <vector>
#include <string> // Tambahkan include string untuk keamanan

using namespace std;

// 1. Forward Declaration
class dokter; 

// 2. Definisi Kelas Pasien
class pasien {
public:
    string nama;
    vector<dokter*> daftar_dokter;

    pasien(string pNama) : nama(pNama) {
        cout << "Pasien \"" << nama << "\" ada\n";
    }
    ~pasien() {
        cout << "Pasien \"" << nama << "\" tidak ada\n";
    }
    
    void tambahDokter(dokter*);
    void cetakDokter();
};

// 3. Definisi Kelas Dokter
class dokter {
public:
    string nama;
    vector<pasien*> daftar_pasien;

    dokter(string pNama) : nama(pNama) {
        cout << "Dokter \"" << nama << "\" ada\n";
    }
    ~dokter() {
        cout << "Dokter \"" << nama << "\" tidak ada\n";
    }

    void tambahPasien(pasien*);
    void cetakPasien();
};

// 4. Implementasi Fungsi (Dilakukan setelah kedua kelas terdefinisi lengkap)
void pasien::tambahDokter(dokter* pDokter) {
    daftar_dokter.push_back(pDokter);
}

void pasien::cetakDokter() {
    cout << "Daftar Dokter yang menangani pasien \"" << this->nama << "\":\n";
    for (auto& a : daftar_dokter) {
        // Sekarang kompiler sudah tahu kalau dokter punya variabel 'nama'
        cout << a->nama << "\n"; 
    }
    cout << endl;
}

void dokter::tambahPasien(pasien* pPasien) {
    daftar_pasien.push_back(pPasien);
    pPasien->tambahDokter(this); // Menghubungkan secara dua arah
}

void dokter::cetakPasien() {
    cout << "Daftar Pasien dari dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

// 5. Main Function
int main() {
    dokter* varDokter1 = new dokter("dr.Budi");
    dokter* varDokter2 = new dokter("dr.Tono");
    pasien* varPasien1 = new pasien("Andi");
    pasien* varPasien2 = new pasien("Lia");

    varDokter1->tambahPasien(varPasien1);
    varDokter1->tambahPasien(varPasien2);
    varDokter2->tambahPasien(varPasien1);

    varDokter1->cetakPasien();
    varDokter2->cetakPasien();
    varPasien1->cetakDokter();
    varPasien2->cetakDokter();

    delete varPasien1;
    delete varPasien2;
    delete varDokter1;
    delete varDokter2;

    return 0;
}
