#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Mahasiswa {
  string nama;
  string nim;
  int angkatan;
  long int nilai;
};

class mahaSiswa{
  public:
    void tambahMahasiswa(vector<Mahasiswa> &data);
    void simpanDataMahasiswa(vector <Mahasiswa> &data);
    void daftarMahasiswa(vector <Mahasiswa> &data);
    void caridataMahasiswa(vector <Mahasiswa> &data);
    void sortingNilaiTerkecil(vector <Mahasiswa> &data);
    void sortingNilaiTerbesar(vector <Mahasiswa> &data);
    void nilaiLulus(vector <Mahasiswa> &data);
    void nilaiTidakLulus(vector <Mahasiswa> &data);
  private:
};

void mahaSiswa::tambahMahasiswa(vector<Mahasiswa> &data){
  Mahasiswa Msiswa;
  cout << "Masukkan nama mahaiswa : ";
  getline(cin, Msiswa.nama);
  cout << "Masukkan NIM mahasiswa : ";
  getline(cin, Msiswa.nim);
  cout << "Masukkan angkatan mahasiswa : ";
  cin.ignore();
  cin >> Msiswa.angkatan;
  cout << "Masukkan nilai mahasiswa : ";
  cin >> Msiswa.nilai;
  cout << endl;
  data.push_back(Msiswa);
  cout << "Data berhasil disimpan" << endl;
  cout << endl;
}

void mahaSiswa::simpanDataMahasiswa(vector<Mahasiswa> &data){
  ofstream file("data_mahasiswa.txt");
  if (file.is_open()){
    for (int i = 0; i < data.size(); i++){
      file << "=========================================" << endl;
       file << "Nama Mahasiswa : " << data[i].nama << endl;
       file << "NIM Mahasiswa : " << data[i].nim << endl;
       file << "Angkatan Mahasiswa : " << data[i].angkatan << endl;
       file << "Nilai Mahasiswa : " << data[i].nilai << endl;
      file << "=========================================" << endl;
       file << endl;
    } 
    file.close();
    cout << "Data masuk txt" << endl;
    cout << endl;
  }
  if(!file){
    cout << "data tidak masuk txt" << endl;
  }
}

void mahaSiswa::daftarMahasiswa(vector<Mahasiswa> &data){
  cout << "Daftar Mahasiswa: " << endl;
  for (int i = 0; i < data.size(); i++){
    cout << "Nama mahasiswa : " << data[i].nama << endl;
    cout << "NIM : " << data[i].nim << endl;
    cout << "Angkatan : " << data[i].angkatan << endl;
    cout << "Nilai : " << data[i].nilai << endl;
    cout << endl;
  }
}

 void mahaSiswa::caridataMahasiswa(vector<Mahasiswa> &data){
   string namaMahasiswa;
   cout << "Masukkan nama Mahasiswa yang ingin dicari: ";
   cin.ignore();  
   getline(cin, namaMahasiswa);

   bool ditemukan = false;
    for (int i = 0; i < data.size(); i++){
      if(data[i].nama == namaMahasiswa){
        cout << "Mahasiswa ditemukan :" << endl;
        cout << "Nama mahasiswa   : " << data[i].nama << endl;
        cout << "NIM    : " << data[i].nim << endl;
        cout << "Angkatan     : " << data[i].angkatan << endl;
        cout << "Nilai : " << data[i].nilai << endl;
        ditemukan = true;
        break;
      }
    }
   if(!ditemukan){
     cout << "Mahasiwa tidak ditemukan" << endl;
   }
 }

bool bandingNilaiTertinggi(const Mahasiswa &a, const Mahasiswa &b){
  return a.nilai > b.nilai;
}

void mahaSiswa::sortingNilaiTerbesar(vector<Mahasiswa> &data){
  sort(data.begin(), data.end(), bandingNilaiTertinggi);
  cout << "Daftar Nilai tertinggi:" << endl;
  for (int i = 0; i < data.size(); i++) {
    cout << "Nama mahasiswa   : " << data[i].nama << endl;
    cout << "NIM    : " << data[i].nim << endl;
    cout << "Angkatan     : " << data[i].angkatan << endl;
    cout << "Nilai : " << data[i].nilai << endl;
    cout << endl;
  }
}

bool bandingNilaiTerendah(const Mahasiswa &a, const Mahasiswa &b) {
  return a.nilai < b.nilai;
}

void mahaSiswa::sortingNilaiTerkecil(vector<Mahasiswa> &data) {
  sort(data.begin(), data.end(), bandingNilaiTerendah);
  cout << "Daftar Nilai terendah:" << endl;
  for (int i = 0; i < data.size(); i++) {
    cout << "Nama mahasiswa   : " << data[i].nama << endl;
    cout << "NIM    : " << data[i].nim << endl;
    cout << "Angkatan     : " << data[i].angkatan << endl;
    cout << "Nilai : " << data[i].nilai << endl;
    cout << endl;
  }
}

void mahaSiswa::nilaiLulus(vector<Mahasiswa> &data){
  ofstream file("data_lulus.txt");
  if (file.is_open()){
  for (int i = 0; i < data.size(); i++) {
    if(data[i].nilai >= 75){
      cout << "Nama mahasiswa   : " << data[i].nama << endl;
      cout << "NIM    : " << data[i].nim << endl;
      cout << "Angkatan     : " << data[i].angkatan << endl;
      cout << "Nilai : " << data[i].nilai << endl;
      cout << endl;
      }
    }
    file.close();
    cout << "data berhasil disimpan" << endl;
    cout << endl;
  }
}

void mahaSiswa::nilaiTidakLulus(vector<Mahasiswa> &data){
  ofstream file("data_tidak_lulus.txt");
  if (file.is_open()){
  for (int i = 0; i < data.size(); i++) {
    if(data[i].nilai < 75){
      cout << "Nama mahasiswa   : " << data[i].nama << endl;
      cout << "NIM    : " << data[i].nim << endl;
      cout << "Angkatan     : " << data[i].angkatan << endl;
      cout << "Nilai : " << data[i].nilai << endl;
      cout << endl;
      }
    }
    file.close();
    cout << "data berhasil disimpan" << endl;
    cout << endl;
  }
}

int main(){
  vector<Mahasiswa> data;
  mahaSiswa m;
  int pil;

  do{
    cout << "Fitur - fitur yang dapat dilakukan : " << endl;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Daftar Mahasiswa" << endl;
    cout << "3. Cari Data Mahasiswa" << endl;
    cout << "4. Sorting Nilai Mahasiswa terbesar" << endl;
    cout << "5. Sorting Nilai Mahasiswa terkecil" << endl;
    cout << "6. Nilai yang lulus" << endl;
    cout << "7. Nilai yang tidak lulus" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pil;
    cin.ignore();
    cout << endl;

    switch(pil){
      case 1:
        m.tambahMahasiswa(data);
        m.simpanDataMahasiswa(data);
      break;

      case 2:
        m.daftarMahasiswa(data);
      break;

      case 3:
        m.caridataMahasiswa(data);
      break;

      case 4:
        m.sortingNilaiTerbesar(data);
      break;

      case 5:
        m.sortingNilaiTerkecil(data);
      break;

      case 6:
        m.nilaiLulus(data);
      break;

      case 7:
        m.nilaiTidakLulus(data);
      break;

      case 8:
      cout << "Terimakasih" << endl;
      break;
    }
  } while(pil != 8);
}
