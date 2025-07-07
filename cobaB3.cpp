#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Buku {
    int nomer;
    string judul;
    string penulis;
    int stok;
};

vector<Buku> bacaDataBuku(const string& namaFile) {
    vector<Buku> daftarBuku;
    ifstream file(namaFile);
    if (file.is_open()) {
        Buku buku;
        while (file >> buku.nomer) {
            file.ignore(); 
            getline(file, buku.judul, ';');
            getline(file, buku.penulis, ';');
            file >> buku.stok;
            file.ignore(); 
            daftarBuku.push_back(buku);
        }
        file.close();
    } else {
        cerr << "Tidak dapat membuka file " << namaFile << endl;
    }
    return daftarBuku;
}

void tambahBukuBaru(vector<Buku>& daftarBuku, const string& namaFile) {
    ofstream file(namaFile, ios::app); 
    if (file.is_open()) {
        Buku bukuBaru;
        cout << "\n--- Tambah Buku Baru ---\n";
        cout << "Masukkan nomor buku: ";
        cin >> bukuBaru.nomer;
        cin.ignore(); 

        cout << "Masukkan judul buku: ";
        getline(cin, bukuBaru.judul);

        cout << "Masukkan nama penulis: ";
        getline(cin, bukuBaru.penulis);

        cout << "Masukkan stok buku: ";
        cin >> bukuBaru.stok;
        cin.ignore(); 

        daftarBuku.push_back(bukuBaru);

        file << bukuBaru.nomer << " " << bukuBaru.judul << ";" << bukuBaru.penulis << ";" << bukuBaru.stok << endl;
        file.close();
        cout << "Buku berhasil ditambahkan!\n\n";
    } else {
        cerr << "Tidak dapat membuka file " << namaFile << " untuk menambahkan buku." << endl;
    }
}

void simpanHasilPencarian(const vector<Buku>& hasil, const string& namaFile) {
    ofstream file(namaFile);
    if (file.is_open()) {
        for (const auto& buku : hasil) {
            file << buku.nomer << " " << buku.judul << " " << buku.penulis << " " << buku.stok << endl;
        }
        file.close();
    } else {
        cerr << "Tidak dapat membuka file " << namaFile << endl;
    }
}

vector<Buku> cariBukuBerdasarkanPenulis(const vector<Buku>& daftarBuku, const string& penulis) {
    vector<Buku> hasil;
    for (const auto& buku : daftarBuku) {
        if (buku.penulis.find(penulis) != string::npos) { 
            hasil.push_back(buku);
        }
    }
    return hasil;
}

vector<Buku> cariBukuBerdasarkanJudul(const vector<Buku>& daftarBuku, const string& judul) {
    vector<Buku> hasil;
    for (const auto& buku : daftarBuku) {
        if (buku.judul.find(judul) != string::npos) {
            hasil.push_back(buku);
        }
    }
    return hasil;
}


void urutkanBukuAtoZ(vector<Buku>& daftarBuku) {
    sort(daftarBuku.begin(), daftarBuku.end(), [](const Buku& a, const Buku& b) {
        return a.judul < b.judul;
    });
}

void urutkanBukuZtoA(vector<Buku>& daftarBuku) {
    sort(daftarBuku.begin(), daftarBuku.end(), [](const Buku& a, const Buku& b) {
        return a.judul > b.judul;
    });
}

void tampilkanMenu() {
    cout << "Menu:\n";
    cout << "1. Cari buku berdasarkan penulis\n";
    cout << "2. Cari buku berdasarkan judul\n";
    cout << "3. Urutkan buku berdasarkan judul A-Z\n";
    cout << "4. Urutkan buku berdasarkan judul Z-A\n";
    cout << "5. Tampilkan daftar buku\n";
    cout << "6. Tambah buku baru\n";
    cout << "7. Keluar\n";
    cout << "Masukkan pilihan: ";
}

void tampilkanBuku(const vector<Buku>& daftarBuku) {
    cout << "\nDaftar Buku:\n";
    if (daftarBuku.empty()) {
        cout << "Tidak ada buku untuk ditampilkan.\n";
        return;
    }
    for (const auto& buku : daftarBuku) {
        cout << "Nomer: " << buku.nomer << endl;
        cout << "Judul: " << buku.judul << endl;
        cout << "Penulis: " << buku.penulis << endl;
        cout << "Stok: " << buku.stok << endl;
        cout << "-------------------------\n";
    }
    cout << "\n";
}

int main() {
    vector<Buku> daftarBuku = bacaDataBuku("buku.txt");
    int pilihan;

    while (true) {
        tampilkanMenu();
        cin >> pilihan;

        if (pilihan == 1) {
            string penulis;
            cout << "Masukkan nama penulis: ";
            cin.ignore();
            getline(cin, penulis);
            vector<Buku> hasil = cariBukuBerdasarkanPenulis(daftarBuku, penulis);
            simpanHasilPencarian(hasil, "hasil_pencarian.txt");
            tampilkanBuku(hasil);
        } else if (pilihan == 2) {
            string judul;
            cout << "Masukkan judul buku: ";
            cin.ignore();
            getline(cin, judul);
            vector<Buku> hasil = cariBukuBerdasarkanJudul(daftarBuku, judul);
            simpanHasilPencarian(hasil, "hasil_pencarian.txt");
            tampilkanBuku(hasil);
        } else if (pilihan == 3) {
            urutkanBukuAtoZ(daftarBuku);
            tampilkanBuku(daftarBuku);
        } else if (pilihan == 4) {
            urutkanBukuZtoA(daftarBuku);
            tampilkanBuku(daftarBuku);
        } else if (pilihan == 5) {
            tampilkanBuku(daftarBuku);
        } else if (pilihan == 6) { 
            tambahBukuBaru(daftarBuku, "buku.txt");
        } else if (pilihan == 7) {
            cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!\n";
            break;
        } else {
            cerr << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    }

    return 0;
}
