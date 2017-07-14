#include <stdio.h>
#include <mpi.h>
#include <time.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	//Variables para medir tiempo
	clock_t tiempo_i;
    clock_t tiempo_f;
    double m_seconds;
	
	tiempo_i = clock(); //tiempo inicial
	
	//Variables de MPI
	int ierr, num_procs, my_id=0;
	MPI_Status stat;
	ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

	//Tiempo MPI
	double MPI_Wtime();
	double t1 = MPI_Wtime();

	//Variabbles del problema
	float a = 5;
	float b = 6;
	float c = 7;

	int partes = 1020/ num_procs;

	//Arreglos
	float array[1020];

	float recipiente[1020];
	float paraunion[1020];
	float recorredor[partes];

	float pre_x = 0.1;
	for(int i = 0;i<1019;i++)
	{
		array[i] =  pre_x;
		pre_x = pre_x+0.1;
	}

	MPI_Scatter(array,partes,MPI_FLOAT,&recorredor,partes,MPI_FLOAT,0,MPI_COMM_WORLD);
	
	float valor;
	for(int x = 0;x< partes ; x++ )
	{
		recipiente[x] = a * recorredor[x]*recorredor[x] + b * recorredor[x] + c;
	}

	MPI_Gather(recipiente,partes,MPI_FLOAT,paraunion,partes,MPI_FLOAT,0,MPI_COMM_WORLD);

	if (my_id==0){
		for(int i = 0; i< 1020 ; i++ )
		{
			printf("numero %d : %f \n",i,paraunion[i]);
		}	
	}
	


	ierr = MPI_Finalize();
	double t2 = MPI_Wtime();
	double tf = t2 - t1;
	printf("El tiempo segun MPI es %f [segundos] \n", tf);

	tiempo_f = clock();//tiempo final
	m_seconds = (double) (tiempo_f - tiempo_i)/CLOCKS_PER_SEC;//tiempo de ejecución.
	printf("El tiempo de ejecucion de este procesador %d fue %.16g [milisegundos]\n",my_id, m_seconds * 1000.0);

	return 0;
}
