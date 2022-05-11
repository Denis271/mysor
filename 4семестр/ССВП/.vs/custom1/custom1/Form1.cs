using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace custom1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
         //  168 число 100% + 20% + 28% + 5% + 15%
        {
            decimal price_retail = 0;
            decimal cost = 0;
            price_retail = price.Value * 168 / 100;
            cost = price_retail * count.Value;
            cost_label.Text = cost.ToString();
        }
    }
}
