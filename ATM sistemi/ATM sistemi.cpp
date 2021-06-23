#include <stdio.h>
#include <locale.h>
//ATM sistemi
main()
{	
setlocale(LC_ALL, "Turkish"); 
int islem,tutar, bakiye =1000; 
printf("Bakiyeniz: %d\n",bakiye);
printf("1. Para Cekme\n"); 
printf("2. Para Yatirma\n");
printf("3. Para Bakiye Sorgulama\n");
printf("4. Kart lade\n");

while(islem != 4)
{
printf("\nisleminizi giriniz: ");
scanf("%d",&islem);
switch(islem){ 
case 1:
 printf("Bakiyeniz: %d\n", bakiye);
 printf("Cekmek istediginiz tutari giriniz: "); 

 scanf("%d",&tutar);

if(tutar>bakiye) {

 printf("bakiyeniz yetersiz");
 scanf("%d",&tutar);
 bakiye -= tutar;
 printf("Yeni Bakiyeniz: %d\n",bakiye);
 printf("baska islem yapacak misiniz. cikmak icin 4e basin\n");
break;
case 2:
 printf("Bakiyeniz: %d\n", bakiye); 
 printf("Yatirmak istediginiz tutari giriniz :");
 scanf("%d",&tutar);
 bakiye+= tutar;
 printf("Yeni Bakiyeniz: %d\n", bakiye);
 printf("baska islem yapacak misiniz. cikmak icin 4e basin\n");
 break;
}
case 3: 
 printf("Bakiyeniz: %d\n", bakiye);
 break;
 } 
}
 printf("kartinizi alin ");
 
return(0);
}
