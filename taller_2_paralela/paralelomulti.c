#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include "string.h"
#define MAX 100000

int main(int argc, char *argv[]) {
  int num_procs,my_id;
  int cantidad ;
  char recibo2[MAX];
  int respuesta[MAX];
  char a[MAX] = "627338399484900393837444599599383746458588474883837444059030384";
  char b[MAX] = "725739330343929902282028828202020282927116282893939405405950039398";
  char c[MAX];
  char temp[MAX];

  MPI_Status stat;
  MPI_Init(&argc, &argv);
  // MPI_Comm_size(comm,&gsize):
  MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

  double MPI_Wtime();
	double t1 = MPI_Wtime();

  int la;
  la=strlen(a)-1;
  int lb;
  lb=strlen(b)-1;
  char mul[MAX];
  int i,j,k=0,x=0,y;
  long int r=0;
  long sum = 0;

  cantidad = 200 / num_procs;
  int recibo[MAX];

  for(i=0;i<=la;i++)
  {
      a[i] = a[i] - 48;
  }

  for(i=0;i<=lb;i++)
  {
      b[i] = b[i] - 48;
  }

  MPI_Scatter(b,cantidad,MPI_INT,&mul,cantidad,MPI_INT,0,MPI_COMM_WORLD);

  for(i=lb;i>=0;i--)
  {
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


  MPI_Gather(mul,cantidad,MPI_CHAR,recibo2,cantidad,MPI_CHAR,0,MPI_COMM_WORLD);

  double t2 = MPI_Wtime();
	double tf = t2 - t1;

  MPI_Finalize();

  printf("Multiplicacion paralela : ");
  printf("%s\n",recibo2);

	printf("\n El tiempo segun MPI es %f [segundos]\n", tf);

  return 0;
}
