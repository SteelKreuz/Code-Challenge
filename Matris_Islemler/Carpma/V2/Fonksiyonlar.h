#include <stdio.h>
#include <stdlib.h>
#include <conio.h>     // _getch()
#include <windows.h>   // system()

void DiziOlustur(int** matris, int satir, int sutun)
{
    *matris = (int*)malloc(satir * sizeof(int*));
    for(int i = 0; i < satir; i++)
        matris[i] = (int*)malloc(sutun * sizeof(int));
}

void DiziElemanEkle(int** matris, int sat, int sut, char kacinci)
{
            printf("\n\n%c. matris degerlerini girin:\n", kacinci);
            for(int satir = 0; satir < sat; satir++)
            {
                for(int sutun = 0; sutun < sut; sutun++)
                {
                    scanf_s("%d", &matris[satir][sutun]);
                }
            }
}

void MatrisCarpmak(int** matris, int** mat1, int** mat2, int sat, int sut, int hedef_sut)
{
    printf("\n\nMatrislerin Carpim sonucu:\n");
    for(int satir = 0; satir < sat; satir++)
    {
        for(int sutun = 0; sutun < sut; sutun++)
        {
            int toplam, hedef;
            for(toplam = 0, hedef = 0; hedef < hedef_sut; hedef++)
            {
                toplam += mat1[satir][hedef] * mat2[hedef][sutun];
            }
            matris[satir][sutun] += toplam;
            printf(" %d ", toplam);
        }
        printf("\n");
    }
}

void beklet()
{
    puts("\nDevam etmek icin bir tusa basiniz...");
    _getch();
}