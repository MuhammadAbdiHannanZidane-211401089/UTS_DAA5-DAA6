#include <iostream>

using namespace std;

int stack[100], opsi, n, x, i;
int head = -1;

void push();
void pop();
void display();
void menu();

int main()
{
    cout << "         SELAMAT DATANG DI PROGRAM STACK" << endl;
    cout << "+============================================+" << endl;
    cout << " Masukkan Jumlah Data Pada Stack [MAX = 100]: ";
    cin >> n;
    cout << "+============================================+" << endl;
    menu();

    do
    {
        cout << "Masukkan Opsi Anda: ";
        cin >> opsi;
        switch (opsi)
        {
        case 1:
        {
            system("cls");
            push();
            system("pause");
            menu();
            break;
        }

        case 2:
        {
            system("cls");
            pop();
            system("pause");
            menu();
            break;
        }

        case 3:
        {
            system("cls");
            display();
            system("pause");
            menu();
            break;
        }

        case 4:
        {
            system("cls");
            cout << "Sampai Jumpa Lagi!!";
            break;
        }

        default:
            cout << "Input Anda Salah!, Masukkan Pilihan (1/2/3/4)";
            break;
        }
    } while (opsi != 4);

    return 0;
}

void push()
{

    if (head >= n - 1)
    {
        cout << "Stack Sudah Penuh" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Masukkan Angka Yang Ingin Di Masukkan Ke Dalam Stack: ";
            cin >> x;
            head++;
            stack[head] = x;
        }
    }
}

void pop()
{

    if (head <= -1)
    {
        cout << "Stack Anda Kosong" << endl;
    }
    else
    {
        cout << "Data Yang Terhapus adalah ";
        cout << stack[head] << endl;
        head--;
    }
}

void display()
{

    if (head >= 0)
    {
        cout << " Data Pada Stack Anda" << endl;
        cout << "+--------------------+" << endl;
        for (int i = head; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
    else
    {
        cout << "Stack Anda Kosong!!!";
    }
}

void menu()
{
    system("cls");

    cout << "+--------------------------------------------+" << endl;
    cout << "         Stack Menggunakan Array" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << " 1. Tambah Data" << endl;
    cout << " 2. Hapus Data" << endl;
    cout << " 3. Tampilkan Data" << endl;
    cout << " 4. Exit" << endl;
    cout << "+--------------------------------------------+" << endl;
}