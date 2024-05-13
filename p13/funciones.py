import sys
from math import pow
from math import sqrt
from multiprocessing import Pool

def fibo(a: int, m: int) -> list[int]:
    v: list[int] = [0] * m
    v[0] = int(1/sqrt(5) * (pow((1 + sqrt(5))/2, a) - pow((1 - sqrt(5))/2, a)))
    v[1] = int(1/sqrt(5) * (pow((1 + sqrt(5))/2, (a + 1)) - pow((1 - sqrt(5))/2, (a + 1))))
    for i in range(2, m):
        v[i] = v[i - 1] + v[i - 2]
    return v

def main(P: int, N: int) -> None:
    m: int = 0

    P = N if N < P else P
    m = N // P if N % P == 0 else N // P + 1
    m = 2 if m == 1 else m

    intervalos: list[int] = [(m * i, m) for i in range(P)]
    # print(intervalos)
    pool: object = Pool(P)
    res: list[list[int]] = pool.starmap(fibo, intervalos)
    pool.close()
    pool.join()

    # print(res)
    count: int = 0
    sw: int = 0
    i: int = 0
    sys.stdout.write("\n")
    for lista in res:
        sys.stdout.write(f"\nProcesador {i}: ")
        for elem in lista:
            if count == N:
                sw = 1
                break
            sys.stdout.write(f"{elem}, ")
            count += 1
        i += 1
        if sw: break
# main(4, 10)