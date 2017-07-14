#include<stdio.h>
#include<string.h>
#include<time.h>

int main()
{

  //Variables para medir tiempo
  clock_t tiempo_i;
  clock_t tiempo_f;
  double m_seconds;

tiempo_i = clock(); //tiempo inicial

int num1[255], num2[255], sum[255];
int l1, l2;

char s1[255] = "627338399484900393837444599599383746458588474883837444059030384";
char s2[255] = "725739330343929902282028828202020282927116282893939405405950039398";

/* convert character to integer*/

for (l1 = 0; s1[l1] != '\0'; l1++)
num1[l1] = s1[l1] - '0';
for (l2 = 0; s2[l2] != '\0'; l2++)
num2[l2] = s2[l2] - '0';

int carry = 0;
int k = 0;
int i = l1 - 1;
int j = l2 - 1;

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

printf("Suma secuencial : ");
for (k--; k >= 0; k--)
printf("%d", sum[k]);

tiempo_f = clock();//tiempo final
m_seconds = (double) (tiempo_f - tiempo_i)/CLOCKS_PER_SEC;//tiempo de ejecución.
printf("\nEl tiempo de ejecucion fue %.16g [segundos]\n", m_seconds * 100.0);

return 0;
}
