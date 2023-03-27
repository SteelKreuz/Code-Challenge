using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Piyano
{
    public partial class Kayit_Ekrani : Form
    {
        Dosya_islemleri Yap2;
        public Kayit_Ekrani()
        {
            InitializeComponent();
            Yap2 = new Dosya_islemleri();
        }

        private void Isim_Kaydet_Click(object sender, EventArgs e)
        {   // Kayit ismi, dizin ismidir.
            //string yol = "\\" + Yap2.DizinAd;

            Dosya_islemleri.gecici_Dizin_Isim = textBox1.Text.Trim(); 

            Yap2.DizinOlustur(Yap2.DizinAd);
            Yap2.DosyaOlustur(Yap2.DosyaAd);
            this.Close();
            
        }
    }
}
