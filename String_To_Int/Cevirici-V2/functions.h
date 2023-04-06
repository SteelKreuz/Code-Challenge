int kuvvet(int taban, int us)
{
    int sonuc = 1, i;

    for(i = 0; i < us; i++)
        sonuc *= taban;
    
    return sonuc;
}

int boyut(char* str, int i)
{   // gelen degerde '+' veya '-' varsa
    // i = 1 olacagindan, 1 karakter fazla
    // olacaktir. Buna dikkat ederek, basamak
    // kontrolu yapilir. Dikkat edilmez ise
    // basamak degeri, bir fazla gelecektir !!
    if (i)
    {
        int j = i + 1;
        for(; str[j] != '\0'; j++)
            i++;
    }        
    else // Degilse normal basamak kontrolu yapilir.
        for(; str[i] != '\0'; i++);

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


int yazidanSayiya(char* str)
{
    int  sayi = 0,
         i,
         kacBasamak;
    char negatifMi = 0; // varsayilan olarak, pozitif olsun.

    if (str[0] == '-')
    {   // Diziye, 1. indisten baslansin. 
        i = 1; 
        // Eger sayi, negatif ise 1(true) degeri atansin.
        negatifMi = 1;
    }
    else if (str[0] == '+')
    {   
        i = 1;
        // Eger sayi, pozitif ise 0(false) degeri atansin.
        negatifMi = 0; 
    }            
    else // Hicbiri degilse, isaret yok demektir.
        i = 0; // Ve diziye 0. indisten baslayabilir.


    kacBasamak = boyut(str, i);

    if (i) // isaretli bir sayi verildiyse
    {
        for(; i <= kacBasamak; i++)       
            sayi += rakamCevir(str[i]) * kuvvet(10, kacBasamak - i);
    }
    else  // isaretsiz bir sayi verildiyse
    {
        for(; i < kacBasamak; i++)
            sayi += rakamCevir(str[i]) * kuvvet(10, kacBasamak - (i + 1));
    }

    
    if (negatifMi)
        sayi *= -1;
    else
        sayi *= 1;
    return sayi; 
}