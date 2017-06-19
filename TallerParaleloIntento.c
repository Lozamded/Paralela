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

	double partes = 1020/ (float)num_procs;
	double subpartes = partes/100;
	int resto = 1020%num_procs;


	typedef struct{
		float inicio;
		float fin;
		int contador;
	}node;

	float array[1020];

	node *p;
	p = malloc(sizeof(node)*num_procs);

				for(int i = 0; i<num_procs;i++)
				{
					if(i == 0)
					{
							p[i].inicio = 0.1;
							p[i].fin = partes * 0.1;
							p[i].contador = 1;
					}else
					{
							p[i].inicio = p[i-1].fin + 0.1;
							p[i].fin = p[i].inicio + (partes * 0.1) - 0.1;
							p[i].contador = p[i-1].contador + 254; 
					}

					printf("caso %d inicio %f final %f \n",i+1,p[i].inicio,p[i].fin);
				}
	
	for(int j = 0 ; j <= num_procs; j++)
	{
		printf("Procesador %d \n",my_id);

		int i = 0;
		float valor = 0;
		int contador = p[my_id].contador;

		for(float x = p[my_id].inicio;x<=p[my_id].fin; x = x+0.1 )
		{
			printf("Procesador %d ",my_id);
			valor = a*x*x + b*x + c;
			//printf("numero %d : %f \n",i+1,valor);
			array[contador-1]=valor;
			contador++;
			i++;
		}

	}

	for(int i;i<1021;i++)
	{
		printf("numero %d : %f \n",i+1,array[i]);
	}
/*
	if (resto == 0)
	{
		switch (my_id)
		{
			case 0:
				printf("se cuenta con %d procesadores ",num_procs );
				printf("entonces son %f para numeros cada procesador \n",partes);

			break;

			default:

			break;
		}

	}else
	{

	}
*/
	ierr = MPI_Finalize();

	double t2 = MPI_Wtime();
	double tf = t2 - t1;
	printf("El tiempo segun MPI es %f [segundos] \n", tf);

	tiempo_f = clock();//tiempo final
	m_seconds = (double) (tiempo_f - tiempo_i)/CLOCKS_PER_SEC;//tiempo de ejecución.
	printf("El tiempo de ejecucion de este procesador %d fue %.16g [milisegundos]\n",my_id, m_seconds * 1000.0);

	return 0;
}
