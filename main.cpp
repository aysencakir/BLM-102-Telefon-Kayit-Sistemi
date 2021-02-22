#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include <algorithm>
#include"telefonKayit.h"
#pragma once
using namespace std;
int main() {
	telefonKayit tel[100];
	fstream dosya;
	static int kisiSayisi = 0;
	char ch;
	int num;

	do
	{
		system("cls");
		cout << "Yapmak istediginiz islemi seciniz!" << endl;
		cout << endl;
		cout << "*************" << endl;
		cout << "1. Kayit Ekleme" << endl;
		cout << "2. Kayitlari Gosterme" << endl;
		cout << "3. Kayit Arama" << endl;;
		cout << "4. Kayit Modifiye Etme" << endl;;
		cout << "5. Kayit Silme" << endl;;
		cout << "6. Cikis" << endl;;
		cout << "*************" << endl;
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1': {
			tel[kisiSayisi].kisiEkle();
			cout << "\n\nKayit olusturuldu.Ana ekrana donmek icin herhangi bir tusa basiniz.";
			cin.ignore();
			cin.get();
			kisiSayisi++;
			break; }
		case '2': {
			vector <string> deneme;
			string t;
			string yedek2;
			for (int i = 0; i < kisiSayisi; i++) {
				t = tel[i].getAd();
				for (int j = 0; j < t.size(); j++) {
					t[j] = tolower(t[j]);
				}
				deneme.push_back(t);
			}
			sort(deneme.begin(), deneme.end());
			for (int i = 0; i < kisiSayisi; i++) {
				int top = 0;
				for (int i2 = 0; i2 < deneme[i].size(); i2++) {
					top = top + (int)deneme[i].at(i2);
				}
				for (int j = 0; j < kisiSayisi; j++) {
					int top2 = 0;
					yedek2 = tel[j].getAd();
					for (int j1 = 0; j1 < yedek2.size(); j1++) {
						top2 = top2 + (int)yedek2.at(j1);
					}
					if (abs(top - top2) % 32 == 0) {
						cout << "************" << endl;
						cout << "ID:" << tel[j].getID() << endl;
						cout << "Isim:" << tel[j].getAd() << endl;
						cout << "Soyisim:" << tel[j].getSoyad() << endl;
						cout << "Cep Telefonu:" << tel[j].getCepTel() << endl;
						cout << "Is Telefonu:" << tel[j].getIsTel() << endl;
						cout << "************" << endl;
						cout << endl;

					}
				}
			}
			cout << "\n\nKayit gosterildi.Ana ekrana donmek icin herhangi bir tusa basiniz.";
			cin.ignore();
			cin.get();
			break; }

		case '3': {aramaM:
			cout << "\n\tArama turunu seciniz" << endl;
			cout << "1.ID ile arama" << endl << "2.Isimle arama" << endl << "3.Soyadla arama" << endl << "4.Cep telefonuyla arama" << endl << "5.Is telefonuyla arama" << endl << "6.Ana menuye geri don" << endl;
			cin >> num;
			switch (num) {
			case(1):
			{
			IDAM:
				int aranacakID;

				cout << "Aramak istediginiz ID'yi giriniz:" << endl;
				cin >> aranacakID;
				int i;
				for (i = 0; i < kisiSayisi; i++) {
					if (aranacakID == tel[i].getID()) {
						cout << "ID:" << tel[i].getID() << endl;
						cout << "Isim:" << tel[i].getAd() << endl;
						cout << "Soyisim:" << tel[i].getSoyad() << endl;
						cout << "Cep Telefonu:" << tel[i].getCepTel() << endl;
						cout << "Is Telefonu:" << tel[i].getIsTel() << endl;
						cout << "\n\nAranan kisi bulundu.";

						break;
					}
				}
				if (i == kisiSayisi) {
				hata1:
					int i1;
					cout << "\aAranan ID bulunamadi" << endl << "1.Ana menuye geri donun" << endl << "2.Arama menusune geri donun" << endl << "3.ID arama menusune geri donun" << endl << "4.Cikis" << endl;
					cin >> i1;
					if (i1 == 1) {
						break;
					}
					else if (i1 == 2) {
						goto aramaM;
					}
					else if (i1 == 3) {
						goto IDAM;
					}
					else if (i1 == 4) {
						goto cikis;
					}
					else {
						cout << "\aHatali giris, tekrar deneyiniz!" << endl;
						cin.ignore();
						cin.get();
						goto hata1;
					}
				}
				else {
					cout << "Ana ekrana geri donmek icin herhangi bir tusa basiniz." << endl;
					cin.ignore();
					cin.get();
					break;
				}
			}
			case(2): {AAM:
			string aranacakAd;
			string olanAd;
			cout << "Aramak istediginiz ismi giriniz:" << endl;
			cin >> aranacakAd;
			int aranacakAdTop = 0;
			int olanAdTop = 0;
			for (int j = 0; j < aranacakAd.size(); j++) {
				aranacakAdTop = aranacakAdTop + (int)aranacakAd.at(j);
			}
			int i;
			for (i = 0; i < kisiSayisi; i++) {
				olanAd = tel[i].getAd();
				for (int j = 0; j < olanAd.size(); j++) {
					olanAdTop = olanAdTop + (int)olanAd.at(j);
				}
				if (abs(olanAdTop - aranacakAdTop) % 32 == 0) {
					cout << "ID:" << tel[i].getID() << endl;
					cout << "Isim:" << tel[i].getAd() << endl;
					cout << "Soyisim:" << tel[i].getSoyad() << endl;
					cout << "Cep Telefonu:" << tel[i].getCepTel() << endl;
					cout << "Is Telefonu:" << tel[i].getIsTel() << endl;
					cout << "\n\nAranan kisi bulundu.";

					break;
				}
				olanAdTop = 0;
			}
			if (i == kisiSayisi) {
			hata2:
				int i1;
				cout << "\aAranan ad bulunamadi" << endl << "1.Ana menuye geri donun" << endl << "2.Arama menusune geri donun" << endl << "3.Ad arama menusune geri donun" << endl << "4.Cikis" << endl;
				cin >> i1;
				if (i1 == 1) {
					break;
				}
				else if (i1 == 2) {
					goto aramaM;
				}
				else if (i1 == 3) {
					goto AAM;
				}
				else if (i1 == 4) {
					goto cikis;
				}
				else {
					cout << "\aHatali giris, tekrar deneyiniz!" << endl;
					cin.ignore();
					cin.get();
					goto hata2;
				}

			}
			else {
				cout << "Ana ekrana geri donmek icin herhangi bir tusa basiniz." << endl;
				cin.ignore();
				cin.get();
				break;
			}

			}
			case(3): {SAM:
			string aranacakSoyad;
			string olanSoyad;
			cout << "Aramak istediginiz soyadi giriniz:" << endl;
			cin >> aranacakSoyad;
			int aranacakSoyadTop = 0;
			int olanSoyadTop = 0;
			for (int j = 0; j < aranacakSoyad.size(); j++) {
				aranacakSoyadTop = aranacakSoyadTop + (int)aranacakSoyad.at(j);
			}
			int i;
			for (i = 0; i < kisiSayisi; i++) {
				olanSoyad = tel[i].getSoyad();
				for (int j = 0; j < olanSoyad.size(); j++) {
					olanSoyadTop = olanSoyadTop + (int)olanSoyad.at(j);
				}
				if (abs(olanSoyadTop - aranacakSoyadTop) % 32 == 0) {
					cout << "ID:" << tel[i].getID() << endl;
					cout << "Isim:" << tel[i].getAd() << endl;
					cout << "Soyisim:" << tel[i].getSoyad() << endl;
					cout << "Cep Telefonu:" << tel[i].getCepTel() << endl;
					cout << "Is Telefonu:" << tel[i].getIsTel() << endl;
					cout << "\n\nAranan kisi bulundu.";

					break;
				}
				olanSoyadTop = 0;
			}
			if (i == kisiSayisi) {
			hata3:
				int i1;
				cout << "\aAranan soyad bulunamadi" << endl << "1.Ana menuye geri donun" << endl << "2.Arama menusune geri donun" << endl << "3.Soyad arama menusune geri donun" << endl << "4.Cikis" << endl;
				cin >> i1;
				if (i1 == 1) {
					break;
				}
				else if (i1 == 2) {
					goto aramaM;
				}
				else if (i1 == 3) {
					goto SAM;
				}
				else if (i1 == 4) {
					goto cikis;
				}
				else {
					cout << "\aHatali giris, tekrar deneyiniz!" << endl;
					cin.ignore();
					cin.get();
					goto hata3;
				}

			}
			else {
				cout << "Ana ekrana geri donmek icin herhangi bir tusa basiniz." << endl;
				cin.ignore();
				cin.get();
				break;
			}

			}
			case(4): {CTAM:
			int aranacakCepTel;
			cout << "Aramak istediginiz cep telefonunu giriniz:" << endl;
			cin >> aranacakCepTel;
			int i;
			for (i = 0; i < kisiSayisi; i++) {
				if (aranacakCepTel == tel[i].getCepTel()) {
					cout << "ID:" << tel[i].getID() << endl;
					cout << "Isim:" << tel[i].getAd() << endl;
					cout << "Soyisim:" << tel[i].getSoyad() << endl;
					cout << "Cep Telefonu:" << tel[i].getCepTel() << endl;
					cout << "Is Telefonu:" << tel[i].getIsTel() << endl;
					cout << "\n\nAranan kisi bulundu.";

					break;
				}
			}
			if (i == kisiSayisi) {
			hata4:
				int i1;
				cout << "\aAranan cep telefonu bulunamadi" << endl << "1.Ana menuye geri donun" << endl << "2.Arama menusune geri donun" << endl << "3.Cep telefonu arama menusune geri donun" << endl << "4.Cikis" << endl;
				cin >> i1;
				if (i1 == 1) {
					break;
				}
				else if (i1 == 2) {
					goto aramaM;
				}
				else if (i1 == 3) {
					goto CTAM;
				}
				else if (i1 == 4) {
					goto cikis;
				}
				else {
					cout << "\aHatali giris, tekrar deneyiniz!" << endl;
					cin.ignore();
					cin.get();
					goto hata4;
				}

			}
			else {
				cout << "Ana ekrana geri donmek icin herhangi bir tusa basiniz." << endl;
				cin.ignore();
				cin.get();
				break;
			}
			}
			case(5): {ITAM:
			int aranacakIsTel;
			cout << "Aramak istediginiz is telefonunu giriniz:" << endl;
			cin >> aranacakIsTel;
			int i;
			for (i = 0; i < kisiSayisi; i++) {
				if (aranacakIsTel == tel[i].get?sTel()) {
					cout << "ID:" << tel[i].getID() << endl;
					cout << "Isim:" << tel[i].getAd() << endl;
					cout << "Soyisim:" << tel[i].getSoyad() << endl;
					cout << "Cep Telefonu:" << tel[i].getCepTel() << endl;
					cout << "Is Telefonu:" << tel[i].getIsTel() << endl;
					cout << "\n\nAranan kisi bulundu.";

					break;
				}
			}
			if (i == kisiSayisi) {
			hata5:
				int i1;
				cout << "\aAranan is telefonu bulunamadi" << endl << "1.Ana menuye geri donun" << endl << "2.Arama menusune geri donun" << endl << "3.?s telefonu arama menusune geri donun" << endl << "4.Cikis" << endl;
				cin >> i1;
				if (i1 == 1) {
					break;
				}
				else if (i1 == 2) {
					goto aramaM;
				}
				else if (i1 == 3) {
					goto ITAM;
				}
				else if (i1 == 4) {
					goto cikis;
				}
				else {
					cout << "\aHatali giris, tekrar deneyiniz!" << endl;
					cin.ignore();
					cin.get();
					goto hata5;
				}

			}
			else {
				cout << "Ana ekrana geri donmek icin herhangi bir tusa basiniz." << endl;
				cin.ignore();
				cin.get();
				break;
			}

			}
			case(6): {
				break;
			}

			}

			break;
			}
		case '4': {M:
			int ID2, i;
			cout << "Modifiye edilecek ID'i giriniz:" << endl;
			cin >> ID2;
			char s1, s2, s3, s4;
			int uyari = 0;
			for (i = 0; i < kisiSayisi; i++) {
				int IDvar = tel[i].getID();
				if (IDvar == ID2) {
					uyari = 1;
					break;
				}
			}
			if (uyari) {
			Name:
				cout << "Isim modifiye edilecek mi?(E/H)" << endl;
				cin >> s1;
				if (s1 == 'e' || s1 == 'E') {
					cout << "Yeni ";
					tel[i].setIsim();
				}
				else if (s1 == 'h' || s1 == 'H') {

				}
				else {
					cout << "\aHatali giris,tekrar deneyiniz!" << endl;
					goto Name;
				}

			Surname:
				cout << "Soyad modifiye edilecek mi?(E/H)" << endl;
				cin >> s2;
				if (s2 == 'e' || s2 == 'E') {
					cout << "Yeni ";
					tel[i].setSoyad();
				}
				else if (s2 == 'h' || s2 == 'H') {

				}
				else {
					cout << "\aHatali giris,tekrar deneyiniz!" << endl;
					goto Surname;
				}

			Phone1:
				cout << "Cep telefonu modifiye edilecek mi?(E/H)" << endl;
				cin >> s3;
				if (s3 == 'e' || s3 == 'E') {
					cout << "Yeni ";
					tel[i].setCepTel();
				}
				else if (s3 == 'h' || s3 == 'H') {

				}
				else {
					cout << "\aHatali giris,tekrar deneyiniz!" << endl;
					goto Phone1;
				}
			Phone2:
				cout << "Is telefonu modifiye edilecek mi?(E/H)" << endl;
				cin >> s4;
				if (s4 == 'e' || s4 == 'E') {
					cout << "Yeni ";
					tel[i].setIsTel();
				}
				else if (s4 == 'h' || s4 == 'H') {

				}
				else {
					cout << "\aHatali giris,tekrar deneyiniz!" << endl;
					goto Phone2;
				}
				uyari = 0;
			}
			if ((ID2 > kisiSayisi) || (i == kisiSayisi)) {
				cout << "\aHatali ID girisi,tekrar deneyiniz." << endl;
				cin.ignore();
				cin.get();
				goto M;
			}
			else {
				cout << "Kisi modifiye edilmistir!" << endl;
				cin.ignore();
				cin.get();

				break;

			}

			break; }
		case '5': {
		Sil:
			cout << "\n\tSilinecek ID: "; cin >> num;
			int uyar? = 0;
			int IDal;
			for (int k = 0; k < kisiSayisi; k++) {
				IDal = tel[k].getID();
				if (IDal == num) {
					uyar? = 1;
				}
			}
			if (uyar?) {

				for (int i = num - 1; i < kisiSayisi; i++) {
					tel[i] = tel[i + 1];
				}
				cout << "Kisi silinmistir!" << endl;

				cin.ignore();
				cin.get();
				kisiSayisi--;

			}
			else {
				system("cls");
				cout << "\aHatali ID girisi,tekrar deneyiniz!" << endl;
				goto Sil;
			}
			break;
		}
		case '6': {	cikis:
		dosya.open("telefonRehberi.txt");
		if (dosya.is_open()) {
			for (int i = 0; i < kisiSayisi; i++) {
				dosya << "********" << endl;
				dosya << "ID:" << tel[i].getID() << endl;
				dosya << "Isim:" << tel[i].getAd() << endl;
				dosya << "Soyisim:" << tel[i].getSoyad() << endl;
				dosya << "Cep Telefonu:" << tel[i].getCepTel() << endl;
				dosya << "Is Telefonu:" << tel[i].getIsTel() << endl;
				dosya << "********" << endl;
			}
		}
		else
			cout << "Dosya acilamadi" << endl;
		dosya.close();

		exit(0); }
		default:	cout << "\a";

		}
	} while (ch != '7');

	return 0;
}