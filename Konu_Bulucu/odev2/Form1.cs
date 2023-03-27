using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace odev2
{
    public partial class Form1 : Form
    {
        string filter;

        DosyaIslemleri oku;
        AramaIslemleri Ara;
        public Form1()
        {
            InitializeComponent();
            filter = "Text Dosyalar |*.txt";
            oku = new DosyaIslemleri();
            Ara = new AramaIslemleri();
        }

        private void DosyaAc()
        {
            openFileDialog1.Title = "Text Dosyasi Sec";
            openFileDialog1.Filter = this.filter;
            openFileDialog1.FileName = "*.*";
            openFileDialog1.InitialDirectory = AppDomain.CurrentDomain.BaseDirectory;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string dosyaYolu = openFileDialog1.FileName;                

                oku.TextKutusunaYaz(dosyaYolu, richTextBox1);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            DosyaAc();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string msg = "";
            oku.KavramlariYukle();
            msg = Ara.KonuBelirle(richTextBox1);

            MessageBox.Show(msg);
        }
    }
}
