
# Clasificacion Segun la Taxonomia de Flynn

|                    |Simple Data|Multiple Data|
|-                   |:-:        |:-:          |
|Simple Instruction  |SISD ![SISD](SISD.png)|SIMD ![SIMD](SIMD.png) [OPENMP](#openmp-simd) [MPI](#mpi-simd)  [MULTIPROCESSING](#multiprocessing-simd)|
|Multiple Instruction|MISD ![MISD](MISD.png) [OPENMP](#openmp-misd) [MPI](#mpi-misd)|MIMD ![MIMD](MIMD.png) [OPENMP](#openmp-mimd) [MPI](#mpi-mimd) [MULTIPROCESSING](#multiprocessing-mimd)|


## OPENMP
<a id="openmp-simd"></a>
**(SIMD)** OpenMP trabaja con multiples 
procesadores y el uso de la memoria es compartida, es decir una sola fuente de datos con $n$ procesadores que realizan la misma instrucción.  
<a id="openmp-misd"></a>
**(MISD)** Ademas cada procesador puede trabajar de forma independiente con instrucciones propias, es decir una sola fuente de datos con $n$ procesadores que realizan diferentes instrucciones.  
<a id="openmp-mimd"></a>
**(MIMD)** Pero ademas el uso de la memoria puede ser distribuida (cada procesador posee su propio espacio en memoria), es decir distintas fuentes de datos con $n$ proceadores que realizan diferentes instrucciones.

## MPI
<a id="mpi-mimd"></a>
**(MIMD)** MPI trabaja con multiples 
procesadores y el uso de la memoria no es compartida (cada procesador posee su propio espacio en memoria), es decir distintas fuentes de datos con $n$ proceadores que realizan diferentes instrucciones.  
<a id="mpi-misd"></a>
**(MISD)** Se podría simular una memoria compartida con el uso de mensajes **MPI_Send() y MPI_Recv()** asi, entonces cada procesador puede trabajar de forma independiente con instrucciones propias haciendo uso de una sola fuente de datos, es decir una sola fuente de datos con $n$ procesadores que realizan diferentes instrucciones.  
<a id="mpi-simd"></a>
**(SIMD)** Con el uso de mensajes **MPI_Send() y MPI_Recv()** tambien se podría simular este comportamiento una sola fuente de datos con $n$ procesadores que realizan la misma instrucción.


## MULTIPROCESSING
<a id="multiprocessing-mimd"></a>
**(MIMD)** Multiprocessing trabaja con multiples procesadores y el uso de la memoria es distribuida (cada proceso posee su propio espacio en memoria), es decir distintas fuentes de datos con $n$ proceadores que realizan diferentes instrucciones o la misma instrucción en cada proceso.  
<a id="multiprocessing-simd"></a>
**(SIMD)** Ademas multiprocessing posee una clase **SharedMemory** que permite el trabajo con memoria compartida, de esta forma cada procesador puede trabajar de forma independiente con la misma fuente de datos, es decir una sola fuente de datos con $n$ procesadores que realizan la misma instrucción.