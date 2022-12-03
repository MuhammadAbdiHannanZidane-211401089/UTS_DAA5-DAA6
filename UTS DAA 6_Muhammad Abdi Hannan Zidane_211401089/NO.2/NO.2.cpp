#include <iostream>
#include <cstring>
using namespace std;

struct belanja{
	string nama;
    int harga, jumlah, total;
};
struct barang{
	int transaksi;
	belanja *nota;
};barang struk;

void bon(int tot){
	for (int i=0; i<tot; i++){
		cout<<"| "<<i+1<<". "<<struk.nota[i].nama<<" X "<<struk.nota[i].jumlah<<endl;
		cout<<"|    Harga Per Satuan 	: "<<struk.nota[i].harga<<endl;
		cout<<"|    Total		: "<<struk.nota[i].harga*struk.nota[i].jumlah<<endl;
	}
}

int main(){
	int total_all=0, total, bayar;
	
	
	cout<<"+=============================+"<<endl;
	cout<<"|      HYPERAKTIF MART        |"<<endl;
	cout<<"+=============================+"<<endl;
	
	cout<<"| Masukkan Total Transaksi : ";
	cin>>struk.transaksi;
	struk.nota=new belanja[struk.transaksi];
	for (int i=0; i<struk.transaksi; i++){
		cout<<"|"<<endl;
		cout<<"| Transaksi "<<i+1<<endl;
		cout<<"| Nama Barang	: ";cin>>struk.nota[i].nama;
		cout<<"| Harga Barang	: Rp. ";cin>>struk.nota[i].harga;
		cout<<"| Total Barang	: ";cin>>struk.nota[i].jumlah;
		total=struk.nota[i].jumlah*struk.nota[i].harga;
		total_all=total_all+total;
	}
	cout<<"+=======================================+"<<endl;
	system("pause");
	system("cls");
	
	cout<<"+==============================+"<<endl;
	cout<<"|      HYPERAKTIF MART         |"<<endl;
	cout<<"+==============================+"<<endl;
	bon(struk.transaksi);
	cout<<"+=======================================+"<<endl;
	cout<<"| Total Belanja	: ";cout<<total_all<<endl;
	cout<<"| Total Bayar	: ";cin>>bayar;
	cout<<"| Kembali	: "<<bayar-total_all<<endl;
	cout<<"+=======================================+"<<endl;
}