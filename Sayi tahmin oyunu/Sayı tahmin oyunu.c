#include <math.h>
#include <stdio.h>
#include <stdlib.h>
  
/* [1, N] aral���nda sayi �reten fonksiyon ve 
�retilen sayi ile tahmin edilen say�n�n ayn�
olup olmad���n� kontrol etme */
void tahmin(int N)
{
    int sayi, tahmin, tahminsayisi = 0;
  
    // Rastgele bir sayi uret

    sayi = rand() % N;
  
    printf("1 ve %d\n Arasinda bir sayi tahmin et : ", N);
  
    // kullanici sayiyi tahmin edene kadar calisacak d�ngu 
    do {
  
        if (tahminsayisi > 9) {
            printf("\nTekrar dene!\n");
            break;
        }
  
        
        scanf("%d", &tahmin);
  
        // Kullan�c� ger�ek sayidan daha yuksek tahmin etti�inde 
        if (tahmin > sayi)
  
        {
            printf("Daha kucuk sayi dene "
                   "lutfen!\n");
            tahminsayisi++;
        }
        // Kullan�c� gerçek sayidan daha kucuk tahmin etti�inde
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
