#include <iostream>
#include <vector>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string prodi;
    int semester;
};

vector<Mahasiswa> data;

// CREATE
void tambahData() {
    Mahasiswa m;
    cout << "\n=== Tambah Data Mahasiswa ===\n";
    cout << "NIM      : "; cin >> m.nim;
    cin.ignore();
    cout << "Nama     : "; getline(cin, m.nama);
    cout << "Prodi    : "; getline(cin, m.prodi);
    cout << "Semester : "; cin >> m.semester;

    data.push_back(m);
    cout << "Data berhasil ditambahkan!\n";
}

// READ
void tampilData() {
    cout << "\n=== Data Mahasiswa ===\n";
    if (data.empty()) {
        cout << "Data kosong!\n";
        return;
    }

    for (int i = 0; i < data.size(); i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "NIM      : " << data[i].nim << endl;
        cout << "Nama     : " << data[i].nama << endl;
        cout << "Prodi    : " << data[i].prodi << endl;
        cout << "Semester : " << data[i].semester << endl;
    }
}

// UPDATE
void updateData() {
    string nim;
    cout << "\nMasukkan NIM yang ingin diubah: ";
    cin >> nim;

    for (int i = 0; i < data.size(); i++) {
        if (data[i].nim == nim) {
            cin.ignore();
            cout << "Nama baru     : "; getline(cin, data[i].nama);
            cout << "Prodi baru    : "; getline(cin, data[i].prodi);
            cout << "Semester baru : "; cin >> data[i].semester;
            cout << "Data berhasil diupdate!\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";
}

// DELETE
void hapusData() {
    string nim;
    cout << "\nMasukkan NIM yang ingin dihapus: ";
    cin >> nim;

    for (int i = 0; i < data.size(); i++) {
        if (data[i].nim == nim) {
            data.erase(data.begin() + i);
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";
}

// MENU
void menu() {
    int pilih;
    do {
        cout << "\n===== SISTEM PERKULIAHAN =====\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Update Data Mahasiswa\n";
        cout << "4. Hapus Data Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahData(); break;
            case 2: tampilData(); break;
            case 3: updateData(); break;
            case 4: hapusData(); break;
            case 5: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);
}

int main() {
    menu();
    return 0;
}
