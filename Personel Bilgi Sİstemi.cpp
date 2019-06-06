#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int cik;
 struct personel{
 	char ad[20];
 	char TCkimlikNo[11];
 	char telefon[11];
 	char Eposta[30];
 	char Adres[30];
 	
 }yk,ekle;
 
 void kayitEkle();
 void listele();
 void duzenle();
 void TCarama();
 void Arama();
 void kaydiSil();
 void kapat();
 
 int main(){
 	int secim;
 	
    setlocale(LC_ALL, "Turkish");
    
    printf("\n\t\t\t PERSONEL BÝLGÝ SÝSTEMÝ");
    printf("\n\t ÝÞLEMLER ");
    printf("\n\t1.Kayýt Ekle");
    printf("\n\t2.Personel Listele");
    printf("\n\t3.Kaydý Düzenle");
    printf("\n\t4.TC Kimlik No ile Arama");
    printf("\n\t5.Ýsim ile Arama");
    printf("\n\t6.Kayýt Sil");
    printf("\n\t0.Çýkýþ");

    printf("\n\t Tercihiniz:");
    scanf("%d",&secim);

    switch(secim)
    {
        case 1:kayitEkle();
        break;
        case 2:listele();
        break;
        case 3:duzenle();
        break;
        case 4:TCarama();
        break;
        case 5: Arama();
        break;
        case 6:kaydiSil();
        break;
        case 7:kapat();
        break;
    }
    return 0;
 }
 
 void kayitEkle(){
 	FILE *dosya;
 	dosya=fopen("Personel.txt","a+");
 	printf("\t\t\t\t Yeni Kayýt\n");
 	
 	printf("\n Ýsmini Giriniz:");
 	scanf("%s",&yk.ad);
 	printf("\n TCkimlik No Giriniz");
 	scanf("%s",&yk.TCkimlikNo);
 	printf("\n Telefon giriniz");
 	scanf("%s",&yk.telefon);
 	printf("\n Eposta giriniz:");
 	scanf("%s",yk.Eposta);
 	printf("\n Adresi giriniz:");
 	scanf("%s",yk.Adres);
 	fprintf(dosya,"%s%s%s%s%s\n",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres);
 	
 	fclose(dosya);
 	
 	
 	printf("\n   Kayýt Oluþturuldu");
 	s1:
	printf("\n\t\t Yeni kayýt için 1,Ana Menü için 2");
	scanf("%d",&cik);
	if(cik==2)
	main();
	else if(cik==1)
	kayitEkle();
	else {
		printf("Hatalý Giriþ");
		goto s1;
		
	}
 }
 
 void listele(){
 	FILE *dosya;
 		dosya=fopen("Personel.txt","r");
 		int test=0;
 		printf("\nÝsim\t\tTC\t\tTelefon\t\tEposta\t\tAdres\n");
 		while(fscanf(dosya,"%s%s%s%s%s",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres)!=EOF){
 			 	printf("\n %s\t\t%s\t\t%s\t\t%s\t\t%s\n",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres);
 			 	test++;
 			 	
		 }
		 fclose(dosya);
		 if(test==0)
		 {printf("KAYIT YOK\n") ; }
		 s2:
		printf("\n\t\t Yeni kayýt için 1,Ana Menü için 2");
		scanf("%d",&cik);
		if(cik==2){
			main();
		}
		else if(cik==1){
			kayitEkle();
		}
		else{
			printf("Hatalý Giriþ\n");
			goto s2;
			
		}
 }
 void duzenle(){
 	int test;
 	FILE *eski,*fark;
 	eski=fopen("Personel.txt","r");
 	fark=fopen("fark.txt","w");
 	printf(	"\nPersonel Ýsmi:");
 	scanf("%s",yk.ad);
 	while(fscanf(eski,"%s%s%s%s%s",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres)!=EOF){
 		if(strcmp(yk.ad,ekle.ad)==0){
 			test=1;
			 
			 printf("\nYeni TC:"); scanf("%s",&ekle.TCkimlikNo);
			 printf("\nYeni Telefon:"); scanf("%s",ekle.telefon);
			 printf("\nYeni Eposta:"); scanf("%s",ekle.Eposta);
			 printf("\nYeni Adres:");  scanf("%s",ekle.Adres);
			  
			  fprintf(fark,"%s%s%s%s%s",ekle.ad,ekle.TCkimlikNo,ekle.telefon,ekle.Eposta,ekle.Adres);
			  printf("\nDeðiþiklikler Kaydedildi");
			  
			 
			 
		 }
		 else
		 {
		   
		 fprintf(fark,"%s%s%s%s%s",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres);
	}
	
	
	 }
 	fclose(eski);
 	fclose(fark);
 	remove("Personel.txt");
 	rename("fark.txt","Personel.txt");
 	
 	if(test!=1)
 	printf("\nisim bulunamadý\a\a\a");
 	
 	s3:
 		printf("\n\t\tTekrar sorgu için 0 Anamenü için 1");
 		scanf("%d",&cik);
 		if(cik==1)
 		main();
 		else if(cik==0)
 		duzenle();
 		else{
 			printf("Yanlýþ Deðer Girdiniz");
 			goto s3;
 			
		 }
 		
 	
 	
 	
 }
 
 
 void TCarama(){
 	FILE *dosya;
 	int test=0;
 		dosya=fopen("Personel.txt","r");
 		printf("Tc:");
 		scanf("%s",&ekle.TCkimlikNo);
 		while(fscanf(dosya,"%s%s%s%s%s",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres)!=EOF)
 		{
 			if(ekle.TCkimlikNo==yk.TCkimlikNo)
 			{
 				test=1;
 				printf("\nisim:%s\nTc:%s\nTelefon:%s\nEposta :%s\nAdres:%s\n",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres);
 				
			 }
		 }
		 fclose(dosya);
		 if(test!=1)
		 printf("Kayýt bulunamadu");
		 s4:
		 	printf("\nTekrar Aramak için0,Ana menü ,Cýkýþ 2");
		 	scanf("%d",&cik);
		 	if(cik==1){
			
		 	main();
		 	 }
		 	else if(cik==2){
		 	kapat();
		 	 }
		 	else if(cik==0){
		 	TCarama();
		 	 }
		 	else{
		 		printf("\nHatali giriþ");
		 		goto s4;
		 		
			 }
		}
 
 
