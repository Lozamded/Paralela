#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 1000

int main()
{
  //Variables para medir tiempo
  clock_t tiempo_i;
  clock_t tiempo_f;
  double m_seconds;

  char a[MAX] = "627338399484900393837444599599383746458588474883837444059030384";
  char b[MAX] = "725739330343929902282028828202020282927116282893939405405950039398";
  char c[MAX];
  char temp[MAX];
  int la=strlen(a)-1;
  int lb=strlen(b)-1;

  char mul[MAX]; //static

  int i,j,k=0,x=0,y;
  long int r=0;
  long sum = 0;

  for(i=0;i<=la;i++)
  {
      a[i] = a[i] - 48;

  }

  for(i=0;i<=lb;i++)
  {
      b[i] = b[i] - 48;
  }

  for(i=lb;i>=0;i--)
  {
    //printf("k antes del for: %d ",k);
       r=0;
       for(j=la;j>=0;j--)
       {
           temp[k++] = (b[i]*a[j] + r)%10;
           //printf("temp[%d] = %d",k,temp[k]);
           //printf("k en el primer for: %d ",k);
           r = (b[i]*a[j]+r)/10;
       }
       temp[k++] = r;
      // printf("k al salir del for %d ",k);
       x++;
       for(y = 0;y<x;y++)
       {
           temp[k++] = 0;
          // printf("temp[%d] = %d",k,temp[k]);
           //printf("k en el segundo for %d \n",k);
       }
  }

  k=0;
  r=0;
  for(i=0;i<la+lb+2;i++){
       sum =0;
       y=0;
       for(j=1;j<=lb+1;j++){
           if(i <= la+j){
               sum = sum + temp[y+i];
           }
           y += j + la + 1;
       }
       c[k++] = (sum+r) %10;
       r = (sum+r)/10;
  }
  c[k] = r;
  j=0;
  for(i=k-1;i>=0;i--){
       mul[j++]=c[i] + 48;
  }
  mul[j]='\0';

  printf("Multiplicacion secuencial : ");
  printf("%s\n",mul);

  tiempo_f = clock();//tiempo final
  m_seconds = (double) (tiempo_f - tiempo_i)/CLOCKS_PER_SEC;//tiempo de ejecución.
  printf("\nEl tiempo de ejecucion fue %.16g [segundos]\n", m_seconds * 100.0);

  return 0;
}
