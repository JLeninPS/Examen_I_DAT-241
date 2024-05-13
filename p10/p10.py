import sys
import multiprocessing
from funciones import main

if __name__ == "__main__":
    PROCESADORES: int = multiprocessing.cpu_count()
    
    sys.stdout.write("\nUsted cuenta con " + str(PROCESADORES) + " Procesadores.")  
    sys.stdout.write("\n¿Cuantos desea usar?: ")
   
    P: int = int(sys.stdin.readline())
    #Validando uso de procesadores
    P = P if (P < PROCESADORES and P > 0) else PROCESADORES

    sys.stdout.write("\nIntroducir tamanio de la serie (N): ")
    N: int = int(sys.stdin.readline())
    

    main(N, P)