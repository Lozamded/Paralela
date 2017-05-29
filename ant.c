#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    int x, i, l, n, min = 0, max = 0;
    clock_t tiempo_i;
    clock_t tiempo_f;
    double m_seconds;

    printf("Ingrese longitud del alambre\n");
    scanf("%d", &l);

    printf("Ingrese cantidad de hormigas\n");
    scanf("%d", &n);

    tiempo_i = clock();

    while(n--)
    {
      printf("Ingrese la ubicacíon de la hormiga %d \n",i+1);
      scanf("%d", &x);

        x = x < l-x ? x : l-x;
        if(x > min)
        {
          min = x;
        }
        if(l-x > max)
        {
          max = l-x;
        }

        i++;
    }

    printf("el tiempo minimo para que caigan todas las hormigas, es %d \n", min);
    printf("el tiempo maximo para que caigan todas las hormigas, es %d \n", max);

    tiempo_f = clock();
    m_seconds = (double) (tiempo_f - tiempo_i)/CLOCKS_PER_SEC;
    printf("El tiempo de ejecucion fue %.16g [milesegundos]\n", m_seconds * 1000.0);

    return 0;
}
