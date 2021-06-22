#include <math.h>
#include <stdio.h>
#include <stdlib.h>
  
/* [1, N] aralığında sayi üreten fonksiyon ve 
üretilen sayi ile tahmin edilen sayının aynı
olup olmadığını kontrol etme */
void tahmin(int N)
{
    int sayi, tahmin, tahminsayisi = 0;
  
    // Rastgele bir sayi uret

    sayi = rand() % N;
  
    printf("1 ve %d\n Arasinda bir sayi tahmin et : ", N);
  
    // kullanici sayiyi tahmin edene kadar calisacak döngu 
    do {
  
        if (tahminsayisi > 9) {
            printf("\nTekrar dene!\n");
            break;
        }
  
        
        scanf("%d", &tahmin);
  
        // Kullanıcı gerçek sayidan daha yuksek tahmin ettiğinde 
        if (tahmin > sayi)
  
        {
            printf("Daha kucuk sayi dene "
                   "lutfen!\n");
            tahminsayisi++;
        }
        // Kullanıcı gerÃ§ek sayidan daha kucuk tahmin ettiğinde
        else if (sayi > tahmin)
  
        {
            printf("Daha yuksek sayi dene"
                   " Lutfen!\n");
            tahminsayisi++;
        }
  
        else
            printf("Dogru bilene kadar yaptigin tahmin sayisi :%d ",
                   tahminsayisi);
  
    } while (tahmin != sayi);
}
  

int main()
{
    int N = 100;
  
    
    tahmin(N);
  
    return 0;
}
