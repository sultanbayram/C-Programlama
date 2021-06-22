#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char ch[10][130]={"KamilKoc","Pamukkale","Oz Bilecik","Istanbul Seyahat","Metro Turizm","Nilufer"};
char ad[32][100]={'\0'};
char numara[32][2]={'\0'};
int num1[32]={0};
int trno;
void otobus();//otobus listesi icin
void ad_numarasi(int rezervasyon,char numstr[100]);
void rezervasyon();//bilet rezervasyonu icin
int numarayi_oku(int trno);//dosyadan numarayi okumak icin
void adi_oku(int trno);//dosyadan ismi okumak icin
void durum();//durumu kullanici girisiyle yazdirmak icin
void durum_1(int trno);//rezervasyon bileti sirasinda durum yazdirmak icin
void iptal();

int main()
{
	setlocale(LC_ALL, "Turkish");
	login();
    int num,i;
  do{
    system("cls");
    printf("\n\n\n");
    printf("====================================== OTOBUS REZERVASYON SISTEMI'NE HOS GELDINIZ ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> Otobus Listesini Goruntule\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Bilet Rezervasyonu\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Rezervasyon iptali\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Otobus Durum Panosu\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> Cikis\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tSecimini gir:: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        otobus();//otobus listesi icin
        break;
    case 2:
        rezervasyon();//rezervasyon icin biletler
        break;
    case 3:
        iptal();
        break;
    case 4:
        durum();
        break;
    }
getch();
    }while(num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tBu Sistemi Kullandiginiz Icin Tesekkur Ederiz\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
    return 0;
}


void otobus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== OTOBUS REZERVASYON SISTEMI ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n"); 
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n"); 
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n"); 
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}

void rezervasyon()
{

    int i=0;
    char numstr[100];
system("cls");
printf("=========================================== OTOBUS REZERVASYON SISTEMI ============================================\n\n\n");
otobus();
printf("Otobus numarasini girin:--->");
scanf("%d",&trno);
system("cls");
printf("=========================================== OTOBUS REZERVASYON SISTEMI ============================================\n\n\n");
printf("Otobus Numaraniz%d ********** %s",trno,ch[trno-1]);
durum_1(trno);
 FILE *f1, *fopen();//koltuklari kullanicidan okumak icin.
 char str1[80]="32",str2[4],str3[4];
 int koltuk1,koltuk2,rezervasyon=0;
if(trno == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
koltuk1=atoi(str1);
if(koltuk1 <= 0)
{
 printf("Bu otobusta bos koltuk yok ");
}else
{
printf("\n\n\n\t\t\t\tMevcut Koltuklar:------>%d\n",koltuk1);
printf("\n\t\t\t\tBilet Sayisi:----->");
scanf("%d",&rezervasyon);
printf("\n");

koltuk1=koltuk1-rezervasyon;
itoa(trno,numstr,10);
ad_numarasi(rezervasyon,numstr);
printf("\n\t\t\t\tToplam rezervasyon rezervasyon tutari %d",200*rezervasyon);
itoa(koltuk1, str1, 10);

if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(trno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}
}



void ad_numarasi(int rezervasyon,char numstr[100])
{
char tempstr[100],tempstr1[12]="durum",tempstr2[12]="numara";
int numara;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");//dosyayi acmak icin adi dosyaya yazmak icin
   b = fopen(tempstr2,"a");//dosyaya sayý yazmak icin dosyayi acmak icin
for(i=0; i<rezervasyon; i++)//kisi adi ve koltuk numarasini dosyaya girmek icin
{
   printf("============================Bilet no icin ayrintilari girin %d============================\n\n\n",i+1);
      printf("\t\t\t\tkoltuk numarasini girin:--->");
      scanf("%d",&numara);
      printf("\t\t\t\tkisinin adini girin:--->");
      scanf("%s",ad[numara-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(numara, tempstr, 10);
      fprintf(a,"%s ",ad[numara-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int numarayi_oku(int trno)//diziye sayisal degeri koymak icin
{
char tempstr[100],tempstr2[12]="numara";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//dosyayi acmak icin adi dosyaya yazmak icin
   while(!feof(a))
   {
      numara[i][j] = fgetc(a);

      if(numara[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(numara[i]);
   }
   fclose(a);
   return k;
}


void adi_oku(int trno)//diziye sayisal degeri koymak icin
{
char tempstr1[12]="durum";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//dosyayi acmak icin adi dosyaya yazmak icin
   while(!feof(b))
   {
      ad[i][j] = fgetc(b);

      if(ad[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   ad[i][j]='\0';
   k=i;
   fclose(b);
}

void durum()
{
system("cls");
printf("=========================================== OTOBUS REZERVASYON SISTEMI ============================================\n\n\n");
    int i,trno,index=0,j;
    printf("Otobus numarasini girin:---->");
    scanf("%d",&trno);
    j=numarayi_oku(trno);
    adi_oku(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      OTOBUS.No-->%d---->%s                                                            \n",trno,ch[trno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],ad[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void durum_1(int trno)
{
    printf("Otobus numaraniz %d ********** %s",trno,ch[trno-1]);
    system("cls");
printf("=========================================== OTOBUS REZERVASYON SISTEMI ============================================\n\n\n");
    int i,index=0,j;
    j=numarayi_oku(trno);
    adi_oku(trno);
    char tempname[33][10]={"Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos ","Bos "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],ad[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void iptal()
{
 int koltuk_no,i,j;
 char numstr[100],tempstr2[15]="numara",tempstr1[15]="durum";
 printf("Otobus numarasini girin:---->");
 scanf("%d",&trno);
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 numarayi_oku(trno);
 adi_oku(trno);
 durum_1(trno);
 printf("Koltuk numarasini girin--->");
 scanf("%d",&koltuk_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == koltuk_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != koltuk_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",ad[j]);
             }
             else if(num1[j] == koltuk_no && num1[j] != 0)
             {
                 strcpy(ad[j],"Bos ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tParaniz iade edildi\t\t\t\n");
    printf("======================================================================================================\n");
}


void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="1234";
    do
{
	system("cls");
	
    printf("\n  =========================  GIRIS FORMU  =========================  ");
    printf(" \n                       KULLANICI ADI GIRIN:-");
	scanf("%s", &uname); 
	printf(" \n                      PAROLANI GIR:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,"user")==0 && strcmp(pword,"1234")==0)
	{
	printf("  \n\n\n    GIRIS BAÞARILI   SISTEMIMIZE HOS GELDINIZ !!!! ");
	printf("\n\n\n\t\t\t\tDevam etmek icin herhangi bir tusa basin...");
	getch();
	break;
	}
	else
	{
		printf("\n       AFEDERSINIZ !!!! GIRIS BASARISIZ");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nUzgunuz, dort kez yanlis kullanici adi ve sifre girdiniz!!!");
		
		getch();
		
		}
		system("cls");	
}
