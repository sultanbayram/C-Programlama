/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2021-2022 YAZ DÖNEMİ
**
**				PROJE NUMARASI..........:1
**				ÖĞRENCİ ADI............:SULTAN BAYRAM
**				ÖĞRENCİ NUMARASI.......:S211210236
**                        DERSİN ALINDIĞI GRUP...:A
****************************************************************************/

#include <iostream>

#include<string>
#include <stdio.h>

#include<conio.h>
#include<fstream>//ofstream ve ifstream kullandigim kutuphane
#include<iomanip>
#include<windows.h>
#include <sstream> 

using namespace std;
using namespace std;
int secim, secim2, secim3, secim4, s_ekle, k = 0, i = 0;
char cevap;
class ogrenci
{
public:
	string Ogrenci_TC;
	string Ogrenci_Adi;
	string Ogrenci_Soyadi;					/*DEğişKENLER*/
	string Ogrenci_No;
	string Ogrenci_Sifre;

	void menu();
	void ogrenciekle();
	void ogrenciduzenle();					/*FONKSiYONLAR*/
	void ogrencisil();
	void ogrencilistele();
	void ogrencisorgula();
}o;
class soru
{
public:
	string Soru_adi;
	string Soru_detay;
	string Cevap_a;					/*DEğişKENLER*/
	string Cevap_b;
	string Cevap_c;
	string Cevap_d;
	string Cevap_e;
	string Dogru_cevap;
	string Zorluk;

	void menu();
	void soruekle();
	void soruduzenle();					/*FONKSiYONLAR*/
	void sorusil();
	void sorulistele();
	void sinavaekle();
	void sinavmenu();


}s;
void soru::sinavaekle() {
	system("cls");
	bool menuTekrar = false;
	string sinavAdi, sinavSuresi, tutucu, sinavSoru_adi;
	int soruSayisi;
	cout << "Sinav adini yaziniz\n";
	cin >> sinavAdi;
	cout << "Soru sayisini yaziniz\n";
	cin >> soruSayisi;
	cout << "Sinav suresini yaziniz\n";
	cin >> sinavSuresi;
	do {
		menuTekrar = false;
		cout << " - + - + - + Soru Listesi + - + - + -" << endl;
		ofstream ac("sinav.txt", ios::app);
		ac.close();
		ifstream DosyaOku("Soru.txt");
		while (!(DosyaOku.eof()))
		{
			DosyaOku >> Soru_adi >> Soru_detay >> Cevap_a >> Cevap_b >> Cevap_c >> Cevap_d >> Cevap_e >> Dogru_cevap >> Zorluk;
			cout << " _________________________________________" << endl << endl;
			cout << " Soru Adi :" << Soru_adi << endl;
			cout << " Soru Detay :" << Soru_detay << endl;
			cout << " cevap A  :" << Cevap_a << endl;
			cout << " cevap B  :" << Cevap_b << endl;
			cout << " cevap C  :" << Cevap_c << endl;
			cout << " cevap D  :" << Cevap_d << endl;
			cout << " cevap E  :" << Cevap_e << endl;
			cout << " Dogru cevap :" << Dogru_cevap << endl;
			cout << " Zorluk :" << Zorluk << endl;
			if (Soru_adi != "")
			{
				cout << "Soru Adi: " << Soru_adi << " - Soru Detay: " << Soru_detay << " - Zorluk:" << Zorluk << endl;//mevcut sorulari ekrana basiyorum
			}
		}

		DosyaOku.close();

		cout << "Sinavda olan sorularin Soru_adi lerini giriniz\n";
		for (int i = 0; i < soruSayisi; i++)//girilen soru sayisi kadar soru Soru_adisi girmesi icin donguyu ayarladim
		{
			bool kontrol = false;
			cin >> tutucu;
			ifstream oku2("Soru.txt", ios::in);
			while (!oku2.eof())
			{
				oku2 >> Soru_adi >> Soru_detay >> Cevap_a >> Cevap_b >> Cevap_c >> Cevap_d >> Cevap_e >> Dogru_cevap >> Zorluk;
				cout << " _________________________________________" << endl << endl;
				getline(oku2, Soru_adi);
				getline(oku2, Soru_detay);
				getline(oku2, Cevap_a);
				getline(oku2, Cevap_b);
				getline(oku2, Cevap_c);
				getline(oku2, Cevap_d);
				getline(oku2, Cevap_e);
				getline(oku2, Dogru_cevap);
				getline(oku2, Zorluk);

				if (Soru_adi == tutucu)//Soru_adi sorularda oldugu muddetce tutucu degiskeni ile tuttugum soru Soru_adisini kaydediyorum
				{
					kontrol = true;
				}
			}
			if (kontrol)
			{
				sinavSoru_adi += tutucu + " ";
			}
			if(kontrol=false)
			{
				sinavSoru_adi = "";
				system("cls");
				cout << "boyle bir Soru_adi bulunamadi lutfen bastan giriniz.\n";
				menuTekrar = true;
				break;
			}
			oku2.close();
		}
		if (!menuTekrar)
		{
			cout << "Sinav kaydedildi.\n";
			ofstream yaz("sinav.txt", ios::app);
			yaz << sinavAdi << endl << sinavSuresi << endl << soruSayisi << endl << sinavSoru_adi << endl;
			yaz.close();
			cout << " Cikmak Icin (H/h)" << endl
				<< " Menuye Gitmek Icin (M/m)";
			cout << endl << " Secim : ";
			cin >> cevap;
			if (cevap == 'h' || cevap == 'H')
				DosyaOku.close();
			else {
				system("cls");
				s.sinavmenu();
			}
		}
	} while (menuTekrar);
}

