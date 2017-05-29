#include <stdio.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char **argv)
{

  int ierr, num_procs, my_id=0;

  clock_t tiempo_i;
  clock_t tiempo_f;
  double m_seconds;

  MPI_Status stat;
  ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
  ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

  int x;
  int l;
  int n;
  int min = 0;
  int max = 0;
  int valores_x[4]={3,11,12,13};
  int i = 0;

  l = 20;
  n = 4;

  tiempo_i = clock();

  switch (my_id)
  {
    case 0: //Nodo maestro
      printf("La cantidad de hormigas es: %d hormigas \n", n);
      printf("La longitud del alambre es: %d [centimetros] \n", l);
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

  tiempo_f = clock();
  m_seconds = (double) (tiempo_f - tiempo_i)/CLOCKS_PER_SEC;
  printf("El tiempo de ejecucion fue %.16g [milesegundos]\n", m_seconds * 1000.0);

  ierr = MPI_Finalize();
  return 0;
}
