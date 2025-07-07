#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits> 

using namespace std;

struct Tiket{
    string kode;
    string maskapai;
    string tujuan;
    string asal;
    string tanggal; 
    string jam_keberangkatan;
    string jam_kedatangan;
    double harga;
};
void penerbangan (vector<Tiket> &tiket){
    Tiket t;
    cout<<"\n--- Tambah Tiket Baru ---"<<endl;
    cout<<"Masukan kode tiket           : ";
    cin >> t.kode;
    cout<<"Masukan maskapai             : ";
    cin >> t.maskapai;
    cout<<"Masukan tujuan               : ";
    cin >> t.tujuan;
    cout<<"Masukan asal                 : ";
    cin >> t.asal;
    cout<<"Masukan tanggal (YYYY-MM-DD) : ";
    cin >> t.tanggal;
    cout<<"Masukan jam keberangkatan    : ";
    cin >> t.jam_keberangkatan;
    cout<<"Masukan jam kedatangan       : ";
    cin >> t.jam_kedatangan;
    cout<<"Masukan harga                : ";
    cin >> t.harga;
    tiket.push_back(t);
    cout << "Tiket berhasil ditambahkan!" << endl;
}

void tampilkan_tiket(vector<Tiket> &tiket){
    if (tiket.empty()) {
        cout << "\nTidak ada tiket untuk ditampilkan." << endl;
        return;
    }
    cout << "\n--- Daftar Tiket ---" << endl;
    for(size_t i = 0; i < tiket.size(); ++i){
        cout << "Kode Tiket        : " << tiket[i].kode << endl;
        cout << "Maskapai          : " << tiket[i].maskapai << endl;
        cout << "Tujuan            : " << tiket[i].tujuan << endl;
        cout << "Asal              : " << tiket[i].asal << endl;
        cout << "Tanggal           : " << tiket[i].tanggal << endl;
        cout << "Jam Keberangkatan : " << tiket[i].jam_keberangkatan << endl;
        cout << "Jam Kedatangan    : " << tiket[i].jam_kedatangan << endl;
        cout << "Harga             : " << tiket[i].harga << endl;
        cout << "---------------------------------" << endl;
    }
    cout << endl;
}

