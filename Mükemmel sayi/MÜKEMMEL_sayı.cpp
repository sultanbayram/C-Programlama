#include<stdio.h>
#include<math.h>
#include <locale.h>
//MÜKEMMEL sayýlarý bulan C Programý.
int main ()
{
	setlocale(LC_ALL, "Turkish"); 
int i, j,n;
 printf("Hangi sayýya kadar olan mükkemmel sayýlarý bulmak istiyorsunuz:");
 scanf("%d",&n);
  for(i=1;i<=n; i++) {
    int sum = 0;
  for(j=1; j<i; j++) {
    if(i%j==0)
    sum=sum+j;
  }
 if (sum==i)
   printf("%d sayýsý mükemmel sayýdýr\n", i);
}

return(0);
}
