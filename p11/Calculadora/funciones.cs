using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculadora
{
    internal class funciones
    {
        public static string borrar(string cad)
        {
            string expresion = cad;
            int tam = expresion.Length;

            if (tam == 1)
            {
                return "0";
            }
            else
            {
                return expresion.Substring(0, tam - 1);
            }
        }
        public static bool esNumero(char cad)
        {
            if (cad == '.')
                return true;

            int x = cad;
            if (x > 57 || x < 48)
                return false;
            return true;
        }
        public static bool verificarPunto(string val)
        {
            int c = 0; 
            int tam = val.Length;
            for(int i = 0; i < tam; i++)
            {
                if (!esNumero(val[i]))
                {
                    c = 0;
                }
                if (val[i] == '.')
                {
                    c++;
                }
                if (c > 1)
                {
                    return false;
                }
            }
            return true;
        }
        //public static double operarRecursive(Pila P, Pila PC, double res = 0.0)
        //{
        //    string num = P.eliminar();
        //    if (num != "(")
        //    {
        //        res = operarRecursive(P, PC, res);
        //    }
        //    return res;

            
        //    return res;
        //}
        public static double operar(Pila P, Pila PC)
        {
            double a, b, res, resPC;
            string elem, num, op, op1;

            elem = P.eliminar();
            if (esNumero(elem[0]))
                P.adicionar(elem);
            
            resPC = 1.0;
            res = 0.0;
            while (!P.esVacia())
            {
                num = P.eliminar();
                op = P.eliminar();    
                
                if (op == "×" || op == "÷")
                {
                    PC.adicionar(op);
                    PC.adicionar(num);
                }
                else if (op == "+" || op == "-")
                {
                    a = Convert.ToDouble(num);
                    if (PC.esVacia())
                    {
                        if (op == "+") res += a;
                        else res -= a;
                    }
                    else
                    {
                        while (!PC.esVacia())
                        {
                            num = PC.eliminar();
                            op1 = PC.eliminar();
                            b = Convert.ToDouble(num);
                            if (op1 == "×") resPC *= b;
                            else resPC *= 1 / b;
                        }
                        if (op == "+") resPC *= a;
                        else resPC = resPC * (-a);
                        res += resPC;
                        resPC = 1.0;
                    }
                }
            }
            return res;
        }
    }
}
