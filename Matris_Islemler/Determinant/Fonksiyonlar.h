#include <stdio.h>
#include <stdlib.h>
#include <conio.h>     // _getch()
#include <windows.h>   // system()

void beklet()
{
    printf("\nDevam etmek icin bir tusa basiniz...");
    _getch();
}

void DiziOlustur(long long** matris, int satir, int sutun)
{
    *matris = (long long*)malloc(satir * sizeof(long long*));
    for(int i = 0; i < satir; i++)
        matris[i] = (long long*)malloc(sutun * sizeof(long long));
}

void DiziElemanEkle(long long** matris, int sat, int sut, char kacinci)
{
    printf("\n\n%c matris degerlerini girin:\n", kacinci);
    for(int satir = 0; satir < sat; satir++)
    {
        for(int sutun = 0; sutun < sut; sutun++)
        {
            printf("\nmatris[%d][%d]: ", satir, sutun);
            scanf_s("%lld", &matris[satir][sutun]);
        }
        system("CLS");
    }
    beklet();
    system("CLS");
}

void Goster(long long** matris, int boyut)
{
    printf("Girilen matris: \n");
    for(int satir = 0; satir < boyut; satir++)
    {
        printf(" ");
        for(int sutun = 0; sutun < boyut; sutun++)
        {
            printf("%lld ", matris[satir][sutun]);
        }
        printf("\n");
    }
}

void KoFaktor(long long** matris, long long** yeniMatris, int sat, int sut, int boyut)
{
    int row = 0, col = 0;
    //printf("\nSiradaki KoFaktor matris: ");
    for(int satir = 0; satir < boyut; satir++)
    {
        for(int sutun = 0; sutun < boyut; sutun++)
        {
            if(satir != sat && sutun != sut)
            {
                yeniMatris[row][col++] = matris[satir][sutun];
                //printf(" %lld ", yeniMatris[row][col-1]);
                if (col == (boyut - 1))
                {
                    col = 0;
                    row++;
                }
            }
        }
        //printf("\n");
    }
    //printf("\nKofaktor bitiyor...");
}

long long Determinant(long long** matris, int boyut)
{
        
    if(boyut == 1)
    {
        return matris[0][0];
    }
    else if(boyut == 2)
    {
        long long Kosegen1 = 1, Kosegen2 = 1;
        for(int i = 0, j = (boyut - 1); i < boyut; i++, j--)
        {
         Kosegen1 *= matris[i][i];
         Kosegen2 *= matris[i][j];
        }

        return (Kosegen1 - Kosegen2);
    }
    else if (boyut == 3)
    {
        {
        // Yontem: 1
        // int kose1, kose2;
    
        // kose1 = (matris[0][0] * matris[1][1] * matris[2][2])
        //       + (matris[0][1] * matris[1][2] * matris[2][0])
        //       + (matris[1][0] * matris[2][1] * matris[0][2]);

        // kose2 = (matris[0][2] * matris[1][1] * matris[2][0])
        //       + (matris[0][1] * matris[1][0] * matris[2][2]) 
        //       + (matris[1][2] * matris[2][1] * matris[0][0]);
    
        // detX = kose1 - kose2;
        // ------------------------------------------------------------------


        // int** yeniDizi = (int**)malloc(sizeof(int*));
        // DiziOlustur(yeniDizi, );
        }

        // Yontem: 2 Sarrus Metodu
        long long x = 0, y = 0;

        for(int i = 0; i < 3; i++)
        {
            x = x + matris[0][i] * matris[1][(i+1)%3] * matris[2][(i+2)%3];
            y = y + matris[2][i] * matris[1][(i+1)%3] * matris[0][(i+2)%3];
        }       
        
        return (x - y);
    }
    else
    {
        long long DetX   = 0;
        long long isaret = 1;

        long long** coFactor = (long long**)malloc(sizeof(long long));

        DiziOlustur(coFactor, boyut, boyut);

        //printf("\nDizi olusturuldu.");

        for(int satir = 0; satir < boyut; satir++)
        {
            KoFaktor(matris, coFactor, 0, satir, boyut);
            //printf("\nKoFaktoru alindi.");
            DetX += isaret * matris[0][satir]
                 *  Determinant(coFactor, (boyut - 1));
            //printf("\nDeterminant alindi.");
            isaret = -isaret;
        }
        return DetX;
    }

    
}

