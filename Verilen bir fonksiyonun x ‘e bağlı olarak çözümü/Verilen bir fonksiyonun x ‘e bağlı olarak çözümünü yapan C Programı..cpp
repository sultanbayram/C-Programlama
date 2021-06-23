#include<stdio.h>
#include<math.h.>
//Verilen bir fonksiyonun x ‘e baðlý olarak çözümünü yapan C Programý.
int main ()
{
float x,y;
printf("x degerini tuslayiniz:");
scanf ("%2f", &x);
 if (x <=0){
  y=0;
 }
 else {
  if (x>0 && x <=10){
    y=3/sqrt(pow (x,3)+1);
  }
 else { 
 y=cos(x)+2*pow (x,2);
 }
} 
printf ("sonuc=%f", y);

return (0);
}
