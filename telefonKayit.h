#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class telefonKayit
{
private:
	string ad;
	string soyad;
	unsigned long long int isTel;
	unsigned long long int cepTel;
	static int sayac;
	int ID;
public:
	void kisiEkle();
	void setIsim();
	void setSoyad();
	void setCepTel();
	void setIsTel();
	string getAd();
	string getSoyad();
	unsigned long long int getIsTel();
	unsigned long long int getCepTel();
	int getID();
};
