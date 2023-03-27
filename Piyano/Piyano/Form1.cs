using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
// Ses dosyalarini oynatmak icin gerekli olan namespace:
using System.Media;

// ---------------------------------------------------- 
/*
 *   Tarih: 17.02.2023
 *
 *   Aciklama: Notalar, "Notalar" dizini altinda;
 *   belirlenen kayit adi ile olusturulmus dizinde
 *   tutuluyor...
 */
// ---------------------------------------------------- 

namespace Piyano
{
    public partial class Form1 : Form
    {
        // Dosya islemlerini yapacak olan,
        // nesnemizi tanimladik.
        Dosya_islemleri Yap;
        public Form1()
        {
            InitializeComponent();
            
            
            Yap = new Dosya_islemleri();
            sira = -1;
        }
        private string msg;
        public string Msg
        {
            get {
                return       "Öğrenci:"
                           + Environment.NewLine
                           + "No: 1"
                           + Environment.NewLine
                           + "Ad Soyad: Emircan CANSEVDİ"
                           + Environment.NewLine
                           + "Sinif:2";
            }
        }
        // Kayitli notalar, bu degiskende tutulacak.
        static string[] Kayit_Notalar;
        
        // Hangi notada kaldigini tutan degisken
        static sbyte sira;

        string[] Notalar = { "C", "C_s", "D", "D_s",
                             "E", "F", "F_s", "G",
                             "G_s", "A", "A_s", "B"
                           };

        #region Ses Dosyasi Oynatma Metodu
        public void Oynat(string Note)
        {
            /*
             * SoundPlayer ismindeki siniftan
             * turetilen bir nesne ile; (Notes)
             * 
             * Resource'dan aldigimiz ses dosyasini
             * oynatabiliyoruz.
             */
            SoundPlayer Notes;
            switch (Note)
            {
                case "C": 
                    Notes = new SoundPlayer(Piyano.Resource1.C);
                    Notes.Play();
                    break;
                case "C_s":
                    Notes = new SoundPlayer(Piyano.Resource1.C_s);
                    Notes.Play();
                    break;
                case "D":
                    Notes = new SoundPlayer(Piyano.Resource1.D);
                    Notes.Play();
                    break;
                case "D_s":
                    Notes = new SoundPlayer(Piyano.Resource1.D_s);
                    Notes.Play();
                    break;
                case "E":
                    Notes = new SoundPlayer(Piyano.Resource1.E);
                    Notes.Play();
                    break;
                case "F":
                    Notes = new SoundPlayer(Piyano.Resource1.F);
                    Notes.Play();
                    break;
                case "F_s":
                    Notes = new SoundPlayer(Piyano.Resource1.F_s);
                    Notes.Play();
                    break;
                case "G":
                    Notes = new SoundPlayer(Piyano.Resource1.G);
                    Notes.Play();
                    break;
                case "G_s":
                    Notes = new SoundPlayer(Piyano.Resource1.G_s);
                    Notes.Play();
                    break;
                case "A":
                    Notes = new SoundPlayer(Piyano.Resource1.A);
                    Notes.Play();
                    break;
                case "A_s":
                    Notes = new SoundPlayer(Piyano.Resource1.A_s);
                    Notes.Play();
                    break;
                case "B":
                    Notes = new SoundPlayer(Piyano.Resource1.B);
                    Notes.Play();
                    break;
            }
        }
        #endregion

        #region Click olaylarinin yapildigi Method:
        // 0 - 255 arasi nota alabilir.
        public void OynatVeYaz(byte indis)
        {
            string note = Notalar[indis];
            Oynat(note);
            
            if (Kayit_Durum.Checked)
                Yap.DosyaVeriYaz(note);
        }
        #endregion

        #region Piyano Button Click Olaylari
        private void C_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(0);
        }

