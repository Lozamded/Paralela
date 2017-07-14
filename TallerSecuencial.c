#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	//Variables para medir tiempo
	clock_t tiempo_i;
    clock_t tiempo_f;
    double m_seconds;
	
	tiempo_i = clock(); //tiempo inicial
	
	//constantes
	float a = 5;
	float b = 6;
	float c = 7;

	float array[1200];

	int i = 0;

	for(float x=0.1;x<=102;x=x+0.1)
	{
		array[i] = a*x*x + b*x + c;
		printf("numero %d : %f \n",i+1,array[i]);
		i++;  
	}

	tiempo_f = clock();//tiempo final
	m_seconds = (double) (tiempo_f - tiempo_i)/CLOCKS_PER_SEC;//tiempo de ejecución.
	printf("El tiempo de ejecucion fue %.16g [milisegundos]\n", m_seconds * 1000.0);

	return 0;

}
