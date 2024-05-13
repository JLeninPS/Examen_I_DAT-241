import sys
import os
from multiprocessing import Process

def serie(m: int, T: int, procesador: int) -> None:

    sys.stdout.write(f"\nProcesador: {procesador}")

    res: int = 0

    v: list[int] = [0] * m
    v[0] = (procesador * m + 1) * 2
    for i in range(1, m):
        v[i] = v[i - 1] + 2
    
    for i in range(m):
        res = v[i]
        sys.stdout.write(f"\t{v[i]} ")
        if res == T: break

def main(N: int, P: int) -> None:
    T: int = N * 2 #Ultimo valor de la serie
    m: int = 0
    # procesos: list[object] = []
    
    P = N if N < P else P
    m = N // P if N % P == 0 else N // P + 1
    P = N // m if N % m == 0 else P
    

    for i in range(P):
        proceso: object = Process(target=serie, args=(m, T, i))
        # procesos.append(proceso)
        proceso.start()
        proceso.join()

    # for proceso in procesos: