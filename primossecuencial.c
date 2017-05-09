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
    int  n1, n2, naux;
    int cont = 0;
    printf("ingrese primer numero");
    scanf("%d",&n1);
    printf("ingrese segundo numero");
    scanf("%d",&n2);
    double raiz = sqrt(n2);

    if(n1 > n2)
    {
      naux = n1;
      n1 = n2;
      n2 = naux;
      printf("Se procedera a invertir el intervalo  \n");
    }

    for(int i = n1; i<n2+1;i++)
    {
        //printf("revisando el %d \n",i);
        if(esprimo(i) == true)
        {
          cont++;
          printf("Es primo el %d \n",i);
        }
    }

    printf("total de numeros primos: %d \n" ,cont );
}
