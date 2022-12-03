#include <iostream>
#include <conio.h>

using namespace std;

int main () {

    string nama[255];
    int n,nim[255];
    int data_filled = 0;
    
    cout << "  Input Total Mahasiswa : "; cin >> n;
    
    {

            data_filled = 1;
            for (int i = 0; i < n; i++) {
                cout << "Mahasiswa Ke - " << i+1 << endl;
                cin.ignore();
                cout << "Nama       : "; getline(cin, nama[i]);
                cout << "NIM        : "; cin >> nim[i];
            }

            for (int i = 0; i < n - 1 ; i++){
                for (int j = 0; j < n - 1 ; j++){
                    if (nim[j] > nim[j + 1]){
                        swap (nama[j], nama[j + 1]);
                        swap (nim[j], nim[j + 1]);
                    }
                }
            }
{
            if (data_filled == 1) {
                cout << "\nUrutan Data Mahasiswa(ascending)\n";
                for(int i = 0; i<n; i++) {
                    cout << "\n[" << i+1 << "]. Nama    : " << nama[i] << "\n     NIM     : " << nim[i] << endl;
                }
            }
}
}
}