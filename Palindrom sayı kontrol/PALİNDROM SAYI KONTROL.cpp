#include<stdio.h>
#include<conio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Turkish"); 
 int a,b,c,s=0; 
 printf(" sayi gir: ");
 scanf("%d",&a);
 c=a; 
   while(a>0) {
     b=a%10;
     s=(s*10)+b; 
     a=a/10;
   } 
  if(s ==c) {
    printf(" palindrom sayidir");
  }

 else
  printf("palindrom sayi degildir");

return(0); 
}
