#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    int angkatan;
    long int nilai;
};

class mahaSiswa {
public:
    void tambahMahasiswa(vector<Mahasiswa>& data);
    void simpanDataMahasiswa(const vector<Mahasiswa>& data);
    void muatDataMahasiswa(vector<Mahasiswa>& data); 
    void daftarMahasiswa(const vector<Mahasiswa>& data);
    void caridataMahasiswa(const vector<Mahasiswa>& data);
    void sortingNilaiTerkecil(vector<Mahasiswa>& data);
    void sortingNilaiTerbesar(vector<Mahasiswa>& data);
    void nilaiLulus(const vector<Mahasiswa>& data);
    void nilaiTidakLulus(const vector<Mahasiswa>& data);
};

void mahaSiswa::tambahMahasiswa(vector<Mahasiswa>& data) {
    Mahasiswa Msiswa;
    cout << "Masukkan nama : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, Msiswa.nama);
    cout << "Masukkan nim : ";
    getline(cin, Msiswa.nim);
    cout << "Masukkan angkatan: ";
    cin >> Msiswa.angkatan;
    cout << "Masukkan nilai : ";
    cin >> Msiswa.nilai;
    cout << endl;
    data.push_back(Msiswa);
    cout << "Data ditambahkan." << endl;
    cout << endl;
}

void mahaSiswa::simpanDataMahasiswa(const vector<Mahasiswa>& data) {
    ofstream file("data_mahasiswa.txt");
    if (file.is_open()) {
        for (int i = 0; i < data.size(); ++i) { 
            file << data[i].nama << '\n';
            file << data[i].nim << '\n';
            file << data[i].angkatan << '\n';
            file << data[i].nilai << '\n';
        }
        file.close();
        cout << "Data berhasil disimpan." << endl;
        cout << endl;
    } else {
        cout << "Gagal" << endl;
    }
}
void mahaSiswa::muatDataMahasiswa(vector<Mahasiswa>& data) {
    data.clear();
    ifstream file("data_mahasiswa.txt");
    if (file.is_open()) {
        Mahasiswa mhs;
        string line;
        while (getline(file, line)) {
            mhs.nama = line;
            
            if (!getline(file, line)) break;
            mhs.nim = line;

            if (!getline(file, line)) break;
            stringstream ss_angkatan(line);
            ss_angkatan >> mhs.angkatan;

            if (!getline(file, line)) break; 
            stringstream ss_nilai(line);
            ss_nilai >> mhs.nilai;

            data.push_back(mhs);
        }
        file.close();
        cout << "Data berhasil diinput" << endl;
    } else {
        cout << "File kosong." << endl;
    }
    cout << endl;
}

void mahaSiswa::daftarMahasiswa(const vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Tidak ada data" << endl;
        return;
    }
    cout << "Daftar" << endl;
    for (int i = 0; i < data.size(); ++i) {
        cout << "Nama : " << data[i].nama << endl;
        cout << "NIM : " << data[i].nim << endl;
        cout << "Angkatan : " << data[i].angkatan << endl;
        cout << "Nilai : " << data[i].nilai << endl;
        cout << endl;
    }
}

void mahaSiswa::caridataMahasiswa(const vector<Mahasiswa>& data) {
    string namaMahasiswa;
    cout << "Masukkan nama yang ingin dicari: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, namaMahasiswa);

    bool ditemukan = false;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i].nama == namaMahasiswa) {
            cout << "Mahasiswa ditemukan :" << endl;
            cout << "Nama : " << data[i].nama << endl;
            cout << "NIM : " << data[i].nim << endl;
            cout << "Angkatan : " << data[i].angkatan << endl;
            cout << "Nilai : " << data[i].nilai << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Mahasiswa tidak ditemukan." << endl;
    }
    cout << endl;
}
bool bandingNilaiTertinggi(const Mahasiswa& a, const Mahasiswa& b) {
    return a.nilai > b.nilai;
}
void mahaSiswa::sortingNilaiTerbesar(vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Tidak ada data mahasiswa." << endl;
        return;
    }
    sort(data.begin(), data.end(), bandingNilaiTertinggi);
    cout << "Daftar Mahasiswa Tertinggi:" << endl;
    for (int i = 0; i < data.size(); ++i) { 
        cout << "Nama mahasiswa : " << data[i].nama << endl;
        cout << "NIM : " << data[i].nim << endl;
        cout << "Angkatan : " << data[i].angkatan << endl;
        cout << "Nilai : " << data[i].nilai << endl;
        cout << endl;
    }
}
bool bandingNilaiTerendah(const Mahasiswa& a, const Mahasiswa& b) {
    return a.nilai < b.nilai;
}
void mahaSiswa::sortingNilaiTerkecil(vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Tidak ada data mahasiswa" << endl;
        return;
    }
    sort(data.begin(), data.end(), bandingNilaiTerendah);
    cout << "Daftar Mahasiswa Terendah:" << endl;
    for (int i = 0; i < data.size(); ++i) { 
        cout << "Nama mahasiswa : " << data[i].nama << endl;
        cout << "NIM : " << data[i].nim << endl;
        cout << "Angkatan : " << data[i].angkatan << endl;
        cout << "Nilai : " << data[i].nilai << endl;
        cout << endl;
    }
}

