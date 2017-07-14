#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int num_procs,my_id;
  int cantidad ;
  int recibo2[66];
  int respuesta[1020];

  int num1[255], num2[255], sum[255];
  char s1[255]="627338399484900393837444599599383746458588474883837444059030384";
  char s2[255]="725739330343929902282028828202020282927116282893939405405950039398";
  int l1, l2;

  int max=66;

  MPI_Status stat;
  MPI_Init(&argc, &argv);
  // MPI_Comm_size(comm,&gsize):
  MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

  double MPI_Wtime();
	double t1 = MPI_Wtime();

  cantidad = max / num_procs;
  int recibo[cantidad];

    for (l1 = 0; s1[l1] != '\0'; l1++)
      num1[l1] = s1[l1] - '0';

    for (l2 = 0; s2[l2] != '\0'; l2++)
      num2[l2] = s2[l2] - '0';

  int carry = 0;
  int k = 0;
  int i = l1 - 1;
  int j = l2 - 1;

  MPI_Scatter(num2,cantidad,MPI_INT,&recibo,cantidad,MPI_INT,0,MPI_COMM_WORLD);

  for (; i >= 0 && j >= 0; i--, j--, k++) {
  sum[k] = (num1[i] + num2[j] + carry) % 10;
  carry = (num1[i] + num2[j] + carry) / 10;
  }
  if (l1 > l2) {

  while (i >= 0) {
  sum[k++] = (num1[i] + carry) % 10;
  carry = (num1[i--] + carry) / 10;
  }

  } else if (l1 < l2) {
  while (j >= 0) {
  sum[k++] = (num2[j] + carry) % 10;
  carry = (num2[j--] + carry) / 10;
  }
  } else {
  if (carry > 0)
  sum[k++] = carry;
  }

  MPI_Gather(sum,cantidad,MPI_INT,recibo2,cantidad,MPI_INT,0,MPI_COMM_WORLD);
  double t2 = MPI_Wtime();
	double tf = t2 - t1;

  MPI_Finalize();

  printf("Suma paralela: ");
  for (k--; k >= 0; k--)
  printf("%d", recibo2[k]);

	printf("\n El tiempo segun MPI es %f [segundos]\n", tf);

  return 0;
}
