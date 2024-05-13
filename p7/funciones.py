import sys
import time
from multiprocessing import Pool
from math import *

def sumatoria(a: int, b: int, n: int) -> float:
    res: float = 0.0
    for i in range(a, b):
        res += sqrt(pow(n, 2) - pow(i, 2))
    return res

def main(N: int, P: int) -> None:

    #--------INTERVALOS--------
    m: int = N // P#Delta X
    L: list[int] = [(m * i, m * (i + 1), N) for i in range(P)]
    #--------------------------

    t0: float = time.perf_counter()

    pool: object = Pool(P)#Pool distribuye las tareas a los P procesadores.
    R: list[float] = pool.starmap(sumatoria, L)#starmap trabaja con funciones que solicitan mas de un argumento.
    pool.close()#Apagando el grupo de procesos
    pool.join()#Esperando a que todas las tareas del grupo de procesos terminen

    pi: float = 4 / pow(N, 2) * sum(R)
    
    tf: float = time.perf_counter()

    sys.stdout.write("\n=========RESULTADO=========")
    sys.stdout.write(f"\nProcesadores: {P}")
    sys.stdout.write(f"\nTiempo: {tf - t0}")
    sys.stdout.write(f"\n\n\tPi = {pi}")
