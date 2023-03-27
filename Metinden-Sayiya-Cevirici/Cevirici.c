/*  Author : Emircan CANSEVDI
 *  Created: 27.03.2023
 *
 *  C dilindeki, atoi() fonksiyonunu 
 *  canlandiran kod ornegi.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int kuvvet(int taban, int us)
{
    int sonuc = 1, i;

    for(i = 0; i < us; i++)
        sonuc *= taban;
    
    return sonuc;
}

int boyut(char* str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

int rakamCevir(char ch)
{
    int rakam;
    switch(ch)
    {
        case '0': rakam = 0; break;
        case '1': rakam = 1; break;
        case '2': rakam = 2; break;
        case '3': rakam = 3; break;
        case '4': rakam = 4; break;
        case '5': rakam = 5; break;
        case '6': rakam = 6; break;
        case '7': rakam = 7; break;
        case '8': rakam = 8; break;
        case '9': rakam = 9; break;
        // Bir hata olursa -1 hatali kodu dondursun.
        default: rakam = -1; 
    }

    return rakam;
}

void tersCevir(char* str, char* str2, char durum)
{    
    int uzunluk, hamStr, i;
    
    // dizinin uzunlugu bulunur.
    uzunluk = boyut(str);
    
    
    // '\0' karakteri haric, toplam karakter adeti
    hamStr = uzunluk - 1;
    
    // string ifadenin, sonundan basina kadar giderken
    // negatif degerde '-256', sonuna kadar gitmesini istemiyoruz.
    // Cunku '-' degeri sadece yon belirtiyor.
    // Biz degerleri hesaplamak icin sadece sayilari alacagiz.
    if (durum)
        uzunluk -= 1;

    for(i = 0; i <= uzunluk; i++)
    {
        str2[i] = str[hamStr];
        hamStr--;
    }
    // dizi icindeki gereksiz karakterleri siler.
    memset(str2 + uzunluk, '\0', 1);    
}

int yazidanSayiya(char* str, char durum)
{
    int sayi = 0, i;

    for(i = 0; i < boyut(str); i++)
    {        
            sayi += rakamCevir(str[i]) * kuvvet(10, i);
    }

    if (durum)
        sayi *= -1;
    else
        sayi *= 1;
    
    return sayi; 
}

void main()
{
    char *word = (char*)malloc(MAX * sizeof(char));
    char *word2 = (char*)malloc(MAX * sizeof(char));
    int sayi;
    char negatifMi = 0; // varsayilan olarak false

    printf("Metin giriniz: ");
    scanf("%s", word);

    if (word[0] == '-')
        negatifMi = 1; // sayi negatif ise true
    else
        negatifMi = 0; // degil ise false

    tersCevir(word, word2, negatifMi);

    printf("\n\nString halinin ters cevrilmisi: %s", word2);

    sayi = yazidanSayiya(word2, negatifMi);

    printf("\n\nSayi Hali: %d\n", sayi);
}
