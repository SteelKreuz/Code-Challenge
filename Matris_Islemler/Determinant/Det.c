#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>       // toupper()
#include "Fonksiyonlar.h"
//#include <conio.h>    // getch() icin gerekebilir.


void main(){

    long long** Mat = (long long**)malloc(sizeof(long long*)),
          Boyut = 0, sonuc;

    while (1)
    {
        system("CLS");
        char durum = 1, secim;        

        printf("Matrix Hesaplama islemi icin -> 'E'\n \
                \rCikis icin -> Herhangi bir tusu\n   \
                \rTuslayiniz: ");
        secim = toupper(_getch());

        if(secim == 'E')
        {
            system("CLS");
            printf("Dizinin boyutunu giriniz (Satir veya Sutun adedi): ");
            scanf_s("%lld", &Boyut);

            if (Boyut > 0)
            {
                DiziOlustur(Mat, Boyut, Boyut);

                DiziElemanEkle(Mat, Boyut, Boyut, ' ');

                Goster(Mat, Boyut);

                sonuc = Determinant(Mat, Boyut);
            }
            else durum = 0;



            if (durum)
                printf("\n\nMatrisin Determinant degeri: %lld\n\n", sonuc);
            else
                printf("\n\nDogru deger giriniz !!!\n\n");

            beklet();
        }
        else break;        
    }
 }