void ogrenci::menu()
{
	if (k == 1)
	{
		system("cls");            /*OGRENCi işLERi OTOMASYONU YAZSIN DiYE YAPILDI*/
	}
	do
	{
	devam:
		if (i != 0)
		{
			system("cls");
			cout << endl << " Yanlis secim !!!" << endl			/*YANLIş BiR SECiM YAPILINCA YENiDEN DENEMEK iCiN YAPILDI*/
				<< " Lutfen Yeniden Seciniz. " << endl << endl;
		}
		cout << " 1) Ogrenci Kayit Ekleme " << endl
			<< " 2) Ogrenci Kayit Duzenleme " << endl
			<< " 3) Ogrenci Kaydi Silme " << endl
			<< " 4) Ogrenci Listesi Alma " << endl
			<< " 5) Ogrenci Sorgulama " << endl
			<< " 6) Cikis " << endl

			<< "_________________________________________________" << endl;
		cout << endl << " Secim : ";
		cin >> secim;
		if (!(secim == 1 || secim == 2 || secim == 3 || secim == 4 || secim == 5 || secim == 6))
		{
			i++;					/*YANLIş SECiM YAPILINCA YUKARIDAKi iF'E GiDER*/
			goto devam;
		}
		k++;
	} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6);
}
void ogrenci::ogrenciekle()
{

	system("cls");
	cout << " - + - + - + Ogrenci ekleme + - + - + -" << endl
		<< " ___________________________________________" << endl;

	ofstream DosyaYaz;
	DosyaYaz.open("Ogrenci.txt", ios::app);

	do
	{
		system("cls");
		cout << "\n Ogrenci Tc No : ";
		cin >> Ogrenci_TC;
		cout << "\n Ogrenci Adi : ";
		cin >> Ogrenci_Adi;
		cout << "\n Ogrenci Soyadi : ";
		cin >> Ogrenci_Soyadi;
		cout << "\n Ogrenci Şifresi : ";
		cin >> Ogrenci_Sifre;
		cout << "\n Ogrenci Numarasi : ";
		cin >> Ogrenci_No;

		DosyaYaz << "\n" << Ogrenci_TC << "        "
			<< Ogrenci_Adi << "        "
			<< Ogrenci_Soyadi << "        "
			<< Ogrenci_Sifre << "        "

			<< Ogrenci_No;

		cout << endl << " - + - + - + Ogrenci Kayidi Tamamlandi + - + - + -" << endl
			<< " _________________________________________________" << endl << endl;

		cout << " Kayit Yapma Devam Icin (E/e)" << endl
			<< " Cikmak Icin (H/h)" << endl
			<< " Menuye Gitmek Icin (M/m)";
		cout << endl << " Secim : ";
		cin >> cevap;
	} while (cevap == 'e' || cevap == 'E');

	if (cevap == 'h' || cevap == 'H')
		DosyaYaz.close();
	else {
		system("cls");
		o.menu();
	}

}
void ogrenci::ogrenciduzenle()
{
	i = 0;
	string sorgu_No;
	system("cls");

	cout << " - + - + - + Ogrenci Kayit Duzenleme + - + - + -" << endl
		<< " ______________________________________________" << endl;

	ifstream DosyaOku("Ogrenci.txt");
	ofstream DosyaYaz("gecici.tmp");


	cout << endl << " Duzenlenecek Ogrencinin Numarasi : ";
	cin >> sorgu_No;


	while (!(DosyaOku.eof()))
	{
		DosyaOku >> Ogrenci_TC >> Ogrenci_Adi >> Ogrenci_Soyadi >> Ogrenci_Sifre >> Ogrenci_No;

		if (sorgu_No == Ogrenci_No)
		{
			cout << endl << endl << " - + - + - + Ogrenci Bilgileri + - + - + -" << endl
				<< " _________________________________________" << endl << endl;

			cout << " Ogrenci Tc :" << Ogrenci_TC << endl;
			cout << " Ogrenci Adi :" << Ogrenci_Adi << endl;
			cout << " Ogrencin Soyadi :" << Ogrenci_Soyadi << endl;
			cout << " Ogrenci Sifresİ :" << Ogrenci_Sifre << endl;
			cout << " Ogrenci Numarasi :" << Ogrenci_No << endl << endl;

			cout << endl << " Ogrenci Bilgilerini Yenileyiniz..." << endl
				<< " _________________________________________" << endl;
			cout << "\n Ogrenci Adi Giriniz :"; cin >> Ogrenci_Adi;
			cout << "\n Ogrenci Soyadi Giriniz. :"; cin >> Ogrenci_Soyadi;
			cout << "\n Ogrenci Sifresi Giriniz :"; cin >> Ogrenci_Sifre;
			cout << "\n Ogrenci Numarasi :"; cin >> Ogrenci_No;

			DosyaYaz << "\n" << Ogrenci_TC << "        "
				<< Ogrenci_Adi << "        "
				<< Ogrenci_Soyadi << "        "
				<< Ogrenci_Sifre << "        "
				<< Ogrenci_No;

			i++;
		}
		else if (Ogrenci_No != sorgu_No)
		{
			DosyaYaz << "\n" << Ogrenci_TC << "        "
				<< Ogrenci_Adi << "        "
				<< Ogrenci_Soyadi << "        "
				<< Ogrenci_Sifre << "        "
				<< Ogrenci_No;
		}
		else
		{
			DosyaYaz << "\n" << Ogrenci_TC << "        "
				<< Ogrenci_Adi << "        "
				<< Ogrenci_Soyadi << "        "
				<< Ogrenci_Sifre << "        "
				<< Ogrenci_No;
		}
	}

	if (i == 0)
	{
		cout << endl << " Boyle Bir Kayit Bulunamamistir." << endl << endl
			<< " Yeniden Denemek Icin (E/e) " << endl;
	}

	cout << endl << " Cikmak Icin (H/h)" << endl
		<< " Menuye Gitmek Icin (M/m)" << endl;
	cout << " Secim : ";
	cin >> cevap;
	if (cevap == 'e' || cevap == 'E')
		o.ogrenciduzenle();
	else if (cevap == 'h' || cevap == 'H')
	{
		DosyaYaz.close();
		DosyaOku.close();
	}
	else {
		system("cls");
		o.menu();
	}

	DosyaYaz.close();
	DosyaOku.close();
	remove("Ogrenci.txt");
	rename("gecici.tmp", "Ogrenci.txt");

}
void ogrenci::ogrencisil()
{
	i = 0;
	system("cls");
	cout << "- + - + - + Ogrenci Kaydi Silme + - + - + -" << endl
		<< "___________________________________________" << endl;
	string silogr_No;
	cout << endl << " Silinecek Ogrenci  Numarasini Giriniz :";
	cin >> silogr_No;

	ifstream DosyaOku("Ogrenci.txt");
	ofstream DosyaYaz("gecici.tmp");

	while (!(DosyaOku.eof()))
	{
		DosyaOku >> Ogrenci_TC >> Ogrenci_Adi >> Ogrenci_Soyadi >> Ogrenci_Sifre >> Ogrenci_No;

		if (Ogrenci_No == silogr_No)
		{

			cout << "- + - + - + Ogrenci Bilgileri + - + - + -" << endl
				<< "_________________________________________" << endl << endl;

			cout << " Ogrenci Tc :" << Ogrenci_TC << endl;
			cout << " Ogrenci Adi :" << Ogrenci_Adi << endl;
			cout << " Ogrencin Soyadi :" << Ogrenci_Soyadi << endl;
			cout << " Ogrenci Sifre :" << Ogrenci_Sifre << endl;
			cout << " Ogrenci Numarasi :" << silogr_No << "\n";
			i++;

			cout << endl << endl << " Silme Isleminiz Gerceklesmistir..." << endl << endl;

		}
		if (Ogrenci_No != silogr_No)
		{
			DosyaYaz << "\n" << Ogrenci_TC << "        "
				<< Ogrenci_Adi << "        "
				<< Ogrenci_Soyadi << "        "
				<< Ogrenci_Sifre << "        "
				<< Ogrenci_No;
		}

	}
	if (i == 0)
	{
		cout << endl << " Boyle Bir Kayit Bulunamamistir" << endl;
		cout << endl << " Yeniden Denemek Icin (E/e) " << endl
			<< " Cikmak Icin (H/h)" << endl
			<< " Menuye Gitmek Icin (M/m)" << endl;
		cout << " Secim : ";
		cin >> cevap;
		if (cevap == 'e' || cevap == 'E')
			o.ogrencisil();
		else if (cevap == 'h' || cevap == 'H')
		{
			DosyaYaz.close();
			DosyaOku.close();
		}
		else {
			system("cls");
			o.menu();
		}
	}
	DosyaYaz.close();
	DosyaOku.close();

	remove("Ogrenci.txt");//dosyayi sildim.
	rename("gecici.tmp", "Ogrenci.txt");//Gecici dosyalar kayit silindikten tmp dosyasi txt dosyasina aktarilir.

}
void ogrenci::ogrencilistele()
{
	i = 0;
	system("cls");
	cout << " - + - + - + Ogrenci Listesi + - + - + -" << endl;

	ifstream DosyaOku("Ogrenci.txt");
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> Ogrenci_TC >> Ogrenci_Adi >> Ogrenci_Soyadi >> Ogrenci_Sifre >> Ogrenci_No;
		cout << " _________________________________________" << endl << endl;
		cout << " Ogrenci Tc :" << Ogrenci_TC << endl;
		cout << " Ogrencinin Adi :" << Ogrenci_Adi << endl;
		cout << " Ogrenci Soyadi :" << Ogrenci_Soyadi << endl;
		cout << " Ogrenci Sifre :" << Ogrenci_Sifre << endl;
		cout << " Ogrenci Numarasi :" << Ogrenci_No << endl;
		i++;
	}
	cout << "_________________________________________" << endl;
	cout << endl << " Toplam Ogrenci Sayisi : " << i << endl << endl;

	cout << " Cikmak Icin (H/h)" << endl
		<< " Menuye Gitmek Icin (M/m)";
	cout << endl << " Secim : ";
	cin >> cevap;
	if (cevap == 'h' || cevap == 'H')
		DosyaOku.close();
	else {
		system("cls");
		o.menu();
	}
}
void ogrenci::ogrencisorgula()
{
	int i = 0;
	string sorguNo;
	system("cls");
	cout << "- + - + - + Ogrenci Sorgulama + - + - + -" << endl
		<< "_________________________________________" << endl << endl;

	cout << "Sorgusu Istenen Ogrencinin Tc'sini Giriniz : ";
	cin >> sorguNo;

	ifstream DosyaOku("Ogrenci.txt");
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> Ogrenci_TC >> Ogrenci_Adi >> Ogrenci_Soyadi >> Ogrenci_Sifre >> Ogrenci_No;

		if (sorguNo == Ogrenci_No)
		{
			cout << endl << endl << "- + - + - + Ogrenci Bilgileri + - + - + -" << endl
				<< "_________________________________________" << endl << endl;
			i++;
			cout << "Ogrenci Tc :" << Ogrenci_TC << endl;
			cout << "Ogrencinin Adi :" << Ogrenci_Adi << endl;
			cout << "Ogrenci Soyadi : " << Ogrenci_Soyadi << endl;
			cout << "Ogrenci Şifre :" << Ogrenci_Sifre << endl;
			cout << "Ogrenci Numarasi :" << sorguNo << endl << endl;

			DosyaOku.close();

			break;
		}
	}
	if (i == 0)
	{
		cout << endl << "Boyle Bir Kayit Bulunamamistir." << endl << endl
			<< "Yeniden Denemek Icin (E/e) " << endl
			<< "Cikmak Icin (H/h)" << endl
			<< "Menuye Gitmek Icin (M/m)" << endl;
		cout << endl << " Secim : ";
		cin >> cevap;
		if (cevap == 'e' || cevap == 'E')
			o.ogrencisorgula();
		else if (cevap == 'h' || cevap == 'H')
		{
			DosyaOku.close();
		}
		else {
			system("cls");
			o.menu();
		}
	}
	cout << " Cikmak Icin (C/c)" << endl
		<< " Menuye Gitmek Icin (M/m)";
	cout << endl << " Secim : ";
	cin >> cevap;
	if (cevap == 'C' || cevap == 'c')
		DosyaOku.close();
	else {
		system("cls");
		o.menu();
	}

}
void soru::sinavmenu() {
	if (k == 1)
	{
		system("cls");            /*Soru işLERi OTOMASYONU YAZSIN DiYE YAPILDI*/
	}
	do
	{
	devam1:
		if (i != 0)
		{
			system("cls");
			cout << endl << " Yanlis secim !!!" << endl			/*YANLIş BiR SECiM YAPILINCA YENiDEN DENEMEK iCiN YAPILDI*/
				<< " Lutfen Yeniden Seciniz. " << endl << endl;
		}
		cout << " 1) Sinav olustur " << endl
			<< " 2) Sinav sil " << endl

			<< " 3)  Cikis " << endl


			<< "_________________________________________________" << endl;
		cout << endl << " Secim : ";
		cin >> secim4;
		if (!(secim4 == 1 || secim4 == 2 || secim4 == 3))
		{
			i++;					/*YANLIş SECiM YAPILINCA YUKARIDAKi iF'E GiDER*/
			goto devam1;
		}
		k++;
	} while (secim4 != 1 && secim4 != 2 && secim4 != 3);
}
void soru::menu()
{
	if (k == 1)
	{
		system("cls");            /*Soru işLERi OTOMASYONU YAZSIN DiYE YAPILDI*/
	}
	do
	{
	devam1:
		if (i != 0)
		{
			system("cls");
			cout << endl << " Yanlis secim !!!" << endl			/*YANLIş BiR SECiM YAPILINCA YENiDEN DENEMEK iCiN YAPILDI*/
				<< " Lutfen Yeniden Seciniz. " << endl << endl;
		}
		cout << " 1) Soru Kayit Ekleme " << endl
			<< " 2) Soru Kayit Duzenleme " << endl
			<< " 3) Soru Kaydi Silme " << endl
			<< " 4) Soru Listesi Alma " << endl
			<< " 5)  Cikis " << endl


			<< "_________________________________________________" << endl;
		cout << endl << " Secim : ";
		cin >> secim3;
		if (!(secim3 == 1 || secim3 == 2 || secim3 == 3 || secim3 == 4 || secim3 == 5))
		{
			i++;					/*YANLIş SECiM YAPILINCA YUKARIDAKi iF'E GiDER*/
			goto devam1;
		}
		k++;
	} while (secim3 != 1 && secim3 != 2 && secim3 != 3 && secim3 != 4 && secim3 != 5);
}
void soru::soruekle()
{

	system("cls");
	cout << " - + - + - + Soru ekleme + - + - + -" << endl
		<< " ___________________________________________" << endl;

	ofstream DosyaYaz;
	DosyaYaz.open("Soru.txt", ios::app);

	do
	{
		system("cls");
		cout << "\n Soru Adi : ";
		cin >> Soru_adi;
		cout << "\n Soru Detay : ";
		cin >> Soru_detay;
		cout << "\n A Sıkkı : ";
		cin >> Cevap_a;
		cout << "\n B Sıkkı : ";
		cin >> Cevap_b;
		cout << "\n C Sıkkı : ";
		cin >> Cevap_c;
		cout << "\n D Sıkkı : ";
		cin >> Cevap_d;
		cout << "\n E Sıkkı : ";
		cin >> Cevap_e;
		cout << "\n Dogru cevap : ";
		cin >> Dogru_cevap;
		cout << "\n Zorluk : ";
		cin >> Zorluk;

		DosyaYaz << "\n" << Soru_adi << "        "
			<< Soru_detay << "        "
			<< Cevap_a << "        "
			<< Cevap_b << "        "
			<< Cevap_c << "        "
			<< Cevap_d << "        "
			<< Cevap_e << "        "
			<< Dogru_cevap << "        "
			<< Zorluk;

		cout << endl << " - + - + - + Soru Kayidi Tamamlandi + - + - + -" << endl
			<< " _________________________________________________" << endl << endl;

		cout << " Kayit Yapmaya Devam Icin (E/e)" << endl
			<< " Cikmak Icin (H/h)" << endl
			<< " Menuye Gitmek Icin (M/m)";
		cout << endl << " Secim : ";
		cin >> cevap;
	} while (cevap == 'e' || cevap == 'E');

	if (cevap == 'h' || cevap == 'H')
		DosyaYaz.close();
	else {
		system("cls");
		s.menu();
	}

}
void soru::soruduzenle()
{
	i = 0;
	string sorgu_adi;
	system("cls");

	cout << " - + - + - + Soru Kayit Duzenleme + - + - + -" << endl
		<< " ______________________________________________" << endl;

	ifstream DosyaOku("Soru.txt");
	ofstream DosyaYaz("gecici1.tmp");


	cout << endl << " Duzenlenecek Sorunun Adi : ";
	cin >> sorgu_adi;


	while (!(DosyaOku.eof()))
	{
		DosyaOku >> Soru_adi >> Soru_detay >> Cevap_a >> Cevap_b >> Cevap_c >> Cevap_d >> Cevap_e >> Dogru_cevap >> Zorluk;

		if (sorgu_adi == Soru_adi)
		{
			cout << endl << endl << " - + - + - + Soru Bilgileri + - + - + -" << endl
				<< " _________________________________________" << endl << endl;

			cout << " Soru Adi :" << sorgu_adi << endl;
			cout << " Soru Detay :" << Soru_detay << endl;
			cout << " A Sıkkı :" << Cevap_a << endl;
			cout << " B Sıkkı :" << Cevap_b << endl;
			cout << " C Sıkkı :" << Cevap_c << endl;
			cout << " D Sıkkı :" << Cevap_d << endl;
			cout << " E Sıkkı :" << Cevap_e << endl;
			cout << " Dogru cevap :" << Dogru_cevap << endl;
			cout << " Zorluk :" << Zorluk << endl << endl;

			cout << endl << " Soru Bilgilerini Yenileyiniz..." << endl
				<< " _________________________________________" << endl;
			cout << "\n Soru detay :"; cin >> Soru_detay;
			cout << "\n A Sıkkı :"; cin >> Cevap_a;
			cout << "\n B Sıkkı  :"; cin >> Cevap_b;
			cout << "\n C Sıkkı :"; cin >> Cevap_c;
			cout << "\n D Sıkkı  :"; cin >> Cevap_d;
			cout << "\n E Sıkkı  :"; cin >> Cevap_e;
			cout << "\n Dogru cevap :"; cin >> Dogru_cevap;
			cout << "\n Zorluk  :"; cin >> Zorluk;
			DosyaYaz << "\n" << Soru_adi << "        "
				<< Soru_detay << "        "
				<< Cevap_a << "        "
				<< Cevap_b << "        "
				<< Cevap_c << "        "
				<< Cevap_d << "        "
				<< Cevap_e << "        "
				<< Dogru_cevap << "        "
				<< Zorluk;

			i++;
		}
		else if (Soru_adi != sorgu_adi)
		{
			DosyaYaz << "\n" << Soru_adi << "        "
				<< Soru_detay << "        "
				<< Cevap_a << "        "
				<< Cevap_b << "        "
				<< Cevap_c << "        "
				<< Cevap_d << "        "
				<< Cevap_e << "        "
				<< Dogru_cevap << "        "
				<< Zorluk;
		}
		else
		{
			DosyaYaz << "\n" << Soru_adi << "        "
				<< Soru_detay << "        "
				<< Cevap_a << "        "
				<< Cevap_b << "        "
				<< Cevap_c << "        "
				<< Cevap_d << "        "
				<< Cevap_e << "        "
				<< Dogru_cevap << "        "
				<< Zorluk;
		}
	}

	if (i == 0)
	{
		cout << endl << " Boyle Bir Kayit Bulunamamistir." << endl << endl
			<< " Yeniden Denemek Icin (E/e) " << endl;
	}

	cout << endl << " Cikmak Icin (H/h)" << endl
		<< " Menuye Gitmek Icin (M/m)" << endl;
	cout << " Secim : ";
	cin >> cevap;
	if (cevap == 'e' || cevap == 'E')
		s.soruduzenle();
	else if (cevap == 'h' || cevap == 'H')
	{
		DosyaYaz.close();
		DosyaOku.close();
	}
	else {
		system("cls");
		s.menu();

	}

	DosyaYaz.close();
	DosyaOku.close();
	remove("Soru.txt");
	rename("gecici1.tmp", "Soru.txt");

}
void soru::sorusil()
{
	i = 0;
	system("cls");
	cout << "- + - + - + Soru Kaydi Silme + - + - + -" << endl
		<< "___________________________________________" << endl;
	string silsoru_adi;
	cout << endl << " Silinecek Soru Adini Giriniz :";
	cin >> silsoru_adi;

	ifstream DosyaOku("Soru.txt");
	ofstream DosyaYaz("gecici.tmp");

	while (!(DosyaOku.eof()))
	{
		DosyaOku >> Soru_adi >> Soru_detay >> Cevap_a >> Cevap_b >> Cevap_c >> Cevap_d >> Cevap_e >> Dogru_cevap >> Zorluk;

		if (Soru_adi == silsoru_adi)
		{

			cout << endl << endl << " - + - + - + Soru Bilgileri + - + - + -" << endl
				<< " _________________________________________" << endl << endl;

			cout << " Soru Adi :" << silsoru_adi << endl;
			cout << " Soru Detay :" << Soru_detay << endl;
			cout << " A Sıkkı :" << Cevap_a << endl;
			cout << " B Sıkkı :" << Cevap_b << endl;
			cout << " C Sıkkı :" << Cevap_c << endl;
			cout << " D Sıkkı :" << Cevap_d << endl;
			cout << " E Sıkkı :" << Cevap_e << endl;
			cout << " Dogru cevap :" << Dogru_cevap << endl;
			cout << " Zorluk :" << Zorluk << endl << "\n";
			i++;

			cout << endl << endl << " Silme Isleminiz Gerceklesmistir..." << endl << endl;

		}
		if (Soru_adi != silsoru_adi)
		{
			DosyaYaz << "\n" << Soru_adi << "        "
				<< Soru_detay << "        "
				<< Cevap_a << "        "
				<< Cevap_b << "        "
				<< Cevap_c << "        "
				<< Cevap_d << "        "
				<< Cevap_e << "        "
				<< Dogru_cevap << "        "
				<< Zorluk;
		}

	}
	if (i == 0)
	{
		cout << endl << " Boyle Bir Kayit Bulunamamistir" << endl;
		cout << endl << " Yeniden Denemek Icin (E/e) " << endl
			<< " Cikmak Icin (H/h)" << endl
			<< " Menuye Gitmek Icin (M/m)" << endl;
		cout << " Secim : ";
		cin >> cevap;
		if (cevap == 'e' || cevap == 'E')
			s.sorusil();
		else if (cevap == 'h' || cevap == 'H')
		{
			DosyaYaz.close();
			DosyaOku.close();
		}
		else {
			system("cls");
			s.menu();
		}
	}
	DosyaYaz.close();
	DosyaOku.close();

	remove("Soru.txt");//dosyayi sildim.
	rename("gecici.tmp", "Soru.txt");//Gecici dosyalar kayit silindikten tmp dosyasi txt dosyasina aktarilir.

}
void soru::sorulistele()
{
	i = 0;
	system("cls");
	cout << " - + - + - + Soru Listesi + - + - + -" << endl;

	ifstream DosyaOku("Soru.txt");
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> Soru_adi >> Soru_detay >> Cevap_a >> Cevap_b >> Cevap_c >> Cevap_d >> Cevap_e >> Dogru_cevap >> Zorluk;
		cout << " _________________________________________" << endl << endl;
		cout << " Soru Adi :" << Soru_adi << endl;
		cout << " Soru Detay :" << Soru_detay << endl;
		cout << " A Sıkkı :" << Cevap_a << endl;
		cout << " B Sıkkı :" << Cevap_b << endl;
		cout << " C Sıkkı :" << Cevap_c << endl;
		cout << " D Sıkkı :" << Cevap_d << endl;
		cout << " E Sıkkı :" << Cevap_e << endl;
		cout << " Dogru cevap :" << Dogru_cevap << endl;
		cout << " Zorluk :" << Zorluk << endl;
		i++;
	}
	cout << "_________________________________________" << endl;
	cout << endl << " Toplam Soru Sayisi : " << i << endl << endl;

	cout << " Cikmak Icin (H/h)" << endl
		<< " Menuye Gitmek Icin (M/m)";
	cout << endl << " Secim : ";
	cin >> cevap;
	if (cevap == 'h' || cevap == 'H')
		DosyaOku.close();
	else {
		system("cls");
		s.menu();
	}
}
int main()
{
	bool tekrar = false;
yeniden:
	cout << " 1 - Ogrenci isleri " << endl
		<< " 2 - Soru isleri " << endl
		<< " 3 - Sinav islemleri" << endl
		<< " 4 - Rapor" << endl
		<< " 5 - Sinava giris" << endl
		<< endl << " Secim : ";
	cin >> secim2;
	bool menuTekrar = false;//girilen menuye tekrar girmek istediginde kontrol etmek icin olusturdugum bool degiskeni
	switch (secim2)
	{

	case 1:
		system("cls");
		cout << " - + - + - + OGRENCI ISLERI  + - + - + -" << endl
			<< " _________________________________________________" << endl << endl;
		o.menu();
		switch (secim)
		{
		case 1:o.ogrenciekle(); break;
		case 2:o.ogrenciduzenle(); break;
		case 3:o.ogrencisil(); break;
		case 4:o.ogrencilistele(); break;
		case 5:o.ogrencisorgula(); break;
		case 6:break;
		}
		break;
	case 2:
		system("cls");
		cout << " - + - + - + SORU ISLERI  + - + - + -" << endl
			<< " _________________________________________________" << endl << endl;
		s.menu();
		switch (secim3)
		{
		case 1:s.soruekle(); break;
		case 2:s.soruduzenle(); break;
		case 3:s.sorusil(); break;
		case 4:s.sorulistele(); break;
		case 5:break;
		}
		break;
	case 3:
		system("cls");

		cout << " - + - + - + SINAV ISLERI  + - + - + -" << endl
			<< " _________________________________________________" << endl << endl;

		do
		{													//menunun ilk etapta bir kez oynatilip sonra istege bagli olmasi icin do while kullandÄ±m
			tekrar = false;
			int secim6;
			cout << "Yapmak istediginiz islemi asagidan seciniz\n";
			cout << "1)Sinav olustur \n";
			cout << "2)Sinav Sil\n";
			cout << "3)Programdan cik\n";
			cin >> secim6;
			system("cls");//ekrani tamizleyen kod
			if (secim6 == 1)

			{
				s.sinavaekle();
				bool menuTekrar = false;
				do
				{
					menuTekrar = false;
					cout << "*********************- Sinav Olustur -*************************** \n";
					cout << "*********** Soru Listesi ***********\n";
					ofstream ac("sinav.txt", ios::app);
					ac.close();
					ifstream oku("Soru.txt", ios::in);
					string Soru_adi, Soru_detay, Cevap_a, Cevap_b, Cevap_c, Cevap_d, Cevap_e, Dogru_cevap, Zorluk;
					while (!oku.eof())
					{
						getline(oku, Soru_adi);
						getline(oku, Soru_detay);
						getline(oku, Cevap_a);
						getline(oku, Cevap_b);
						getline(oku, Cevap_c);
						getline(oku, Cevap_d);
						getline(oku, Cevap_e);
						getline(oku, Dogru_cevap);
						getline(oku, Zorluk);
						if (Soru_adi != "")
						{
							cout << "Soru_adi: " << Soru_adi << " - Soru metni: " << Soru_detay << " - Zorluk:" << Zorluk << endl;//mevcut sorulari ekrana basiyorum
						}
					}
					s.sorulistele();
					oku.close();
					string sinavAdi, sinavSuresi, tutucu, sinavSoru_adi;
					int soruSayisi;
					cout << "Sinav adini yaziniz\n";
					cin >> sinavAdi;
					cout << "Soru sayisini yaziniz\n";
					cin >> soruSayisi;
					cout << "Sinav suresini yaziniz\n";
					cin >> sinavSuresi;
					cout << "Sinavda olan sorularin Soru_adi lerini giriniz\n";
					for (int i = 0; i < soruSayisi; i++)//girilen soru sayisi kadar soru Soru_adisi girmesi icin donguyu ayarladim
					{
						bool kontrol = false;
						cin >> tutucu;
						ifstream oku2("Soru.txt", ios::in);
						while (!oku2.eof())
						{
							string Soru_adi, Soru_detay, Cevap_a, Cevap_b, Cevap_c, Cevap_d, Cevap_e, Cevap, Zorluk;
							getline(oku2, Soru_detay);
							getline(oku2, Cevap_a);
							getline(oku2, Cevap_b);
							getline(oku2, Cevap_c);
							getline(oku2, Cevap_d);
							getline(oku2, Cevap_e);
							getline(oku2, Dogru_cevap);
							getline(oku2, Zorluk);
							if (Soru_adi == tutucu)//Soru_adi sorularda oldugu muddetce tutucu degiskeni ile tuttugum soru Soru_adisini kaydediyorum
							{
								kontrol = true;
							}
						}
						if (kontrol)
						{
							sinavSoru_adi += tutucu + " ";
						}
						else
						{
							sinavSoru_adi = "";
							system("cls");
							cout << "boyle bir Soru_adi bulunamadi lutfen bastan giriniz.\n";
							menuTekrar = true;
							break;
						}
						oku2.close();
					}
					if (!menuTekrar)
					{
						cout << "Sinav kaydedildi.\n";
						ofstream yaz("sinav.txt", ios::app);
						yaz << sinavAdi << endl << sinavSuresi << endl << soruSayisi << endl << sinavSoru_adi << endl;
						yaz.close();
						cout << "Ana menuye donmek icin 2 ye tekrar girmek icin 1 e basiniz\n";
						string giris;
						cin >> giris;
						if (giris == "1")
						{
							menuTekrar = true;
						}
						else
						{
							menuTekrar = false;
							tekrar = true;
						}
						system("cls");
					}

				} while (menuTekrar);
			}

			if (secim6 == 2)
			{
				bool menuTekrar = false;
				do
				{
					cout << "*******************- Sinav Sil -***********************\n";
					string isim, str;
					ofstream ac("sinav.txt", ios::app);
					ac.close();
					ifstream oku("sinav.txt", ios::in);
					cout << "*********** Sinav Listesi ***********\n";
					while (!oku.eof())
					{
						string kontrol1, kontrol2, kontrol3, kontrol4;
						getline(oku, kontrol1);
						getline(oku, kontrol2);
						getline(oku, kontrol3);
						getline(oku, kontrol4);
						if (kontrol1 != "" && kontrol2 != "" && kontrol3 != "" && kontrol4 != "")
						{
							cout << " isim: " + kontrol1 + " - " + kontrol2 + " - " + kontrol3 + " - " + kontrol4 + "\n";//mevcut sinavlari ekrana basiyorum
						}
					}
					oku.close();
					cout << "Silinecek Sinavin Adini Giriniz\n";
					cin >> isim;
					bool isimKontrol = false;
					string kontrol1, kontrol2, kontrol3, kontrol4;
					ifstream oku2("sinav.txt", ios::in);
					while (!oku2.eof())
					{
						getline(oku2, kontrol1);
						getline(oku2, kontrol2);
						getline(oku2, kontrol3);
						getline(oku2, kontrol4);
						if (kontrol1 == isim)
						{
							isimKontrol = true;//girilen sinav adi var mi diye bakiyorum
						}
					}
					if (isimKontrol)
					{
						string str;
						string satirlar[1500];
						ifstream oku3("sinav.txt", ios::in);
						int i = 0;
						while (!oku3.eof())
						{
							string str1, str2, str3, str4;
							getline(oku3, str1);
							getline(oku3, str2);
							getline(oku3, str3);
							getline(oku3, str4);
							if (str1 != isim)
							{
								if (str1 != "")
								{
									satirlar[i] = str1;//girilen sinav ismine esit olmadigi muddetce diziye atiyorum
									satirlar[i + 1] = str2;
									satirlar[i + 2] = str3;
									satirlar[i + 3] = str4;
									i += 4;
								}
							}
						}
						cout << "silme islemi basarili.\n";
						oku3.close();
						ofstream sil;
						sil.open("sinav.txt", ofstream::out | ofstream::trunc);//kesme islemi bu sayede dosya siliniyor
						sil.close();
						ofstream yaz2("sinav.txt", ios::app);
						for (int j = 0; j < i + 1; j++)
						{
							yaz2 << satirlar[j] << endl;//atadigi diziyi txt dosyasina basiyorum
						}
						yaz2.close();
						cout << "Ana menuye donmek icin 2 ye tekrar girmek icin 1 e basiniz\n";
						string giris;
						cin >> giris;
						if (giris == "1")
						{
							menuTekrar = true;
						}
						else
						{
							menuTekrar = false;
							tekrar = true;
						}
						system("cls");

					}
					else
					{
						system("cls");
						cout << "Girdiginiz isim sinav listesinde bulunamadi tekrar deneyiniz\n";
						menuTekrar = true;

					}
				} while (menuTekrar);
			}

		} while (tekrar);
		break;
	case 4:
	{


		system("cls");
		cout << "******************- Raporlar -******************* \n";
		cout << "*********** Sonuc Listesi ***********\n";

		ofstream ac("raporlar.txt", ios::app);
		ac.close();
		//rapor dosyasini aciyorum
		ifstream oku("raporlar.txt", ios::in);

		string ogrenci, sinav, sonuc, giris;

		while (!oku.eof())
		{
			getline(oku, ogrenci);
			getline(oku, sinav);
			getline(oku, sonuc);

			if (ogrenci != " ")
			{
				cout << "Ogrenci: " << ogrenci << " - Sinav: " << sinav << " - Sonuc: " << sonuc << endl;//rapor dosyasindaki verileri ekrana basiyorum
			}
		}
		oku.close();
		cout << "Ana menuye donmek icin 2 ye programdan cikmak icin 1 e basiniz\n";

		cin >> giris;
		if (giris == "2")
		{
			tekrar = true;
		}
		else {
			tekrar = false;
		}
	}
	break;



	case 5:
	{

		system("cls");
		do
		{
			menuTekrar = false;
			cout << "******************- Sinav Ol -************************* \n";
			cout << "*********** Sinav Listesi ***********\n";
			ofstream ac;
			ac.open("sinav.txt", ios::app);
			ac.close();
			ofstream ac2;
			ac2.open("raporlar.txt", ios::app);
			ac2.close();
			ifstream oku("sinav.txt", ios::in);
			while (!oku.eof())
			{
				string sinavAdi, sinavSuresi, sinavSoru, sorular;
				getline(oku, sinavAdi);
				getline(oku, sinavSuresi);
				getline(oku, sinavSoru);
				getline(oku, sorular);
				if (sinavAdi != "")
				{
					cout << "Sinav Adi: " << sinavAdi << " Sinav suresi: " << sinavSuresi << " Soru sayisi: " << sinavSoru << endl;//mevcut sinavlari ekrana basiyorum
				}
			}
			oku.close();
			string sinavIsmi;
			cout << "Girmek istediginiz sinavin adini giriniz.\n";
			cin >> sinavIsmi;
			ifstream oku2("sinav.txt", ios::in);
			bool kontrol = false;
			string str1, str2, str3, str4;
			while (!oku2.eof())
			{
				getline(oku2, str1);
				getline(oku2, str2);
				getline(oku2, str3);
				getline(oku2, str4);
				if (str1 == sinavIsmi)
				{
					kontrol = true;//girilen sinav adi var mi diye bakiyorum
					break;
				}
			}
			int periyot = stoi(str2);//sinav suresini degiskene atiyorum
			int soruSayisi = stoi(str3);
			string tutucu[1000];
			int i = 0;;
			for (int j = 0; j < str4.length(); j++)
			{
				if (str4.substr(j, 1) != " ")//sorulari xx xx xx seklinde kaydettigim icin Soru_adileri ayiriyorum
				{
					tutucu[i] += str4.substr(j, 1);
				}
				else
				{
					i++;
				}
			}
			oku2.close();
			if (kontrol)
			{
				string ogrenciTc, sifre;
				cout << "Girecek ogrencinin Adini giriniz.\n";
				cin >> ogrenciTc;
				ifstream ogrenciKontrol("ogrenci.txt", ios::in);
				bool tcKontrol = false;
				string ogrenciAdi, ogrenciTcsi, ogrenciSifre;
				while (!ogrenciKontrol.eof())
				{
					getline(ogrenciKontrol, ogrenciAdi);
					getline(ogrenciKontrol, ogrenciTcsi);
					getline(ogrenciKontrol, ogrenciSifre);
					if (ogrenciTc == ogrenciTcsi)// tc kontolu
					{
						tcKontrol = true;
						break;
					}
				}
				ogrenciKontrol.close();
				if (tcKontrol)
				{
					cout << "tcyi giriniz.\n";
					cin >> sifre;
					ifstream passKontrol("ogrenci.txt", ios::in);
					string a, b, c;
					bool sifreKontrol = false;
					while (!passKontrol.eof())
					{
						getline(passKontrol, a);
						getline(passKontrol, b);
						getline(passKontrol, c);
						if (sifre == c)
						{
							sifreKontrol = true;//sifre kontrolu
							break;
						}
					}

					passKontrol.close();
					if (sifreKontrol)
					{
						bool raporKontrol = false;
						string isim, sinav, sinavSonucu;
						ifstream raporOku("raporlar.txt", ios::in);
						while (!raporOku.eof())
						{
							getline(raporOku, isim);
							getline(raporOku, sinav);
							getline(raporOku, sinavSonucu);
							if (isim == ogrenciAdi)
							{
								if (sinav == sinavIsmi)//daha once girmis mi diye kontrol ediliyor
								{
									raporKontrol = true;
								}
							}
						}
						raporOku.close();
						if (!raporKontrol)
						{
							string sorular[1000], Dogru_cevaplar[1000];
							int i = 0;
							ifstream oku3("Soru.txt", ios::in);
							while (!oku3.eof())
							{
								getline(oku3, sorular[i]);
								getline(oku3, sorular[i + 1]);
								getline(oku3, sorular[i + 2]);
								getline(oku3, sorular[i + 3]);
								getline(oku3, sorular[i + 4]);
								getline(oku3, sorular[i + 5]);
								getline(oku3, sorular[i + 6]);
								getline(oku3, sorular[i + 7]);
								getline(oku3, sorular[i + 8]);
								if (sorular[i] != "")
								{
									for (int j = 0; j < soruSayisi; j++)
									{
										if (sorular[i] == tutucu[j])
										{
											Dogru_cevaplar[i / 9] = sorular[i + 7];//Dogru_cevaplari onceden diziye atiyorum
											i += 9;
										}
									}
								}
							}
							oku3.close();
							string kullaniciDogru_cevaplari[1000];
							clock_t endwait;
							endwait = clock() + (periyot * 60) * CLOCKS_PER_SEC;//sayaci sinav suresine gore ayarliyorum
							int sayac = 0;
							bool sayacKontrol = false;
							while (clock() < endwait)//sayac durmadigi surece dongu donuyor
							{
								for (int k = 0; k < soruSayisi; k++)
								{
									if (sayac < soruSayisi)//sorularin hepsini Dogru_cevapladiktan sonra dongunun durmasini sagliyorum
									{
										for (int j = k * 9; j < ((k + 1) * 9); j++)
										{
											if (j % 9 != 0 && j % 9 != 8 && j % 9 != 7)
											{
												cout << sorular[j] << endl;//sorulari ekrana basiyorum
												if (j == ((k + 1) * 9) - 3)
												{
													cin >> kullaniciDogru_cevaplari[sayac];//Dogru_cevaplari aliyorum
													sayac++;
												}
											}
										}

									}
									else
									{
										sayacKontrol = true;
										break;
									}
								}
								if (sayacKontrol)
								{
									break;
								}
							}
							cout << "Sinav oturmunuz bitmistir.\n";
							int dogrular = 0;
							for (int k = 0; k < soruSayisi; k++)
							{
								if (Dogru_cevaplar[k] == kullaniciDogru_cevaplari[k])
								{
									dogrular++;
								}
							}
							double sonuc = ((dogrular / soruSayisi) * 100);
							cout << ogrenciAdi + " " << sonuc << " puan aldiniz\n";
							ofstream sonucYaz("raporlar.txt", ios::app);
							sonucYaz << ogrenciAdi << endl << sinavIsmi << endl << sonuc << endl;
							sonucYaz.close();
							cout << "Ana menuye donmek icin 2 ye baska sinava girmek icin 1 e basiniz\n";
							string giris;
							cin >> giris;
							if (giris == "1")
							{
								menuTekrar = true;
							}
							else
							{
								menuTekrar = false;
								tekrar = true;
							}
							system("cls");
						}
						else
						{
							system("cls");
							cout << "Bu ogrenci zaten sinava girdi.\n";
							menuTekrar = true;
						}
					}
					else
					{
						system("cls");
						cout << "Sifreniz yanlisti lutfen yenSoru_adien deneyiniz.\n";
						menuTekrar = true;
					}
				}
				else
				{
					system("cls");
					cout << "Bu Tc ye sahip ogrenci bulunamadi tekrar deneyiniz\n";
					menuTekrar = true;
				}
			}
			else
			{
				system("cls");
				cout << "Boyle bir sinav bulunmamaktadir yenSoru_adien giriniz\n";
				menuTekrar = true;
			}
		} while (menuTekrar);
		
	}
	break;
	}
}