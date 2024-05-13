import sys
import os
from funciones import main
if __name__ == "__main__":

    procesadores: int = os.cpu_count()
    
    sys.stdout.write(f"\nUsted cuenta con {procesadores} procesadores")
    sys.stdout.write(f"\nCuantos desea utilizar?: ")
    P: int = int(sys.stdin.readline())
    
    sys.stdout.write("\nIntroducir cantidad de terminos (N): ")
    N: int = int(sys.stdin.readline())
    # N: int = 1000
    
    main(P, N)