#include<stdio.h>
#include<math.h>
#include <locale.h>
//M�KEMMEL say�lar� bulan C Program�.
int main ()
{
	setlocale(LC_ALL, "Turkish"); 
int i, j,n;
 printf("Hangi say�ya kadar olan m�kkemmel say�lar� bulmak istiyorsunuz:");
 scanf("%d",&n);
  for(i=1;i<=n; i++) {
    int sum = 0;
  for(j=1; j<i; j++) {
    if(i%j==0)
    sum=sum+j;
  }
 if (sum==i)
   printf("%d say�s� m�kemmel say�d�r\n", i);
}

return(0);
}