        private void C_s_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(1);
        }

        private void D_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(2);
        }

        private void D_s_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(3);
        }

        private void E_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(4);
        }

        private void F_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(5);
        }

        private void F_s_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(6);
        }

        private void G_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(7);
        }

        private void G_s_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(8);
        }

        private void A_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(9);
        }

        private void A_s_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(10);
        }

        private void B_btn_Click(object sender, EventArgs e)
        {
            OynatVeYaz(11);
        }
        #endregion

        #region Kayit Oynatma Methodu
        private void Cagir(string Tus)
        {
            switch (Tus)
            {
                case "C":
                    C_btn.Focus();
                    C_btn.PerformClick(); 
                    break;
                case "C_s":
                    C_s_btn.Focus();
                    C_s_btn.PerformClick();
                    break;
                case "D":
                    D_btn.Focus();
                    D_btn.PerformClick();
                    break;
                case "D_s":
                    D_s_btn.Focus();
                    D_s_btn.PerformClick();
                    break;
                case "E":
                    E_btn.Focus();
                    E_btn.PerformClick();
                    break;
                case "F":
                    F_btn.Focus();
                    F_btn.PerformClick();
                    break;
                case "F_s":
                    F_s_btn.Focus();
                    F_s_btn.PerformClick();
                    break;
                case "G":
                    G_btn.Focus();
                    G_btn.PerformClick();
                    break;
                case "G_s":
                    G_s_btn.Focus();
                    G_s_btn.PerformClick();
                    break;
                case "A":
                    A_btn.Focus();
                    A_btn.PerformClick();
                    break;
                case "A_s":
                    A_s_btn.Focus();
                    A_s_btn.PerformClick();
                    break;
                case "B":
                    B_btn.Focus();
                    B_btn.PerformClick();
                    break;
            }
        }
        #endregion
       
        private void Button_Durum(bool durum)
        {
            Baslat_btn.Visible = durum;
            Baslat_btn.Enabled = durum;
            Durdur_btn.Visible = durum;
            Durdur_btn.Enabled = durum;
            //Devam_btn.Visible = durum;
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            Kayit_Son.Enabled = false; // Checkbox
            menuStrip1.BackColor = Color.Black;
            timer1.Interval = 2000;
            timer1.Enabled = false;

            Button_Durum(false);
            Devam_btn.Visible = false;
            Kayit_Kapat_btn.Visible = false;

            if (Kayit_Durum.Checked)
            {
                Yap.DizinOlustur(Yap.DizinAd);
                Yap.DosyaOlustur(Yap.DosyaAd);
            }               
        }

        private void Kayit_Durum_CheckedChanged(object sender, EventArgs e)
        {
            if (Kayit_Durum.Checked)
            {
                Kayit_Son.Enabled = true;
                Kayit_Ac.Visible = false;
                Kayit_Ekrani Kayit = new Kayit_Ekrani();
                Kayit.Show();
                Kayit_Durum.Enabled = false;
            }
            else
            {                
                Kayit_Ac.Visible = true;
            }
            
        }

        private void Kayit_Ac_Click(object sender, EventArgs e)
        {
            Button_Durum(true);
            
            Kayit_Ac open = new Kayit_Ac();
            open.Show();

            Kayit_Durum.Visible = false;
            Kayit_Son.Visible = false;
            Kayit_Kapat_btn.Visible = true;
            Kayit_Ac.Visible = false;
            
        }

        private void Baslat_btn_Click(object sender, EventArgs e)
        {
            Kayit_Notalar = Yap.DosyaOkuma().Split(' ');
            Baslat_btn.Enabled = false;
            timer1.Start();
        }

        private void Durdur_btn_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            Devam_btn.Visible = true;
            Durdur_btn.Enabled = false;
        }

        private void Devam_btn_click(object sender, EventArgs e)
        {
            Devam_btn.Visible = false;
            Durdur_btn.Enabled = true;
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (Kayit_Notalar.Length > ++sira)
                Cagir(Kayit_Notalar[sira]);
            else
            {
                Baslat_btn.Enabled = true;
                Devam_btn.Visible = false;
                
                sira = -1;
                timer1.Stop();
            }
                
        }

        private void Kayit_Kapat_btn_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            sira = -1;
            // Kayit kapatildigindan, notalari da
            // hafizadan silinir.
            Kayit_Notalar = null;

            Button_Durum(false);

            Kayit_Ac.Visible = true;
            Kayit_Durum.Visible = true;
            Kayit_Son.Visible = true;
            Devam_btn.Visible = false;
            Kayit_Kapat_btn.Visible = false;            
        }

        private void hakkındaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show(Msg, "Hakkımda", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void Kayit_Son_CheckedChanged(object sender, EventArgs e)
        {
            if (Kayit_Son.Checked)
            {
                Kayit_Durum.Enabled = true;
                Kayit_Durum.Checked = false;
                Kayit_Ac.Visible = true;
                Kayit_Son.Enabled = false;
                Kayit_Son.Checked = false;
            }
        }
    }
}
