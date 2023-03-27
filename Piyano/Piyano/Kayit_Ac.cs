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
    public partial class Kayit_Ac : Form
    {
        public Kayit_Ac()
        {
            InitializeComponent();
        }

        private void Kayit_Ac_btn_Click(object sender, EventArgs e)
        {
            try
            {
                Dosya_islemleri.gecici_Dizin_Isim2 = textBox1.Text.Trim();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                this.Close();
            }
        }
    }
}
