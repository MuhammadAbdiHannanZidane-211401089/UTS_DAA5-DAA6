#include <iostream>

using namespace std;

int queue[100], opsi, depan, blkg, i, x = 100, y, m;

void menu();
void push();
void pop();
void display();

int main()
{
    cout << "         SELAMAT DATANG DI PROGRAM QUEUE" << endl;
    cout << "+============================================+" << endl;
    cout << " Masukkan Jumlah Data Pada Queue [MAX = 100]: ";
    cin >> y;
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
}

void menu()
{
    system("cls");

    cout << "+--------------------------------------------+" << endl;
    cout << "         Queue Menggunakan Array" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << " 1. Tambah Data" << endl;
    cout << " 2. Hapus Data" << endl;
    cout << " 3. Tampilkan Data" << endl;
    cout << " 4. Exit" << endl;
    cout << "+--------------------------------------------+" << endl;
}

void push()
{

    if (blkg == x)
    {
        cout << "Queue Sudah Penuh" << endl;
    }
    else
    {
        for (int i = 0; i < y; i++)
        {
            cout << "Masukkan Angka Yang Ingin Di Masukkan Ke Dalam Queue: ";
            cin >> queue[blkg++];
        }
    }
}

void pop()
{
    if (depan == blkg)
    {
        cout << "Queue Anda Kosong!!!";
    }
    else
    {
        cout << "Data Yang Dihapus Adalah: ";
        cout << queue[depan++];
        x++;
        cout << endl;
    }
}

void display()
{
    cout << "Data Pada Queue Anda Adalah: " << endl;
    if (depan == blkg)
    {
        cout << "Queue Anda Kosong!!!" << endl;
    }
    else
    {
        for (int i = depan; i < blkg; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}