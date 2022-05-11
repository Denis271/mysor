using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            int n = 10;
            for (int i = 0; i < n; i++)
            {
                dataGridView1.Columns.Add("Column" + Convert.ToString(i),
                Convert.ToString(i + 1));//создаем и нумеруем столбец
                dataGridView1.Columns[i].Width = 40;//указываем ширину
                dataGridView1.Rows.Add();//добавляем строку
                dataGridView1.Rows[i].HeaderCell.Value =
                Convert.ToString(i + 1);//нумеруем строку

            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double usd = 0;
            double k = 0;
            double rub = 0;
            usd = Convert.ToDouble(textBox1.Text);
            k = Convert.ToDouble(textBox2.Text);
            rub = usd * k;
            label3.Visible = true;
            label3.Text = "Cумма составляет " + rub.ToString() +
            " руб.";

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            double[,] a = new double[10, 10];//объявляем массив
            richTextBox1.Clear();//очищаем поле вывода
            try //обработка исключени
            {
                //считываем с экрана массив
                for (int i = 0; i < numericUpDown1.Value; i++)
                    for (int j = 0; j < numericUpDown1.Value; j++)
                        a[i, j] =
                        Convert.ToDouble(dataGridView1.Rows[j].Cells[i].Value.ToString());
                //считываем среднее арифметическое
                double s = 0;
                for (int i = 0; i < numericUpDown1.Value; i++)
                {
                    {
                        s = 0;
                        for (int j = 0; j < numericUpDown1.Value; j++)
                        { s = s + a[i, j]; }
                        s = s / Convert.ToDouble(numericUpDown1.Value);
                        richTextBox1.Text += "Cреднее арифметическое " + (i +
                        1) + " столбца = " + s + "\n";
                    }

                }
            }
            catch (System.Exception g)//обработка пойманного
            {
                MessageBox.Show(g.Message + "\n(Ошибка вводимых параметров!)", "Ошибка!", MessageBoxButtons.OK,
            MessageBoxIcon.Error);
            }
        }

        private void файлToolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void очиститьToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();//очищаем поле вывода
            dataGridView1.Rows.Clear();
            label3.Visible = false;
            int n = 10;
            for (int i = 0; i < n; i++)
            {
                dataGridView1.Rows.Add();//добавляем строку
                dataGridView1.Rows[i].HeaderCell.Value =
                Convert.ToString(i + 1);//нумеруем строку
            }
            textBox1.Clear();
            textBox2.Clear();
            numericUpDown1.Value = numericUpDown1.Minimum;

        }

        private void задача1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            button1_Click(sender, e);
        }

        private void задача2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            button2_Click(sender, e);
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void справкаToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void оПрограммеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AboutBox1 fr2 = new AboutBox1(); // Создаем конструктор
            fr2.Show(); // Показываем вторую форму
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void tabPage3_Click(object sender, EventArgs e)
        {

        }
    } 
}


