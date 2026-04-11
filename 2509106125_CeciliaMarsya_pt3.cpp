#include <iostream>
using namespace std;

#define MAX 100

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

Hewan dataHewan[100];
int jumlah = 0;

Hewan queue[MAX];
int front = -1, rear = -1;

Hewan stack[MAX];
int top = -1;


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


void enqueue(Hewan *h) {
    if (rear == MAX - 1) {
        cout << "Queue overflow!\n";
        return;
    }
    if (front == -1) front = 0;

    rear++;
    queue[rear] = *h; 
    cout << "Masuk antrian: " << h->nama << endl;
}

Hewan dequeue() {
    Hewan kosong;
    kosong.id = -1;

    if (front == -1 || front > rear) {
        cout << "Queue underflow!\n";
        return kosong;
    }

    Hewan h = queue[front];
    front++;

    if (front > rear) front = rear = -1;

    cout << "Dipanggil: " << h.nama << " (ID: " << h.id << ")\n";
    return h;
}

void tampilAntrian() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    Hewan *ptr = &queue[front];

    for (int i = front; i <= rear; i++) {
        cout << ptr->nama << " (ID: " << ptr->id << ")\n";
        ptr++;
    }
}


void push(Hewan h) {
    if (top == MAX - 1) {
        cout << "Stack overflow!\n";
        return;
    }
    top++;
    stack[top] = h;
}

void pop() {
    if (top < 0) {
        cout << "Stack underflow!\n";
        return;
    }
    cout << "Hapus riwayat: " << stack[top].nama << endl;
    top--;
}

void tampilRiwayat() {
    if (top < 0) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    Hewan *ptr = stack;

    for (int i = 0; i <= top; i++) {
        cout << ptr->nama << " (ID: " << ptr->id << ")\n";
        ptr++;
    }
}

void peek() {
    if (front != -1 && front <= rear)
        cout << "Antrian depan: " << queue[front].nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top >= 0)
        cout << "Riwayat terakhir: " << stack[top].nama << endl;
    else
        cout << "Riwayat kosong\n";
}


int main() {
    int pilih;

    do {
        cout << "\n=== MENU PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Masuk Antrian\n";
        cout << "4. Panggil Pasien\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "7. Pop Riwayat\n";
        cout << "8. Peek\n";
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
            int idx;
            cout << "Masukkan index hewan: ";
            cin >> idx;

            if (idx >= 0 && idx < jumlah)
                enqueue(&dataHewan[idx]);
            else
                cout << "Index tidak valid\n";
        }
        else if (pilih == 4) {
            Hewan h = dequeue();
            if (h.id != -1)
                push(h);
        }
        else if (pilih == 5) {
            tampilAntrian();
        }
        else if (pilih == 6) {
            tampilRiwayat();
        }
        else if (pilih == 7) {
            pop();
        }
        else if (pilih == 8) {
            peek();
        }

    } while (pilih != 0);

    return 0;
}