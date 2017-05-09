#include <mpi.h>
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <math.h>

bool esprimo(int numero)
{
  int divisores= 0;
  double raiz = sqrt(numero);

  if (numero >2)
  {
    for(int i=1;i<=raiz;i++)
    {
      //printf("numero: %d \n",i);
      if(numero%i == 0)
      {
         divisores++;
      }
    }
    //printf("divisible: %d veces \n",divisores);
    if(divisores< 2)
    {
      return true;
    }else
    {
      return false;
    }
  }else
  {
    if(numero == 2)
    {
      return true;
    }else
    {
          return false;
    }
  }
}

int main(int argc, char *argv[])
{
  int  n, myid, numprocs, i;
  //double PI25DT = 3.141592653589793238462643;
  //double mypi, pi, h, sum, x;
  int  n1, n2, naux;
  int cont = 0;
  int source, dest, tag = 100;
  double raiz = sqrt(n2);


  n1 = 100;
  n2 = 1500;
  int total_numeros = n2 - n1;


  MPI_Status status;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  int largo_division = total_numeros/numprocs;

  printf("\nProcessor: %d,  of %d \n", myid,numprocs);



    if(myid == 0)
    {
      printf("numeros totales %d, dividido en %d partes, de %d numeros \n" ,total_numeros , numprocs, largo_division);
      for( i = n1; i<n1+largo_division ;i++)
      {
        //printf("revisando el %d \n",i);
        if(esprimo(i) == true)
        {
          cont++;
          printf("Es primo el %d \n",i);
        }
        MPI_Send(&cont, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
      }
    }else{}

    MPI_Finalize();
    printf("total de numeros primos: %d \n" ,cont );
/*
  if(myid == id)
  {
    for(int i = n1; i<n2+1;i++)
    {
        //printf("revisando el %d \n",i);
        if(esprimo(i) == true)
        {
          cont++;
          printf("Es primo el %d \n",i);
        }
    }
  }else
  {
            MPI_Send(&mypi, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  }
    printf("total de numeros primos: %d \n" ,cont );
*/
}
