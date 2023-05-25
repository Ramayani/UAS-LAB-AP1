#include <iostream>
#include <vector>
#include <string>

struct Tugas {
    std::string deskripsi; // Deskripsi dari tugas
    bool selesai; // Menyimpan status apakah tugas telah selesai atau belum

    Tugas(const std::string& desc) : deskripsi(desc), selesai(false) {} // Konstruktor untuk inisialisasi tugas dengan deskripsi dan status default
};

class DaftarTugas {
private:
    std::vector<Tugas> tugas; // Menyimpan daftar tugas dalam bentuk vektor

public:
    void tambahTugas(const std::string& deskripsi) {
        Tugas tugasBaru(deskripsi); // Membuat objek tugas baru dengan deskripsi yang diberikan
        tugas.push_back(tugasBaru); // Menambahkan tugas baru ke dalam daftar tugas
        std::cout << "Tugas berhasil ditambahkan." << std::endl; // Menampilkan pesan sukses
    }

    void tampilkanTugas() {
        if (tugas.empty()) {
            std::cout << "Tidak ada tugas yang ditemukan." << std::endl; // Menampilkan pesan jika tidak ada tugas dalam daftar
            return;
        }

        std::cout << "Daftar Tugas:" << std::endl; // Menampilkan label daftar tugas
        for (size_t i = 0; i < tugas.size(); ++i) {
            std::cout << "[" << i << "] " << tugas[i].deskripsi << " - "
                      << (tugas[i].selesai ? "Selesai" : "Belum Selesai") << std::endl; // Menampilkan indeks, deskripsi, dan status tugas
        }
    }

    void tandaiTugasSelesai(int indeks) {
        if (indeks < 0 || indeks >= tugas.size()) {
            std::cout << "Indeks tugas tidak valid." << std::endl; // Menampilkan pesan jika indeks tugas tidak valid
            return;
        }

        tugas[indeks].selesai = true; // Menandai tugas dengan indeks yang diberikan sebagai selesai
        std::cout << "Tugas ditandai sebagai selesai." << std::endl; // Menampilkan pesan sukses
    }

    void tandaiTugasBelumSelesai(int indeks) {
        if (indeks < 0 || indeks >= tugas.size()) {
            std::cout << "Indeks tugas tidak valid." << std::endl; // Menampilkan pesan jika indeks tugas tidak valid
            return;
        }

        tugas[indeks].selesai = false; // Menandai tugas dengan indeks yang diberikan sebagai belum selesai
        std::cout << "Tugas ditandai sebagai belum selesai." << std::endl; // Menampilkan pesan sukses
    }

    void hapusTugas(int indeks) {
        if (indeks < 0 || indeks >= tugas.size()) {
            std::cout << "Indeks tugas tidak valid." << std::endl; // Menampilkan pesan jika indeks tugas tidak valid
            return;
        }

        tugas.erase(tugas.begin() + indeks); // Menghapus tugas dengan indeks yang diberikan dari daftar tugas
        std::cout << "Tugas berhasil dihapus." << std::endl; // Menampilkan pesan sukses
    }
};
int main() {
    DaftarTugas daftarTugas;

    while (true) {
        std::cout << "Menu:" << std::endl; // Menampilkan menu
        std::cout << "1. Tambah Tugas" << std::endl; // Opsi untuk menambahkan tugas baru
        std::cout << "2. Tampilkan Tugas" << std::endl; // Opsi untuk menampilkan daftar tugas
        std::cout << "3. Tandai Tugas Selesai" << std::endl; // Opsi untuk menandai tugas sebagai selesai
        std::cout << "4. Tandai Tugas Belum Selesai" << std::endl; // Opsi untuk menandai tugas sebagai belum selesai
        std::cout << "5. Hapus Tugas" << std::endl; // Opsi untuk menghapus tugas dari daftar
        std::cout << "6. Keluar" << std::endl; // Opsi untuk keluar dari program

        int pilihan;
        std::cout << "Pilih menu (1-6): ";
        std::cin >> pilihan;

        if (pilihan == 1) {
            std::cin.ignore(); // Mengabaikan karakter newline
            std::string deskripsi;
            std::cout << "Masukkan deskripsi tugas: ";
            std::getline(std::cin, deskripsi);

        // untuk menambahkan tugas
            daftarTugas.tambahTugas(deskripsi);
        } else if (pilihan == 2) {
            daftarTugas.tampilkanTugas();
        } else if (pilihan == 3) {
            int indeks;
            std::cout << "Masukkan indeks tugas: ";
            std::cin >> indeks;

        // untuk menandai tugas yang selesai
            daftarTugas.tandaiTugasSelesai(indeks);
        } else if (pilihan == 4) {
            int indeks;
            std::cout << "Masukkan indeks tugas: ";
            std::cin >> indeks;

        //untuk menandai tugas yang belum selesai
            daftarTugas.tandaiTugasBelumSelesai(indeks);
        } else if (pilihan == 5) {
            int indeks;
            std::cout << "Masukkan indeks tugas: ";
            std::cin >> indeks;

        //untuk menghapus tugas yang di inginkan
            daftarTugas.hapusTugas(indeks);
        } else if (pilihan == 6) {
            break;
        } else {
            std::cout << "Pilihan tidak valid." << std::endl; //Menampilkan pesan bahwa pilihan tidak valid.
        }

        std::cout << std::endl;
    }

    return 0;
}

