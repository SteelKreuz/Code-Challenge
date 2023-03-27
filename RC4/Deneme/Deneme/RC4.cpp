#include <iostream>		// for io
#include <string>		// string properties
#include <cmath>		// pow()
#include <conio.h>		// _getch()
#include <fstream>		// file
#include <windows.h>   // Sleep()

#define MAX_SIZE 125000
#define BIT 8

using namespace std;

// Binary formata cevirmek.
string BolmeIle(string name)
{
	string bitler = "";
	int len = name.size();

	for (int i = 0; i < len; i++)
	{
		int kalan[8];
		int deger = int(name[i]);
		for (int j = 0; j < 8; j++)
		{
			kalan[j] = deger % 2;
			deger /= 2;
		}
		for (int j = 7; j >= 0; j--)
			bitler += to_string(kalan[j]);

		bitler += " ";
	}
	return bitler;
}

// String formattaki binary degerini karakterlere donusturur.
string BinaryToString(string binary) {
	//cout << "Fonk. icinde binary: " << binary << endl;
	//cout << "fonk icinde binary uzunluk: " << binary.size() << endl;
	long long kalan, onluk_sayi = 0, taban = 1;
	long long uzunluk = binary.size();
	string msg = "";

	for (long long i = 8; i < uzunluk; i += BIT)
	{

		for (long long j = (i - 1), k = 0; j >= (i - BIT); j--, k++)
		{
			short bit = (binary[j] == '1' ? 1 : 0);
			onluk_sayi += pow(2, k) * bit;
		}
		// String'te bir bosluk vardir !!
		i++;
		msg += (char(onluk_sayi));
		onluk_sayi = 0;
		//cout << msg << endl;
	}
	return msg;
}

// BitWise Op. ile binary formata cevirmek.
string BitWiseWith(string name) {
	string bitler = "";
	if (name == "") return 0;
	unsigned int len = name.size();

	for (int i = 0; i < len; i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			if (name[i] & (1 << j)) bitler += '1';
			else bitler += '0';
		}
		bitler += ' ';
	}
	return bitler;
}

// Key-scheduling algorithm - Anahtar Zamanlama Algoritmasi
// Sifreleme icin kullanilacak anahtarda shifting yani
// kaydirma islemleri yapilir.
// Degistirilmis bir anahtar olusturulur.
void KSA(string key, long long S[]) {

	long long len = key.size();
	long long j = 0;

	// Sifreli metin icin, gereken her ihtimal S dizisinde
	// olusturulur.
	for (long long i = 0; i < MAX_SIZE; i++)
		S[i] = i;

	// key degerini, bastan sona dogru; bazi degerler ile
	// toplayip, MAX_SIZE ile mod islemi yapiyoruz.
	for (long long i = 0; i < MAX_SIZE; i++) {
		j = (j + S[i] + long long(key[i % len])) % MAX_SIZE;

		// Bastaki karakter ile j'ninci indisteki elemanin
		// degerlerini takas ediyoruz.
		//swap(&S[i], &S[j]);

		long long tmp = S[i];
		S[i] = S[j];
		S[j] = tmp;
	}
}

// Pseudo-random generation algorithm
// Sozde rastgele sayi olusturma algoritmasi
string PRGA(long long S[], string DuzMetin) {
	char* SifreliMetin = (char*)malloc(MAX_SIZE);
	long long i = 0;
	long long j = 0;
	for (long long i = 0; i < MAX_SIZE; i++)
		SifreliMetin[i] = ' ';

	// olusturulan i ve j'ninci indisteki degerler ile
	// metindeki her karakteri xor ile isliyoruz.
	for (long long n = 0, len = DuzMetin.size(); n < len; n++) {
		i = (i + 1) % MAX_SIZE;
		j = (j + S[i]) % MAX_SIZE;

		//swap(&S[i], &S[j]);
		long long tmp = S[i];
		S[i] = S[j];
		S[j] = tmp;

		// her xor islemi icin tek seferlik random bir
		// anahtar degeri olusturulur
		long long random = S[(S[i] + S[j]) % MAX_SIZE];
		//printf("(%X02hh, %d) - ", random, random);
		//_getch();
		// bu anahtar ile metin xor islemi ile sifrelenir.
		SifreliMetin[n] = random ^ DuzMetin[n];
	}
	memset(SifreliMetin + DuzMetin.length(), 0, sizeof(SifreliMetin));

	return SifreliMetin;
}