void cari_tiket(vector<Tiket> &tiket){
    if (tiket.empty()) {
        cout << "\nTidak ada tiket untuk dicari." << endl;
        return;
    }
    string kode;
    cout << "Masukan kode tiket yang ingin dicari : ";
    cin >> kode;
    bool found = false;
    for(size_t i = 0; i < tiket.size(); ++i){
        if(tiket[i].kode == kode){
            cout << "\n--- Tiket Ditemukan ---" << endl;
            cout << "Kode Tiket        : " << tiket[i].kode << endl;
            cout << "Maskapai          : " << tiket[i].maskapai << endl;
            cout << "Tujuan            : " << tiket[i].tujuan << endl;
            cout << "Asal              : " << tiket[i].asal << endl;
            cout << "Tanggal           : " << tiket[i].tanggal << endl;
            cout << "Jam Keberangkatan : " << tiket[i].jam_keberangkatan << endl;
            cout << "Jam Kedatangan    : " << tiket[i].jam_kedatangan << endl;
            cout << "Harga             : " << tiket[i].harga << endl;
            cout << "---------------------------------" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Tiket dengan kode " << kode << " tidak ditemukan." << endl;
    }
}

void hapus_tiket(vector<Tiket> &tiket){
    if (tiket.empty()) {
        cout << "\nTidak ada tiket untuk dihapus." << endl;
        return;
    }
    string kode;
    cout << "Masukan kode tiket yang ingin dihapus : ";
    cin >> kode;
    bool deleted = false;
    for(size_t i = 0; i < tiket.size(); ++i){
        if(tiket[i].kode == kode){
            tiket.erase(tiket.begin() + i);
            cout << "Tiket berhasil dihapus!" << endl;
            deleted = true;
            break;
        }
    }
    if (!deleted) {
        cout << "Tiket dengan kode " << kode << " tidak ditemukan." << endl;
    }
}

void ubah_tiket(vector<Tiket> &tiket){
    if (tiket.empty()) {
        cout << "\nTidak ada tiket untuk diubah." << endl;
        return;
    }
    string kode;
    cout << "Masukan kode tiket yang ingin diubah : ";
    cin >> kode;
    bool updated = false;
    for(size_t i = 0; i < tiket.size(); ++i){
        if(tiket[i].kode == kode){
            cout << "\n--- Ubah Data Tiket ---" << endl;
            cout << "Masukan kode tiket baru          : ";
            cin >> tiket[i].kode;
            cout << "Masukan maskapai baru            : ";
            cin >> tiket[i].maskapai;
            cout << "Masukan tujuan baru              : ";
            cin >> tiket[i].tujuan;
            cout << "Masukan asal baru                : ";
            cin >> tiket[i].asal;
            cout << "Masukan tanggal baru (YYYY-MM-DD): ";
            cin >> tiket[i].tanggal;
            cout << "Masukan jam keberangkatan baru   : ";
            cin >> tiket[i].jam_keberangkatan;
            cout << "Masukan jam kedatangan baru      : ";
            cin >> tiket[i].jam_kedatangan;
            cout << "Masukan harga baru               : ";
            cin >> tiket[i].harga;
            cout << "Tiket berhasil diubah!" << endl;
            updated = true;
            break;
        }
    }
    if (!updated) {
        cout << "Tiket dengan kode " << kode << " tidak ditemukan." << endl;
    }
}

void tampilkan_tiket_tertinggi(vector<Tiket> &tiket){
    if (tiket.empty()) {
        cout << "\nTidak ada tiket untuk dibandingkan (daftar kosong)." << endl;
        return;
    }

    double max_harga = -1.0; 
    Tiket *tiket_tertinggi = nullptr;

    for(size_t i = 0; i < tiket.size(); ++i){
        if(tiket[i].harga > max_harga){
            max_harga = tiket[i].harga;
            tiket_tertinggi = &tiket[i]; 
        }
    }

    if (tiket_tertinggi != nullptr) {
        cout << "\n--- Tiket dengan Harga Tertinggi ---" << endl;
        cout << "Kode Tiket        : " << tiket_tertinggi->kode << endl;
        cout << "Maskapai          : " << tiket_tertinggi->maskapai << endl;
        cout << "Tujuan            : " << tiket_tertinggi->tujuan << endl;
        cout << "Asal              : " << tiket_tertinggi->asal << endl;
        cout << "Tanggal           : " << tiket_tertinggi->tanggal << endl;
        cout << "Jam Keberangkatan : " << tiket_tertinggi->jam_keberangkatan << endl;
        cout << "Jam Kedatangan    : " << tiket_tertinggi->jam_kedatangan << endl;
        cout << "Harga             : " << tiket_tertinggi->harga << endl;
        cout << "-----------------------------------" << endl;
    } else {
        cout << "Tidak dapat menemukan tiket dengan harga tertinggi." << endl;
    }
}

void tampilkan_tiket_terendah(vector<Tiket> &tiket){
    if (tiket.empty()) {
        cout << "\nTidak ada tiket untuk dibandingkan (daftar kosong)." << endl;
        return;
    }

    double min_harga = tiket[0].harga;
    Tiket *tiket_terendah = &tiket[0];

    for(size_t i = 1; i < tiket.size(); ++i){
        if(tiket[i].harga < min_harga){
            min_harga = tiket[i].harga;
            tiket_terendah = &tiket[i];
        }
    }

    if (tiket_terendah != nullptr) {
        cout << "\n--- Tiket dengan Harga Terendah ---" << endl;
        cout << "Kode Tiket        : " << tiket_terendah->kode << endl;
        cout << "Maskapai          : " << tiket_terendah->maskapai << endl;
        cout << "Tujuan            : " << tiket_terendah->tujuan << endl;
        cout << "Asal              : " << tiket_terendah->asal << endl;
        cout << "Tanggal           : " << tiket_terendah->tanggal << endl;
        cout << "Jam Keberangkatan : " << tiket_terendah->jam_keberangkatan << endl;
        cout << "Jam Kedatangan    : " << tiket_terendah->jam_kedatangan << endl;
        cout << "Harga             : " << tiket_terendah->harga << endl;
        cout << "-----------------------------------" << endl;
    } else {
        cout << "Tidak dapat menemukan tiket dengan harga terendah." << endl;
    }
}

void tampilkan_tiket_terlama(vector<Tiket> &tiket){
    if (tiket.empty()) {
        cout << "\nTidak ada tiket untuk dibandingkan (daftar kosong)." << endl;
        return;
    }

    string tanggal_terlama = tiket[0].tanggal;
    Tiket *tiket_terlama_ptr = &tiket[0];

    for(size_t i = 1; i < tiket.size(); ++i){
        if(tiket[i].tanggal < tanggal_terlama){ 
            tanggal_terlama = tiket[i].tanggal;
            tiket_terlama_ptr = &tiket[i];
        }
    }

    if (tiket_terlama_ptr != nullptr) {
        cout << "\n--- Tiket dengan Tanggal Keberangkatan Paling Awal ---" << endl;
        cout << "Kode Tiket        : " << tiket_terlama_ptr->kode << endl;
        cout << "Maskapai          : " << tiket_terlama_ptr->maskapai << endl;
        cout << "Tujuan            : " << tiket_terlama_ptr->tujuan << endl;
        cout << "Asal              : " << tiket_terlama_ptr->asal << endl;
        cout << "Tanggal           : " << tiket_terlama_ptr->tanggal << endl;
        cout << "Jam Keberangkatan : " << tiket_terlama_ptr->jam_keberangkatan << endl;
        cout << "Jam Kedatangan    : " << tiket_terlama_ptr->jam_kedatangan << endl;
        cout << "Harga             : " << tiket_terlama_ptr->harga << endl;
        cout << "----------------------------------------------------" << endl;
    } else {
        cout << "Tidak dapat menemukan tiket dengan tanggal terlama." << endl;
    }
}

void tampilkanMenu() {
    cout << "\n===== Aplikasi Manajemen Tiket Pesawat =====" << endl;
    cout << "1. Tambah Tiket Baru" << endl;
    cout << "2. Tampilkan Semua Tiket" << endl;
    cout << "3. Cari Tiket Berdasarkan Kode" << endl;
    cout << "4. Hapus Tiket Berdasarkan Kode" << endl;
    cout << "5. Ubah Data Tiket" << endl;
    cout << "6. Tampilkan Tiket dengan Harga Tertinggi" << endl;
    cout << "7. Tampilkan Tiket dengan Harga Terendah" << endl;
    cout << "8. Tampilkan Tiket dengan Tanggal Keberangkatan Paling Awal" << endl;
    cout << "9. Keluar" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    vector<Tiket> daftar_tiket;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1:
                penerbangan(daftar_tiket);
                break;
            case 2:
                tampilkan_tiket(daftar_tiket);
                break;
            case 3:
                cari_tiket(daftar_tiket);
                break;
            case 4:
                hapus_tiket(daftar_tiket);
                break;
            case 5:
                ubah_tiket(daftar_tiket);
                break;
            case 6:
                tampilkan_tiket_tertinggi(daftar_tiket);
                break;
            case 7:
                tampilkan_tiket_terendah(daftar_tiket);
                break;
            case 8:
                tampilkan_tiket_terlama(daftar_tiket);
                break;
            case 9:
                cout << "\nTerima kasih telah menggunakan aplikasi. Sampai jumpa!" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan masukkan angka antara 1 dan 9." << endl;
                break;
        }
    } while (pilihan != 9); 

    return 0;
}