void mahaSiswa::nilaiLulus(const vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Tidak ada data mahasiswa" << endl;
        return;
    }
    ofstream file("data_lulus.txt");
    if (file.is_open()) {
        bool adaYangLulus = false;
        cout << "Daftar Mahasiswa Lulus >=75 :" << endl;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i].nilai >= 75) {
                cout << "Nama mahasiswa : " << data[i].nama << endl;
                cout << "NIM : " << data[i].nim << endl;
                cout << "Angkatan : " << data[i].angkatan << endl;
                cout << "Nilai : " << data[i].nilai << endl;
                cout << endl;
                file << "Nama: " << data[i].nama << ", NIM: " << data[i].nim << ", Angkatan: " << data[i].angkatan << ", Nilai: " << data[i].nilai << '\n';
                adaYangLulus = true;
            }
        }
        if (!adaYangLulus) {
            cout << "Tidak ada mahasiswa yang lulus" << endl;
        }
        file.close();
    } else {
        cout << "Gagal" << endl;
    }
    cout << endl;
}

void mahaSiswa::nilaiTidakLulus(const vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Tidak ada data mahasiswa" << endl;
        return;
    }
    ofstream file("data_tidak_lulus.txt");
    if (file.is_open()) {
        bool adaYangTidakLulus = false;
        cout << "Daftar Mahasiswa Tidak Lulus >=75 :" << endl;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i].nilai < 75) {
                cout << "Nama mahasiswa : " << data[i].nama << endl;
                cout << "NIM : " << data[i].nim << endl;
                cout << "Angkatan : " << data[i].angkatan << endl;
                cout << "Nilai : " << data[i].nilai << endl;
                cout << endl;
                file << "Nama: " << data[i].nama << ", NIM: " << data[i].nim << ", Angkatan: " << data[i].angkatan << ", Nilai: " << data[i].nilai << '\n';
                adaYangTidakLulus = true;
            }
        }
        if (!adaYangTidakLulus) {
            cout << "tidak ada data." << endl;
        }
        file.close();
    } else {
        cout << "Gagal membuka file" << endl;
    }
    cout << endl;
}


int main() {
    vector<Mahasiswa> data;
    mahaSiswa m;
    int pil;
    m.muatDataMahasiswa(data);

    do {
        cout << "Fitur Pencarian : " << endl;
        cout << "1. Tambah " << endl;
        cout << "2. Daftar " << endl;
        cout << "3. Cari Data " << endl;
        cout << "4. Sorting Nilai terbesar" << endl;
        cout << "5. Sorting Nilai terkecil" << endl;
        cout << "6. Nilai  lulus" << endl;
        cout << "7. Nilai tidak lulus" << endl;
        cout << "8. Keluar" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pil;
        if (cin.fail()) {
            cout << "Input tidak valid." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << endl;
            continue; 
        }
        cout << endl; 

        switch (pil) {
            case 1:
                m.tambahMahasiswa(data);
                m.simpanDataMahasiswa(data); break;
            case 2:
                m.daftarMahasiswa(data); break;
            case 3:
                m.caridataMahasiswa(data); break;
            case 4:
                m.sortingNilaiTerbesar(data); break;
            case 5:
                m.sortingNilaiTerkecil(data); break;
            case 6:
                m.nilaiLulus(data); break;

            case 7:
                m.nilaiTidakLulus(data); break;
            case 8:
                cout << "Terima kasih telah menggunakan program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pil != 8);

    return 0;
}