string RC4(string key, string DuzMetin) {

	long long S[MAX_SIZE];
	KSA(key, S);

	return PRGA(S, DuzMetin);
}

void Encryption() {
	long long Metin_boyut;
	string key;
	string mesaj;

	string Sifreli_Metin;

	string ikilik_sifre;


	system("cls");

	cout << "Sifrelenicek mesaji giriniz:" << endl;
	getline(cin, mesaj);
	cout << "\nSifreleme icin Anahtari giriniz: " << endl;
	getline(cin, key);

	system("cls");

	cout << "\n\n--------------------------------------" << endl;
	cout << "Encryption islemi basliyor..." << endl;
	cout << "--------------------------------------" << endl;
	Sifreli_Metin = BitWiseWith(RC4(key, mesaj));

	Sleep(60 * 30); // 0.5 dk bekletir.

	cout << "\n\nsifreleme bitti..." << endl;

	system("cls");

	Metin_boyut = Sifreli_Metin.size();
	cout << "\n\nSifrelenmis veri: ";
	for (long long i = 0; i < Metin_boyut; i++)
		cout << Sifreli_Metin[i];
	cout << "\n\n";

	ofstream Dosya("Sifre.txt");

	if (Dosya.is_open()) {
		for (long long i = 0; i < Metin_boyut; i++)
			Dosya << Sifreli_Metin[i];
		Dosya.close();
	}
	else {
		cout << "Dosya Acik !!" << endl;
	}

	cout << "\nDevam etmek icin herhangi bir tusa basin." << endl;
	_getch();
}

void Decryption() {
	// int veriBitisDeger = *index;

	string ikilik_metin;
	string key;
	string Duz_metin;
	string Cozulmus_Mesaj;
	//char Dizi_krk[MAX_SIZE];


	//int ikilik_sifre[MAX_SIZE];



	//char str[MAX_SIZE];


	system("cls");

	cout << "Sifresi cozulucek mesaji giriniz:" << endl;
	getline(cin, ikilik_metin);

	cout << "\nSifreleme icin Anahtari giriniz:" << endl;
	getline(cin, key);

	Duz_metin = BinaryToString(ikilik_metin);
	//for (int i = 0; i < boyut; i += BIT) {
	//	char sub_str[BIT];

	//	memcpy(sub_str, ikilik_metin + i, BIT);
	//	Dizi_krk[(*index)++] = BinaryToChar(sub_str);
	//}



	cout << "\n\n--------------------------------------" << endl;
	cout << "Decryption islemi basliyor..." << endl;
	cout << "--------------------------------------\n\n" << endl;
	Cozulmus_Mesaj = RC4(key, Duz_metin);

	cout << "\n\nCozulmus Sifre: " << Cozulmus_Mesaj << endl;

	cout << "\nDevam etmek icin herhangi bir tusa basin." << endl;
	_getch();
}


int main() {

	string menu = "\nEncryption islemi icin E tusuna basin\nDecryption islemi icin D tusuna\nCikis icin Q tusuna basiniz\n";

	char secim;

	while (1) {
		system("cls");
		cout << menu;
		cin >> secim;
		secim = toupper(secim);
		cin.ignore();


		if (secim == 'E') {
			Encryption();
		}
		else if (secim == 'D') {
			Decryption();
		}
		else if (secim == 'Q')
		{
			break;
		}
		else
		{
			system("cls");
			cout << "Dogru secenek girin!\nDevam etmek icin herhangi bir tusa basin." << endl;
			_getch();
		}

	}
	return 0;
}