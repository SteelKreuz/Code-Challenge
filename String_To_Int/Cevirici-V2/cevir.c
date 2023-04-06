/*  Author : Emircan CANSEVDI
 *  Created: 06.04.2023
 *
 *  C dilindeki, atoi() fonksiyonunu 
 *  canlandiran kod ornegi.
 */


#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define MAX 100

void main()
{
    char *word = (char*)malloc(MAX * sizeof(char));
    int sayi;

    printf("Metin giriniz: ");
    scanf("%s", word);

    sayi = yazidanSayiya(word);

    printf("\n\nSayi Hali: %d\n", sayi);
}
