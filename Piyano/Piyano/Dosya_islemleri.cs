using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Piyano
{
    internal class Dosya_islemleri
    {
        public Dosya_islemleri()
        {
            dosyaAd  = "Basilan_Tuslar";
            dizinAd  = "Notalar";
            dizinYol = string.Empty;
            dosyaYol = string.Empty;            
        }

        #region Degiskenler
        private FileStream Dosya;
        private StreamWriter Yazici;
        private StreamReader Okuyucu;
        // Yazici icin:
        public static string gecici_Dizin_Isim;
        //Okuyucu icin:
        public static string gecici_Dizin_Isim2;
        private string dosyaAd,
                       dizinAd,
                       dizinYol,
                       dosyaYol;
        #endregion

        #region Getter ve Setter Properties

            #region Dosya adi
            public string DosyaAd
            {
                get
                {
                    return dosyaAd;
                }
                set
                {
                    // Ozellik eklenebilir...
                }
            }
            #endregion

            #region Dizin Ad
            public string DizinAd
            {
                get
                {
                    return dizinAd;
                }
                set
                {
                    // Ozellik eklenebilir...
                }
            }
            #endregion

            #region Dizin Yolu
            public string DizinYol
            {
                get
                {
                    return dizinYol;
                }
                set
                {
                    // Ozellik eklenebilir...
                }
            }
        #endregion

            #region Dosya Yolu
            public string DosyaYolu
            {
                get
                {
                    return dosyaYol;
                }
                set
                {
                    // Ozellik eklenebilir...
                }
            }
        #endregion

        #endregion

        #region Mevcut Konumu Gosteren Method
        private string Mevcut_Konum()
        {
            return AppDomain.CurrentDomain.BaseDirectory;
        }
        #endregion
        
        #region Dizin Olusturma
        public void DizinOlustur(string dizinAdi)
        {
  
            this.dizinYol = Mevcut_Konum() + "\\" 
                          + dizinAdi
                          + "\\" + gecici_Dizin_Isim;

            Directory.CreateDirectory(this.dizinYol);
 

        }
        #endregion

        #region Dosya Olusturma
        public void DosyaOlustur(string dosyaAdi)
        {
            this.dosyaYol = this.dizinYol + "\\" + dosyaAdi + ".txt";
            bool dosyaVarMi = File.Exists(this.dosyaYol);

            if (!dosyaVarMi)
            {
                Dosya = File.Create(this.dosyaYol);
                Dosya.Close();
            }
        }
        #endregion

        #region Hata Yazdiran Metot
        private void HataYazdir(Exception Ex)
        {
            string hataMesaj = "Hata Gerceklesti !"
                             + Environment.NewLine
                             + "Hata Aciklamasi:"
                             + Environment.NewLine
                             + Ex.Message;
            MessageBox.Show(hataMesaj);
        }
        #endregion

        #region Yazma Islemini Baslat
        private void YaziciBaslat()
        {
            try
            {                
                this.dizinYol = Mevcut_Konum() + "\\"
                              + this.dizinAd
                              + "\\" + gecici_Dizin_Isim;

                this.dosyaYol = this.dizinYol + "\\" + this.dosyaAd + ".txt";

                // Eger dosya varsa, ustune yazsin diye
                // 2. parametre true
                this.Yazici = new StreamWriter(this.dosyaYol, true);
            }
            catch (Exception Ex)
            {
                HataYazdir(Ex);                
            }
        }
        #endregion

        #region Yazma Islemini Bitir
        private void YaziciKapat()
        {
            this.Yazici.Close();
        }
        #endregion

        #region Dosyaya Veri Yazan Metot
        public void DosyaVeriYaz(string Veri)
        {
            #region Alternatif Yol 1: Su an kullanilan yontem !!        
            string msg;
            try
            {
                YaziciBaslat();
                msg = Veri + " ";
                this.Yazici.Write(msg);
            }
            catch (Exception Ex)
            {
                HataYazdir(Ex);
            }
            finally
            {
                YaziciKapat();
            }
            #endregion

            #region Alternatif Yol 2:
            /*
            try
            {
                File.WriteAllText(this.dosyaYol, Veri);
            }
            catch(Exception Ex)
            {
                HataYazdir(Ex);
            }
            */
            #endregion

        }
        #endregion

        #region Okuma Islemini Baslat
        private void OkuyucuBaslat()
        {
            string Yol = Mevcut_Konum() + "\\" + this.dizinAd
                       + "\\" + gecici_Dizin_Isim2 + "\\"
                       + this.dosyaAd + ".txt";
            Okuyucu = new StreamReader(Yol);            
        }
        #endregion

        #region Dosya Icerigini Okuyan Method
        public string DosyaOkuma()
        {
            OkuyucuBaslat();
            return Okuyucu.ReadToEnd();
        }
        #endregion
    
    }
}
