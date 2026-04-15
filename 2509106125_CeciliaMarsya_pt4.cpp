#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
    Hewan* next; // pointer ke node berikutnya
};

Hewan* dataHead = NULL;

Hewan* front = NULL;
Hewan* rear = NULL;

Hewan* top = NULL;

void tambahData() {
    Hewan* baru = new Hewan();

    cout << "\nTambah Data Hewan\n";
    cout << "ID: "; cin >> baru->id;
    cout << "Nama: "; cin >> baru->nama;
    cout << "Jenis: "; cin >> baru->jenis;
    cout << "Harga: "; cin >> baru->harga;

    baru->next = NULL;

    if (dataHead == NULL)
        dataHead = baru;
    else {
        Hewan* temp = dataHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }
}

void tampilData() {
    if (dataHead == NULL) {
        cout << "Data kosong\n";
        return;
    }

    Hewan* temp = dataHead;
    cout << "\n=== DATA HEWAN ===\n";
    int i = 0;
    while (temp != NULL) {
        cout << i++ << ". " << temp->nama << " (ID: " << temp->id << ")\n";
        temp = temp->next;
    }
}

void enqueue(Hewan* h) {
    Hewan* baru = new Hewan(*h);
    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Masuk antrian: " << h->nama << endl;
}

Hewan* dequeue() {
    if (front == NULL) {
        cout << "Queue kosong (underflow)\n";
        return NULL;
    }

    Hewan* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    cout << "Dipanggil: " << temp->nama << endl;
    return temp;
}

void tampilAntrian() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Hewan* temp = front;
    cout << "\n=== ANTRIAN ===\n";
    while (temp != NULL) {
        cout << temp->nama << " (ID: " << temp->id << ")\n";
        temp = temp->next;
    }
}

void push(Hewan* h) {
    Hewan* baru = new Hewan(*h);
    baru->next = top;
    top = baru;
}

void pop() {
    if (top == NULL) {
        cout << "Stack kosong (underflow)\n";
        return;
    }

    Hewan* temp = top;
    cout << "Hapus riwayat: " << temp->nama << endl;

    top = top->next;
    delete temp;
}

void tampilRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Hewan* temp = top;
    cout << "\n=== RIWAYAT ===\n";
    while (temp != NULL) {
        cout << temp->nama << " (ID: " << temp->id << ")\n";
        temp = temp->next;
    }
}

void peek() {
    if (front != NULL)
        cout << "Antrian depan: " << front->nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top != NULL)
        cout << "Riwayat terakhir: " << top->nama << endl;
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
            tampilData();
        }
        else if (pilih == 2) {
            tambahData();
        }
        else if (pilih == 3) {
            int idx;
            cout << "Masukkan index hewan: ";
            cin >> idx;

            Hewan* temp = dataHead;
            int i = 0;

            while (temp != NULL && i < idx) {
                temp = temp->next;
                i++;
            }

            if (temp != NULL)
                enqueue(temp);
            else
                cout << "Index tidak valid\n";
        }
        else if (pilih == 4) {
            Hewan* h = dequeue();
            if (h != NULL)
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