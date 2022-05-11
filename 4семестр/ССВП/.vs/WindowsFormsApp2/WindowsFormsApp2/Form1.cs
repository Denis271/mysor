using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private double summ; //стоимость заказа
        private void Form1_Load(object sender, EventArgs e)
        {
            checkBox3.Enabled = false; //переключатель Соус недоступен
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            if (checkBox1.Checked && checkBox2.Checked && checkBox3.Checked &&
            checkBox4.Checked)
            {
                // пользователь заказал все продукты
                MessageBox.Show("Вам предоставляется скидка 10%\n" + "Стоимость заказа: " + (0.9 * summ).ToString("C"), "Кафе");
            }
            else
            {
                if (checkBox1.Checked || checkBox2.Checked || checkBox3.Checked ||
                checkBox4.Checked)
                    MessageBox.Show("Стоимость заказа : " + summ.ToString("C"), "Кафе");
                else MessageBox.Show("Вы ничего не заказали!", "Кафе");
            }
        }

        private void checkBox1_CheckedChanged_1(object sender, EventArgs e)
        {
            if (checkBox1.Checked) summ += 54.00; else summ -= 54.00;
            label2.Refresh();
            label2.Text = summ.ToString("C");
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked)
            {
                summ += 24.50;
                if (!checkBox3.Enabled) checkBox3.Enabled = true; //переключатель
}
            else
            {
                summ -= 24.50;
                if (checkBox3.Checked) checkBox3.Checked = false; //сбросили
            checkBox3.Enabled = false; //переключатель Соус недоступен
            }
            label2.Refresh();
            label2.Text = summ.ToString("C");
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked) summ += 10.50;
            else summ -= 10.50;
            label2.Refresh();
            label2.Text = summ.ToString("C");
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked) summ += 18.00;
            else summ -= 18.00;
            label2.Refresh();
            label2.Text = summ.ToString("C");
        }
        private void label1_Paint(object sender, PaintEventArgs e)
        { label2.Text = summ.ToString("C"); }
        private void label2_Paint(object sender, PaintEventArgs e)
        {
            label2.Text = summ.ToString("C");
        }
    }
}