void sil(){
    FILE *eski,*fark;
    int test=0;
    eski=fopen("Personel.txt","r");
    fark=fopen("fark.txt","w");
    printf("Silinecek kiþi TC'si:");
    scanf("%s",&ekle.TCkimlikNo);
    while(fscanf(eski,"%s %s %s %s %s",yk.ad,&yk.TCkimlikNo,&yk.telefon, yk.Eposta, yk.Adres)!=EOF)
    {
        if(ekle.TCkimlikNo!=yk.TCkimlikNo)
            fprintf(fark,"%s %s %s %s %s\n",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres);
        else{
            test++;
            printf("\nKayýt silindi.\n");
        }
   }
   fclose(eski);
   fclose(fark);
   remove("Personel.txt");
   rename("fark.txt","Personel.txt");
   if(test==0)
        printf("\nKayýt bulunamadý!\a\a\a");
    gecersiz7:
        printf("\nTekrar silme aramasý yapmak için 0, Ana Menü için 1, Çýkmak için 2:");
        scanf("%d",&cik);
        if (cik==1)
            main();
        else if (cik==2)
            kapat();
        else if(cik==0)
            sil();
        else{
        printf("\nYanlýþ Giriþ!\a");
        goto gecersiz7;
        }
    }

 
 void Arama(){
 	FILE *dosya;
 	dosya=fopen("Personel.txt","r");
 	int test;
 	printf("ismi giriniz");
 	scanf("%s",&ekle.ad);
 	
 	  while(fscanf(dosya,"%s %s %s %s %s",yk.ad,&yk.TCkimlikNo,&yk.telefon, yk.Eposta, yk.Adres)!=EOF)
    {
            if(strcmp(ekle.ad,yk.ad) == 0){
                test=1;
                printf("\nÝsim:%s \nTC:%s \nTelefon:%s \nEposta:%s \nAdres:%s\n",yk.ad,yk.TCkimlikNo,yk.telefon,yk.Eposta,yk.Adres);
            }
    }
    fclose(dosya);
    if(test!=1)
        printf("\nKayýt Bulunamadý!\a\a\a");
    s6:
        printf("\nTekrar aramak için 0, Ana Menü için 1, çýkmak için 2:");
        scanf("%d",&cik);
            if (cik==1)
                main();
            else if (cik==2)
                kapat();
            else if(cik==0)
                Arama();
            else{
                printf("\nYanlýþ Giriþ!\a");
                goto s6;
            }
 	
 }


 void kapat(){ 
 exit (1);
 	
 }
