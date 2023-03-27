/* ************************************************
 * Surum 1: Kare matrisler uzerinde carpma islemi
 * yapar...
 * 
 * ***********************************************/

#include <stdio.h>

// Kare matris hesaplanir.
#define Boyut 3

void main() {

    int m1[Boyut][Boyut] = {
                         2, 5, 7,
                         3, 5, 8,
                         1, 4, 9
    };

    int m2[Boyut][Boyut] = {
                         4, 8, 1,
                         2, -3, 0,
                         1, 2, 1
    };

    int sonucMat[Boyut][Boyut];

    printf("\n\nBirinci Matris:(m1)\n");
    for (int satir = 0; satir < Boyut; satir++)
    {
        for (int sutun = 0; sutun < Boyut; sutun++)
        {
            printf("%4d", m1[satir][sutun]);
        }
        printf("\n");
    }

    printf("\n\nIkinci Matris:(m2)\n");
    for (int satir = 0; satir < Boyut; satir++)
    {
        for (int sutun = 0; sutun < Boyut; sutun++)
        {
            printf("%4d", m2[satir][sutun]);
        }
        printf("\n");
    }

    printf("\n\nMatrislerin Carpimi:\n\n");
    for (int satir = 0; satir < Boyut; satir++)
    {
        for (int sutun = 0; sutun < Boyut; sutun++) {
            int toplam, hedef;
            printf("1. matrisin %d. satir ile 2. matrisin %d. sutunu carpimi:\n", satir + 1, sutun + 1);
            printf("   m1[%d][x] x m2[x][%d] = [ ", satir, satir);
            for (toplam = 0, hedef = 0; hedef < Boyut; hedef++)
            {
                int islem = m1[satir][hedef] * m2[hedef][sutun];
                if (islem < 0)
                    printf("(%d) + ", islem);
                else
                    printf("%5d + ", islem);
                toplam += islem;
            }
            sonucMat[satir][sutun] = toplam;
            printf("\b\b] = %d\n\n\n", sonucMat[satir][sutun]);
        }
        printf("------------------------------------------------------------\n\n");
    }
    printf("\n\n");

    printf("Carpim Sonucu matris:\n");
    for (int satir = 0; satir < Boyut; satir++)
    {
        for (int sutun = 0; sutun < Boyut; sutun++)
        {
            printf("%4d", sonucMat[satir][sutun]);
        }
        printf("\n");
    }
    printf("\n\n");
}