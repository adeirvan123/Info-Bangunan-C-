#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct rectangle {
	int length;
	int width;
};

struct person {
	string name;
	int age;
};

struct info {
	person pemilik;
	rectangle bangunan;
};

info infoBangunan[100];//untuk case 1..agar hasil tersimpan, tidak langsung hilang (tersimpan dalam array) tiap indek 
					   //menyimpan nilai yg dimasukkan ke fungsi ( info infoBangunan() ) 
int banyakBangunan = 0;//sebagai index pada array infoBangunan[100]

info tambahBangunan() {//scope blok maka perlu didefiniskan lagi type data variabelnya
	string name;
	int age, length, width;
	//angka yang dimasukkan ke struct lewat var struct scope blok akan mempunyai nilai yg sama dengan struct yg scopenya global
	//dan bisa diambil oleh struct var blok lain (dengan type struct yg sama) 
	info infoBaru;
	
	cout<<"Input nama Pemilik : ";
	cin>> name;
	
	cout<<"Input umur pemilik : ";
	cin>> age;
	
	cout<<"Input lebar bangunan : ";
	cin>> width;
	
	cout<<"Input Panjang bangunan : ";
	cin>> length;
	

	infoBaru.pemilik.name = name;
	infoBaru.pemilik.age = age;
	infoBaru.bangunan.width = width;
	infoBaru.bangunan.length = length;
	//nilai tadi dimasukkan ke infoBaru (struct info)
	return infoBaru;	
}

void lihatBangunan () {
	//menampilkan nilai pada opsi ke 2. lihat bangunan dengan loop
	for (int i = 0; i<banyakBangunan; i++) {
		info bangunan = infoBangunan[i];
		cout<<i+1<<". "<<bangunan.pemilik.name<<" berumur "<<bangunan.pemilik.age<<" memiliki luas bangunan "<<bangunan.bangunan.length*bangunan.bangunan.width<<endl;
	}
}

int main () {
	int input = 0;
	
	do {
		cout<<"1. Tambah Bangunan"<<endl;
		cout<<"2. Lihat Bangunan"<<endl;
		cout<<"3. Exit"<<endl;
		cin>>input;
		cout<<endl;
		switch(input) {
			case 1:
				infoBangunan[banyakBangunan] = tambahBangunan();
				banyakBangunan++;
				break;
			case 2:
				lihatBangunan();
				getch();
				break;
		}
		system("cls");
	}while(input !=3 );
}
