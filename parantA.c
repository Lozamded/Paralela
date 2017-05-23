#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{

  int ierr, num_procs, my_id=0;

  MPI_Status stat;
  ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
  ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

  int x;
  int l;
  int n;
  int min = 0;
  int max = 0;
  int valores_x[4]={11,12,3,13};
  int i = 0;

  l = 20;
  n = 4;


  switch (my_id)
  {
    case 0: //Nodo maestro
      printf("La cantidad de hormigas es: %d hormigas \n", n);
      printf("La longitud del alambre es: %d [metros] \n", l);
        //int array[2]={l,n};
    break;

    case 1:
        	//MPI_Recv(&array, 2, MPI_INT, 0, 20, MPI_COMM_WORLD, &stat);
          for(int i = 0; i<n; i++)
          {
            printf("Hormiga numero %d \n", i+1);
            x=valores_x[i];
            printf("Posicion: %d\n",x);
            x = x < l-x ? x : l-x;
            if(x > min)
            {
              min = x;
            }
          }
          printf("el tiempo minimo para que caigan todas las hormigas, es %d \n", min);
    break;

    case 2:
          //MPI_Recv(&array, 2, MPI_INT, 0, 20, MPI_COMM_WORLD, &stat);
            while(n--)
            {
              printf("Hormiga numero %d \n", i+1);
              x=valores_x[i];
              printf("Posicion: %d\n",x);
              x = l-x;
              if(l-x > max)
              {
                max = x;
              }
              i++;
            }
          printf("el tiempo maximo para que caigan todas las hormigas, es %d \n", max);
    break;
   }

  ierr = MPI_Finalize();
  return 0;

}
