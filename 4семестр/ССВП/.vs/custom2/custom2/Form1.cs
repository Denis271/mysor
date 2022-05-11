using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace custom2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        public void errorsQuestion(Label label)
        {
            label.ForeColor = Color.Red;
        }
        public void goodQuestion(Label label)
        {
            label.ForeColor = Color.Green;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int ball = 0;

            if (radioButton2.Checked)
            {
                ball++;
                goodQuestion(label_question_1);
            }
            else
            {
                errorsQuestion(label_question_1);
            }
           
            if (radioButton6.Checked)
            {
                ball++;
                goodQuestion(label_question_2);
            }
            else
            {
                errorsQuestion(label_question_2);
            }
            
            if (radioButton9.Checked)
            {
                ball++;
                goodQuestion(label_question_4);
            }
            else
            {
                errorsQuestion(label_question_4);
            }


            if (textBox1.Text == "988")
            {
                ball++;
                goodQuestion(label_question_3);
            }
            else
            {
                errorsQuestion(label_question_3);
            }
            
            if (textBox2.Text == "1933")
            {
                ball++;
                goodQuestion(label_question_7);
            }
            else
            {
                errorsQuestion(label_question_7);
            }

            if (radioButton10.Checked)
            {
                ball++;
                goodQuestion(label_question_5);
            }
            else
            {
                errorsQuestion(label_question_5);
            }

            if (checkBox1.Checked && checkBox7.Checked)
            {
                ball++;
                goodQuestion(label_question_6);
            }
            else
            {
                errorsQuestion(label_question_6);
            }

            if (checkBox8.Checked && checkBox4.Checked)
            {
                ball++;
                goodQuestion(label_question_8);
            }
            else
            {
                errorsQuestion(label_question_8);
            }

            if (textBox3.Text == "1380")
            {
                ball++;
                goodQuestion(label_question_9);
            }
            else
            {
                errorsQuestion(label_question_9);
            }

            if (radioButton13.Checked)
            {
                ball++;
                goodQuestion(label_question_10);
            }
            else
            {
                errorsQuestion(label_question_10);
            }
            label_result.Text = "Успех - " + (ball * 100 / 10).ToString() + "%";
            button1.Enabled = false;

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label_result_Click(object sender, EventArgs e)
        {

        }
    }
}
