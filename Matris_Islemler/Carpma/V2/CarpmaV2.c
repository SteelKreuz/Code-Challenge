/* ****************************************
 * Surum 2: Verilen iki matrisi carpar.
 *
 * ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>   // system()
/* Butun islemler Fonksiyonlar.h dosyasindadir.*/
#include "Fonksiyonlar.h"


void main() {

    while (1)
    {
        int M1_sat, M1_sut, M2_sat, M2_sut, Sonuc_sat, Sonuc_sut;
        int **m1 = (int**)malloc(sizeof(int*)),
            **m2 = (int**)malloc(sizeof(int*)),
            **CarpimMat = (int**)malloc(sizeof(int*));

        system("CLS");
        printf("\n1. Matrisin satir sayisi: ");
        scanf_s("%d", &M1_sat);

        printf("\n1. Matrisin sutun sayisi: ");
        scanf_s("%d", &M1_sut);

        printf("\n2. Matrisin satir sayisi: ");
        scanf_s("%d", &M2_sat);

        if (M1_sut == M2_sat)
        {
            printf("\n2. Matrisin sutun sayisi: ");
            scanf_s("%d", &M2_sut);

            Sonuc_sat = M1_sat;
            Sonuc_sut = M2_sut;

            DiziOlustur(m1, M1_sat, M1_sut);
            DiziOlustur(m2, M2_sat, M2_sut);
            DiziOlustur(CarpimMat, Sonuc_sat, Sonuc_sut);

            DiziElemanEkle(m1, M1_sat, M1_sut, '1');    
            DiziElemanEkle(m2, M2_sat, M2_sut, '2');
            
            MatrisCarpmak(CarpimMat, m1, m2, Sonuc_sat, Sonuc_sut, M1_sut);
            
            beklet();
        }
        else
        {
            system("CLS");
            printf("\n1. Matrisin SUTUN degeri ile 2. Matrisin satir degeri AYNI olmak zorundadir...\n\n");
            
            beklet();
        }


    }

}