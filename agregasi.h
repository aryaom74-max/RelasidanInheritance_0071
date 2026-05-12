#include <iostream>
#include <string> // Tambahkan ini untuk keamanan tipe data string
using namespace std;

// Pastikan anak.h di-include LEBIH DULU daripada ibu.h
// karena kelas 'ibu' membutuhkan definisi lengkap kelas 'anak' 
// untuk mencetak nama anak (daftar_anak[i]->nama)
#include "anak.h"
#include "ibu.h"

