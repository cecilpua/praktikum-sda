#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

Hewan dataHewan[100];
int jumlah = 0;

void swap(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Hewan *arr, int n) {
    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < n; i++) {
        Hewan *p = (arr + i); 
        cout << "ID: " << p->id
             << " | Nama: " << p->nama
             << " | Jenis: " << p->jenis
             << " | Harga: " << p->harga << endl;
    }
}


void tambah(Hewan *arr, int &n) { 
    cout << "\nTambah Data Hewan\n";
    cout << "ID: "; cin >> (arr + n)->id;
    cout << "Nama: "; cin >> (arr + n)->nama;
    cout << "Jenis: "; cin >> (arr + n)->jenis;
    cout << "Harga: "; cin >> (arr + n)->harga;
    n++;
}

void linearSearch(Hewan *arr, int n, string cari) {
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == cari) {
            cout << "Ditemukan di index " << i << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Data tidak ditemukan\n";
}

int fibonacciSearch(Hewan *arr, int n, int target) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    cout << "\nProses Fibonacci Search:\n";

    while (fib > 1) {
        int i = offset + fib2;
        if (i >= n) i = n - 1;

        cout << "Cek index " << i << " (ID: " << (arr + i)->id << ")\n";

        if ((arr + i)->id == target)
            return i;

        else if ((arr + i)->id < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    if (fib1 && (arr + offset + 1)->id == target)
        return offset + 1;

    return -1;
}

void bubbleSort(Hewan *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swap((arr + j), (arr + j + 1));
            }
        }
    }
}

void selectionSort(Hewan *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min)->harga) {
                min = j;
            }
        }
        swap((arr + i), (arr + min));
    }
}

int main() {
    int pilih;
    do {
        cout << "\n=== MENU PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Linear Search (Nama)\n";
        cout << "4. Fibonacci Search (ID)\n";
        cout << "5. Bubble Sort (Nama A-Z)\n";
        cout << "6. Selection Sort (Harga)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            tampil(dataHewan, jumlah);
        }
        else if (pilih == 2) {
            tambah(dataHewan, jumlah);
        }
        else if (pilih == 3) {
            string cari;
            cout << "Masukkan nama: ";
            cin >> cari;
            linearSearch(dataHewan, jumlah, cari);
        }
        else if (pilih == 4) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;

            int hasil = fibonacciSearch(dataHewan, jumlah, id);
            if (hasil != -1)
                cout << "Data ditemukan di index " << hasil << endl;
            else
                cout << "Data tidak ditemukan\n";
        }
        else if (pilih == 5) {
            bubbleSort(dataHewan, jumlah);
            cout << "Data berhasil diurutkan (Nama)\n";
        }
        else if (pilih == 6) {
            selectionSort(dataHewan, jumlah);
            cout << "Data berhasil diurutkan (Harga)\n";
        }

    } while (pilih != 0);

    return 0;
}

// update dikit