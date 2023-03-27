using System;
using System.Collections.Generic;
using System.Linq;
/*
 * System.Linq
 * ------------------------
static int Max(params int[] numbers)
{
    return numbers.Max();
}

Then you could call it like this: max(1, 6, 2), it allows for an arbitrary number of parameters.*/
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace odev2
{
    internal class AramaIslemleri
    {
        public AramaIslemleri()
        {
            (Bilg_Say, Elek_Say, Fizik_Say, Mat_Say) = (0, 0, 0, 0);
        }
        // Konularla ilgili terimlerin tutuldugu dizi degiskenleri
        public static string[] Bilgisayar_Kavram,
                               Elektronik_Kavram,
                               Fizik_Kavram,
                               Matematik_Kavram;

        // Yazida, konu ile ilgili kac kelime sayildigini
        // tutan sayac degiskenleri
        int Bilg_Say, Elek_Say, Fizik_Say, Mat_Say;

        string msg = @"Yazinin konusu: {0}";

        private void SayacSifirla()
        {
            (Bilg_Say, Elek_Say, Fizik_Say, Mat_Say) = (0, 0, 0, 0);
        }

        private void MetindeAra(string[] metin)
        {
            foreach (string aranan in Bilgisayar_Kavram)
            {
                foreach (string icineBak in metin)
                {
                    if (icineBak.Contains(aranan))
                    {
                        Bilg_Say++;
                    }
                }
            }

            foreach (string aranan in Elektronik_Kavram)
            {
                foreach (string icineBak in metin)
                {
                    if (icineBak.Contains(aranan))
                    {
                        Elek_Say++;
                    }
                }
            }

            foreach (string aranan in Fizik_Kavram)
            {
                foreach (string icineBak in metin)
                {
                    if (icineBak.Contains(aranan))
                    {
                        Fizik_Say++;
                    }
                }
            }

            foreach (string aranan in Matematik_Kavram)
            {
                foreach (string icineBak in metin)
                {
                    if (icineBak.Contains(aranan))
                    {
                        Mat_Say++;
                    }
                }
            }

        }

        private int EnBuyukBul()
        {
            return (new int[] { Bilg_Say, Elek_Say, Fizik_Say, Mat_Say }).Max();
        }

        private string HangiKavram(int deger)
        {
            string sonuc = "";

            if (Bilg_Say == deger)
                sonuc = "Bilgisayar";
            else if (Elek_Say == deger)
                sonuc = "Elektrik";
            else if (Fizik_Say == deger)
                sonuc = "Fizik";
            else if (Mat_Say == deger)
                sonuc = "Matematik";

            return sonuc;
        }
        public string KonuBelirle(RichTextBox YaziKutusu)
        {
            string konu = "";
            string[] yazi = YaziKutusu.Text.ToLower().Split(' ');
            // en buyuk degeri tutan degisken
            int eb;

            MetindeAra(yazi);

            eb = EnBuyukBul();

            konu = HangiKavram(eb);

            SayacSifirla();

            return String.Format(msg, konu);
        }
    }
}
