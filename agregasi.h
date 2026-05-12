#include <iostream>
#include <string> // Tambahkan ini untuk keamanan tipe data string
using namespace std;

// Pastikan anak.h di-include LEBIH DULU daripada ibu.h
// karena kelas 'ibu' membutuhkan definisi lengkap kelas 'anak' 
// untuk mencetak nama anak (daftar_anak[i]->nama)
#include "anak.h"
#include "ibu.h"

int main() {
    // Membuat objek secara dinamis di heap menggunakan 'new'
    ibu* varIbu = new ibu("dini");
    ibu* varIbu2 = new ibu("novi");
    
    anak* varAnak1 = new anak("tono");
    anak* varAnak2 = new anak("rini");
    anak* varAnak3 = new anak("Dewi");

    // Menghubungkan objek (Agregasi)
    varIbu->tambahAnak(varAnak1);
    varIbu->tambahAnak(varAnak2);
    varIbu2->tambahAnak(varAnak3);
    varIbu2->tambahAnak(varAnak1); // Satu anak bisa dimiliki dua ibu dalam agregasi ini

    // Menampilkan data
    varIbu->cetakAnak();
    varIbu2->cetakAnak();

    // Penghapusan objek
    // Dalam Agregasi, menghapus 'ibu' tidak otomatis menghapus 'anak'
    delete varIbu;
    delete varIbu2;
    
    // Objek anak harus dihapus manual karena dibuat dengan 'new'
    delete varAnak1;
    delete varAnak2;
    delete varAnak3;

    return 0;
}