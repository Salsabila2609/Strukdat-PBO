#include <iostream>
#include <string>

//menetapkan maksimal data 10 mahasiswa
const int MAX_MAHASISWA = 10; 

struct Mhs {
    std::string Nama;
    int NRP;
    float IPK;
};

//menambahkan data baru
int addData(Mhs mhsArray[], int jumlahData) {
    if (jumlahData < MAX_MAHASISWA) {
        std::cout << "Masukkan data baru:" << std::endl;
        std::cout << "Nama: ";
        std::cin >> mhsArray[jumlahData].Nama;
        std::cout << "NRP: ";
        std::cin >> mhsArray[jumlahData].NRP;
        std::cout << "IPK: ";
        std::cin >> mhsArray[jumlahData].IPK;
        std::cout << "Data berhasil ditambahkan." << std::endl;
        return jumlahData + 1; 
    } else {
        std::cout << "Batas maksimal data adalah 10." << std::endl;
        return jumlahData;
    }
}

//menampilkan data
void showData(const Mhs mhsArray[], int jumlahData) {
    std::cout << "Data lengkap mahasiswa:" << std::endl;
    for (int i = 0; i < jumlahData; ++i) {
        std::cout << "Data-" << (i + 1) << ":" << std::endl;
        std::cout << "Nama: " << mhsArray[i].Nama << std::endl;
        std::cout << "NRP: " << mhsArray[i].NRP << std::endl;
        std::cout << "IPK: " << mhsArray[i].IPK << std::endl;
        std::cout << std::endl;
    }
}

//mengubah data dari yang sudah ada
void fixData(Mhs mhsArray[], int jumlahData, int indeks) {
    if (indeks >= 0 && indeks < jumlahData) {
        std::cout << "Masukkan data yang diubah:" << std::endl;
        std::cout << "Nama: ";
        std::cin >> mhsArray[indeks].Nama;
        std::cout << "NRP: ";
        std::cin >> mhsArray[indeks].NRP;
        std::cout << "IPK: ";
        std::cin >> mhsArray[indeks].IPK;
        std::cout << "Data berhasil diubah." << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }
}

//menghapus data
int delData(Mhs mhsArray[], int jumlahData, int indeks) {
    if (indeks >= 0 && indeks < jumlahData) {
        for (int i = indeks; i < jumlahData - 1; ++i) {
            mhsArray[i] = mhsArray[i + 1];
        }
        std::cout << "Data telah dihapus." << std::endl;
        return jumlahData - 1; 
    } else {
        std::cout << "Error" << std::endl;
        return jumlahData;
    }
}

int main() {
    Mhs listMhs[MAX_MAHASISWA];
    int jumlahData = 0;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Tampilkan Data" << std::endl;
        std::cout << "2. Tambah Data" << std::endl;
        std::cout << "3. Hapus Data" << std::endl;
        std::cout << "4. Ubah Data" << std::endl;
        std::cout << "5. Keluar" << std::endl;

        int menu;
        std::cout << "Pilih nomor menu: ";
        std::cin >> menu;

        switch (menu) {
            case 1:
                showData(listMhs, jumlahData);
                break;
            case 2:
                jumlahData = addData(listMhs, jumlahData);
                break;
            case 3:
                if (jumlahData > 0) {
                    std::cout << "Data yang ingin dihapus (0-" << (jumlahData - 1) << "): ";
                    int indeksHapus;
                    std::cin >> indeksHapus;
                    jumlahData = delData(listMhs, jumlahData, indeksHapus);
                } else {
                    std::cout << "Tidak ada data yang bisa dihapus" << std::endl;
                }
                break;
            case 4:
                if (jumlahData > 0) {
                    std::cout << "Data yang ingin diubah (0-" << (jumlahData - 1) << "): ";
                    int indeksUbah;
                    std::cin >> indeksUbah;
                    fixData(listMhs, jumlahData, indeksUbah);
                } else {
                    std::cout << "Tidak ada data yang bisa diubah" << std::endl;
                }
                break;
            case 5:
                std::cout << "Program selesai" << std::endl;
                return 0;
            default:
                std::cout << "Error" << std::endl;
                break;
        }
    }

return 0;
}