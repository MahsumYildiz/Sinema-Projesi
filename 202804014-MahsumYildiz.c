#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct salon{
int adi;
int matine;
int ucret;
int ucret2;
int koltuk[5][10];
}film[0];

FILE *dosya;
char adii[50],sfrr[50];


void dosyaw()
{

 FILE *dosya;
    dosya = fopen("sifre.txt", "w");
     if(dosya == NULL)
       {
        printf("�ifre dosyas� a��lmad�.");
               exit(1);
       }
    printf("Kullan�c� ad�n� giriniz\n"); scanf("%s",adii);
    printf("�ifre giriniz\n"); scanf("%s",sfrr);
    fprintf(dosya,"%s %s\n",adii,sfrr);
 fclose(dosya);
}

void dosyar()
{

    char kullanici[50],sifrem[50];
bas:printf("Kar��la�t�rmak i�in kullan�c� ad�n�z� tekrar giriniz\n"); scanf("%s",kullanici);
    printf("Kar��la�t�rmak i�in �ifrenizi tekrar giriniz\n"); scanf("%s",sifrem);

 FILE *dosya;
    dosya = fopen("sifre.txt","r");
    fscanf(dosya,"%s %s",adii,sfrr);
    int a=strcmp(kullanici,adii);
    int b=strcmp(sifrem,sfrr);
    if(a==0 && b==0){
        printf("Giri� ba�ar�l�\n");
    }
    else {
        printf("Giri� ba�ar�s�z\n");
        goto bas;
    }
fclose(dosya);
}

void fonks()
{
   char secim,E,H,adi,sfr;
   int bilets,sayac=0,sayac2=0,sonuc,sonuc2,rastgele;
   int sonucr=0,sonucg=0,sonucb=0;

film[0].ucret=20;
film[0].ucret2=30;

       printf("Ka� adet bilet istiyorsunuz\n"); scanf("%d",&bilets);
       for(int i=0; i<bilets; i++){
       printf("L�tfen istedi�iniz salonu se�iniz\n");
     a:printf("1-Red\n2-Green\n3-Blue\n"); scanf("%d",&film[0].adi);
       if(film[0].adi>=1 && film[0].adi <=3){
        }
        else{
            printf("Hatal� Se�im yapt�n�z,tekrar deneyiniz\n");
        goto a;
      }
        switch(film[0].adi)
        {
            case 1: sonucr++; break;
            case 2: sonucg++; break;
            case 3: sonucb++; break;
        }
     b:printf("Matine se�iniz (1-5 aras�)\n"); scanf("%d",&film[0].matine);
       if(film[0].matine>=1 && film[0].matine <=5){
        }
        else{
            printf("Hatal� Se�im yapt�n�z,tekrar deneyiniz\n");
        goto b;
        }
       printf("��renci misin? (E/H)\n"); scanf("%s",&secim);
       printf("Bo� koltuklar�m�z\n");
        for(int i=0; i<5; i++){
        printf("%d  ",++film[0].koltuk[5][10]);
            for(int j=0; j<9; j++){
                printf("%d  ",++film[0].koltuk[5][10]);
            } printf("\n");
       }
     c:printf("Koltuk se�iniz(1-50 aras�)\n"); scanf("%d",&film[0].koltuk[5][10]);
       if(film[0].koltuk[5][10]>=1 && film[0].koltuk[5][10] <=50){
        }
        else{
            printf("Hatal� Se�im yapt�n�z,tekrar deneyiniz\n");
        goto c;
        }
      switch(film[0].adi){
           case 1:printf("Salon Red\n"); break;
           case 2:printf("Salon Green\n"); break;
           case 3:printf("Salon Blue\n"); break;
       }
    printf("Matine %d\n",film[0].matine);
    printf("Koltuk %d\n",film[0].koltuk[5][10]);
    switch(secim){
    case 'E' :printf("��renci indirimi uyguland�.Fiyat %d TL\n\n",film[0].ucret); sayac++; break;
    case 'H' :printf("Tam Bilet.Fiyat %d TL\n\n",film[0].ucret2); sayac2++;break;
    case 'e' :printf("��renci indirimi uyguland�.Fiyat %d TL\n\n",film[0].ucret);sayac++; break;
    case 'h' :printf("Tam Bilet.Fiyat %d TL\n\n",film[0].ucret2);sayac2++; break;
    }
  }
    FILE *login;
    login=fopen("log.txt","w");
    sonuc=(sayac*20)+(sayac2*30);
    sonuc2=sayac+sayac2;
    fprintf(login,"Salon Red   film izliyen ki�i say�s� %d\n",sonucr);
    fprintf(login,"Salon Green film izliyen ki�i say�s� %d\n",sonucg);
    fprintf(login,"Salon Blue  film izliyen ki�i say�s� %d\n",sonucb);
    fprintf(login,"Toplam %d Tl has�lat var\n",sonuc);
    fprintf(login,"Toplam %d Ki�i film izliyor\n",sonuc2);
    fclose(login);
}
int main()
{
     setlocale(LC_ALL,"Turkish");
dosyaw();
dosyar();
fonks();

   return 0;
}
