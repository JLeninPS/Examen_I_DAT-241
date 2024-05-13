using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculadora
{
    internal class Pila
    {
        private static int max = 500;
        private string[] v = new string[max];
        private int tope;

        public Pila()
        {
            tope = 0;
        }
        public Boolean esVacia()
        {
            if (tope == 0)
                return true;
            return false;
        }
        public Boolean esLlena()
        {
            if (tope == max) 
                return true;
            return false;
        }
        public int numElementos()
        {
            return tope;
        }
        public void adicionar(string elem)
        {
            if (!esLlena())
            {
                v[tope + 1] = elem;
                tope += 1;
            }
            else
                Console.WriteLine("Pila Llena...");
        }
        public string eliminar()
        {
            string elem = "";
            if (!esVacia())
            {
                elem = v[tope];
                tope -= 1;
            }
            else
                Console.WriteLine("Pila Vacia");
            return elem;
        }
        public void vaciar(Pila Z)
        {
            while(!Z.esVacia())
                adicionar(Z.eliminar());
        }
    }
}
