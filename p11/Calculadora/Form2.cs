using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculadora
{
    public partial class Form2 : Form
    {
        
        public Form2() 
        {
            InitializeComponent();
        }
        private void Form2_Load(object sender, EventArgs e)
        {
            txtExpresion.Text = "0";
            lblRes.Text = "";
        }

        string s = "0";
        string val = "";
        private void button1_Click(object sender, EventArgs e)
        {
            string boton = ((Button)sender).Text;

            val += boton;
            if (boton == ".")
            {
                if (funciones.verificarPunto(val))
                    txtExpresion.Text += boton;
                val = txtExpresion.Text;
            }
            else if (txtExpresion.Text == "0")
            {
                if (boton == "0" || boton == "<×" || boton == "=" || boton == "AC")
                {
                    txtExpresion.Text = "0";
                    if (boton == "AC") lblRes.Text = "";
                }
                else if (boton == "+" || boton == "-" || boton == "×" || boton == "÷")//|| boton == ".")
                {
                    txtExpresion.Text += boton;
                }
                else
                    txtExpresion.Text = boton;
            }
            else
            {
                if (boton == "+" || boton == "-" || boton == "×" || boton == "÷") //|| boton == ".")
                {
                    if (s != "+" && s != "-" && s != "×" && s != "÷")//&& s != ".")
                    {
                        txtExpresion.Text += boton;
                    }
                }
                else if(boton == "=")
                {
                    Pila P = new Pila();
                    Pila A = new Pila();

                    P.adicionar("+");
                    string expresion = txtExpresion.Text;
                    string num = "";
                    char exp;
                    for (int i = 0; i < expresion.Length; i++)
                    {
                        exp = expresion[i];

                        if (exp != '+' && exp != '-' && exp != '×' && exp != '÷' && exp != '(' && exp != ')')
                            num += exp;
                        else if (exp == '+' || exp == '-' || exp == '×' || exp == '÷' || exp == '(' || exp == ')')
                        {
                            if (num[num.Length - 1] == '.')
                                num = num.Substring(0, num.Length - 2);
                            P.adicionar(num);
                            P.adicionar(exp + "");
                            num = "";
                        }
                    }
                    if (num != "")
                    {
                        P.adicionar(num);
                    }

                    double res = funciones.operar(P, A);

                    lblRes.Text = res.ToString();
                }
                else if(boton == "<×")
                {
                    txtExpresion.Text = funciones.borrar(txtExpresion.Text);
                }
                else if(boton == "AC")
                {
                    txtExpresion.Text = "0";
                    lblRes.Text = "";
                }
                else
                {
                    txtExpresion.Text += boton;
                }
                
            }
            s = boton;

            txtExpresion.Select(); // establecer Foco
            txtExpresion.Select(txtExpresion.Text.Length, 0);//cursor al final del textBox
        }

        private void btnOFF_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void txtExpresion_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(!funciones.esNumero(e.KeyChar))
            {
                e.Handled = true;
                return;
            }
        }
    }
}
