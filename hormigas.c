#include<stdio.h>
#include<stdlib.h>


typedef struct
  {
     int numero;
     int pos_inicial;
     int pos_actual;
     int direccion;

  } hormiga;

  void mostrar_hormigas(hormiga array[], int num)
  {
    for(int i = 0; i<num;i++)
    {
      printf("hormiga numero %d con pocision en %d con direccion %d que partio en %d \n", array[i].numero, array[i].pos_actual, array[i].direccion ,array[i].pos_inicial );
    }
  }

int main(int argc, char *argv[])
{
    int n_hormigas = 0;

    printf("ingrese largo del alambre ")
    scanf()

    printf("ingrese numero de hormigas");
    scanf("%d",&n_hormigas);

    hormiga hormigas[n_hormigas];

    int pos;
    for(int i = 0; i <n_hormigas; i++)
    {
        hormigas[i].numero = i+1;
        printf("ingrese pocision de la hormiga %d \n", i+1);
        scanf("%d", &pos);
        hormigas[i].pos_inicial = pos;
        hormigas[i].pos_actual = pos;
        hormigas[i].direccion = 0;
    }

    mostrar_hormigas(hormigas,n_hormigas);

}
