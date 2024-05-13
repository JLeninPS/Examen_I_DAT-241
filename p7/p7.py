import sys
import multiprocessing
from funciones import *

if __name__ == "__main__":
    
    PROCESADORES: int = multiprocessing.cpu_count()

    sys.stdout.write("\nUsted cuenta con " + str(PROCESADORES) + " Procesadores.")  
    sys.stdout.write("\n¿Cuantos desea usar? ")
   
    P: int = int(sys.stdin.readline())
    N: int = 10_000_000
    
    #Validando uso de procesadores
    P = P if (P < PROCESADORES and P > 0) else PROCESADORES

    main(N, P)
