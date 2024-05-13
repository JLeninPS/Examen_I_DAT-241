using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculadora
{
    internal class PilaNum
    {
        private static int max = 500;
        private double[] v = new double[max];
        private int tope;

        public PilaNum()
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
        public void adicionar(double elem)
        {
            if (!esLlena())
            {
                v[tope + 1] = elem;
                tope += 1;
            }
            else
                Console.WriteLine("Pila Llena...");
        }
        public double eliminar()
        {
            double elem = 0;
            if (!esVacia())
            {
                elem = v[tope];
                tope -= 1;
            }
            else
                Console.WriteLine("Pila Vacia");
            return elem;
        }
        public void vaciar(PilaNum Z)
        {
            while (!Z.esVacia())
                adicionar(Z.eliminar());
        }
    }
}
