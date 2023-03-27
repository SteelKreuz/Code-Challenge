using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;

namespace odev2
{
    internal class DosyaIslemleri
    {
        string PC_Yol, elek_Yol, fizik_Yol, mat_Yol;
        private string MevcutKonum()
        {
            return AppDomain.CurrentDomain.BaseDirectory;
        }
        private void YolBelirle()
        {
            PC_Yol = MevcutKonum() + "Bilgisayar_Terimleri.txt";
            elek_Yol = MevcutKonum() + "Elektronik_Terimler.txt";
            fizik_Yol = MevcutKonum() + "Fizik_Terimleri.txt";
            mat_Yol = MevcutKonum() + "Matematik_Terimleri.txt";
        }
        public void TextKutusunaYaz(string Yol, RichTextBox YaziKutusu)
        {
            StreamReader oku = new StreamReader(Yol);
            string satir;

            while((satir = oku.ReadLine()) != null)
            {
                YaziKutusu.Text += satir + Environment.NewLine;
            }
            oku.Close();
        }

        private string[] DegerleriAl(string yol)
        {
            string yazi = "", satir;
            StreamReader oku = new StreamReader(yol);

            while ((satir = oku.ReadLine()) != null)
                yazi += satir.ToLower() + " ";

            oku.Close();
            return yazi.Split(' ');
        }

        public void KavramlariYukle()
        {
            YolBelirle();

            AramaIslemleri.Bilgisayar_Kavram = DegerleriAl(PC_Yol);
            AramaIslemleri.Elektronik_Kavram = DegerleriAl(elek_Yol);
            AramaIslemleri.Matematik_Kavram  = DegerleriAl(mat_Yol);
            AramaIslemleri.Fizik_Kavram      = DegerleriAl(fizik_Yol);
        }
    }
}
