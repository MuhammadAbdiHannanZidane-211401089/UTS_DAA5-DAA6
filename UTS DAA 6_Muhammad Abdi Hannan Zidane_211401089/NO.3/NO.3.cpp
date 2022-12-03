#include <iostream>
using namespace std;

// struktur data dinamis
bool exit1;
int nim, nilai, ans, n, total = 0;
string nama;
char kom;

struct Node { //deklarasi node linkedlist
    int nim;
    string nama;
    char kom;
    int nilai;

    struct Node* next;
};
struct Node* head = NULL; //head kosong

//struktur data statis
int jumlahMahasiswa = 0;
int start = 0;
int n2, total2;

struct dataMahasiswa {
    int nim;
    string nama;
    char kom;
    int nilai;
};

struct dataMahasiswa MHS[150];

//data dinamis
struct Node* swap(struct Node* ptr1, struct Node* ptr2) { //swap node
    struct Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void bubbleDinamis(struct Node** head, int count) {
    struct Node** h;
    int i, j;

    for (int i = 0; i <= count; i++) {
        h = head;

        for (int j = 0; j < count - i - 1; j++) {
            struct Node* p1 = *h;
            struct Node* p2 = p1->next;

            if (p1->nilai < p2->nilai) {
                *h = swap(p1, p2);
            }
            h = &(*h)->next;
        }
    }
}

void append(struct Node** head, int node_nim, string node_nama, char node_kom, int node_nilai) {

    struct Node* newNode = new Node; // membuat node baru
    struct Node* last = *head;

    newNode->nim = node_nim;
    newNode->nama = node_nama;
    newNode->kom = node_kom;
    newNode->nilai = node_nilai;

    newNode->next = NULL;

    if (*head == NULL) { //jika tidak ada node maka node yang dimasukkan akan menjadi kepala
        *head = newNode;
        return;
    }

    while (last->next != NULL) //membuat node baru ditambahkan ke paling belakang
        last = last->next;

    last->next = newNode;
    return;
}

void insert() {
    system("cls");
    cout << "Masukkan Jumlah data yang akan dimasukkan : ";
    cin >> n;
    total += n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke -" << i + 1 << ":\n";
        cout << "Masukkan NIM   : "; cin >> nim;
        cout << "Masukkan Nama  : "; cin >> nama;
        cout << "Masukkan KOM   : "; cin >> kom;
        cout << "Masukkan Nilai : "; cin >> nilai;
        cout << "\n";
        append(&head, nim, nama, kom, nilai);
    }
    return;
}

void deleteData(struct Node* Node, int n) {
    struct Node* a = Node;
    struct Node* b;
    for (int i = 1; i < n - 1; i++) {
        a = a->next;
    }
    b = a;
    a = a->next;
    b->next = a->next;
    total--;
    delete a;
}

void deleteText() {
    int urutan;
    cout << "Masukkan data ke berapa yang ingin dihapus : ";
    cin >> urutan;

    deleteData(head, urutan);
}

void displayList(struct Node* node) {
    system("cls");
    int i = 1;
    while (node != NULL) { //selama masih ada node maka akan ditampilkan
        cout << "Peringkat ke-" << i << "\n";
        cout << "NIM    : " << node->nim << "\n";
        cout << "Nama   : " << node->nama << "\n";
        cout << "KOM    : " << node->kom << "\n";
        cout << "Nilai  : " << node->nilai << "\n";
        cout << "\n";
        node = node->next; //ke node selanjutnya
        i++;
    }
}

void optionDinamis() {
    int pil1;
    system("cls");
    cout << "1. Sebelum di sortir\n";
    cout << "2. Setelah di sortir\n";
    cin >> pil1;

    switch (pil1) {
    case 1:displayList(head);
        system("pause");
        break;
    case 2:bubbleDinamis(&head, total);
        displayList(head);
        system("pause");
        break;
    }
}

void dataDinamis() {
    int ans1;
    bool exit2;

    do {
        system("cls");
        cout << "1. Masukkan data\n";
        cout << "2. Hapus data\n";
        cout << "3. Tampilkan data\n";
        cout << "4. Exit\n";
        cin >> ans1;

        switch (ans1) {
        case 1: insert();
            break;
        case 2: deleteText();
            break;
        case 3: optionDinamis();
            break;
        case 4: return;
        }
    } while (exit2 = true);

}
//statis

void swapStatis(struct dataMahasiswa* a, struct dataMahasiswa* b) {
    struct dataMahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

void selectionStatis(struct dataMahasiswa a[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {

        int m = i;
        for (j = i + 1; j < n; j++)
            if (a[j].nilai > a[m].nilai)
                m = j;

        if (m != i)
            swapStatis(&a[m], &a[i]);
    }
}

void addNewStatis() {
    cout << "Jumlah data yang ingin dimasukkan : ";
    cin >> n2;
    total2 += n2;

    for (int i = start; i < total2; i++) {
        cout << "Isilah data-data berikut !" << endl;
        cout << "Masukkan NIM   : "; cin >> MHS[i].nim;
        cout << "Masukkan Nama  : "; cin >> MHS[i].nama;
        cout << "Masukkan KOM   : "; cin >> MHS[i].kom;
        cout << "Masukkan Nilai : "; cin >> MHS[i].nilai;
        cout << "\n";
    }
    start += n2;
}

void readStatis() {
    system("cls");
    for (int i = 0; i < total2; i++) {
        cout << "\nPeringkat ke-" << i + 1 << " : ";
        cout << "\nNIM    :" << MHS[i].nim;
        cout << "\nNama   :" << MHS[i].nama;
        cout << "\nKOM    :" << MHS[i].kom;
        cout << "\nNilai  :" << MHS[i].nilai;
        cout << "\n";
    }

}

void dataStatis() {
    int ans2;
    bool exit3;

    do {
        system("cls");
        cout << "1. Masukkan Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. exit\n";
        cin >> ans2;

        switch (ans2) {
        case 1: addNewStatis();
            break;
        case 2: selectionStatis(MHS, total2);
            readStatis();
            system("pause");
            break;
        case 3: return;
        }
    } while (exit3 = true);
}

int main() {
    int pil;
    do {
        system("cls");
        cout << "1. Data Dinamis \n";
        cout << "2. Data Statis \n";
        cout << "3. Exit \n";
        cin >> pil;

        switch (pil) {
        case 1: dataDinamis();
            break;
        case 2: dataStatis();
            break;
        case 3: exit1 = false;
        }
    } while (exit1 = true);
}