#include<iostream>
#include<fstream>
#include<iomanip>
#include"telefonKayit.h"
#pragma once
using namespace std;
int telefonKayit::sayac = 0;
void telefonKayit::setIsim() {
	cout << "Isim:" << endl;
	cin >> ad;
}
void telefonKayit::setSoyad() {
	cout << "Soyisim:" << endl;
	cin >> soyad;
}
void telefonKayit::setCepTel() {
	cout << "Cep telefonu:" << endl;
	cin >> cepTel;
}
void telefonKayit::setIsTel() {
	cout << "Is telefonu:" << endl;
	cin >> isTel;
}
void telefonKayit::kisiEkle() {
	system("cls");
	setIsim();
	setSoyad();
	setCepTel();
	setIsTel();
	sayac++;
	ID = sayac;
}

string telefonKayit::getAd() {
	return ad;
}
string telefonKayit::getSoyad() {
	return soyad;
}
unsigned long long int telefonKayit::getCepTel() {
	return cepTel;
}
unsigned long long int telefonKayit::getIsTel() {
	return isTel;
}
int telefonKayit::getID() {
	return ID;
}