#include <stdio.h>

int main(int argc, char **argv)
{
    int x, i, l, n, min = 0, max = 0;

    printf("Ingrese longitud del alambre\n");
    scanf("%d", &l);

    printf("Ingrese cantidad de hormigas\n");
    scanf("%d", &n);

    while(n--)
    {
      printf("Ingrese las posiciones de la hormiga %d \n",i+1);
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
}
