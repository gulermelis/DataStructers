#include <iostream>
#include <stdio.h>
#include <stdlib.h>


/* 
        STRUCT ve dizgiler(String)
Struct lar asl�nda c programlama dilinin temelini olusturuyor
c de birden fazla tipi birle�tirerek tek bir tip olusturmak istersek STRUCT kullan�yoruz.
yeni bir tip tan�ml�yoruz
OLUSUM YAPISI:
--insan tipinde i�inde 3 tip bar�nd�ran bir tip tan�mlanamas�-- (enumarator tan�mlar� devc de gerek yok)
   
    typedef enum{   ---yani burda enum tan�ml�yoruz-- enumdan tip tan�mlama--i�erdi�i 2 tipten birisidr, 
    	bay,    //0       --bu kod sunu yapt�:cinsiyet tipi, mainde de struct i�indede butun kod da tan�ml� hale getirdi
    	bayan   //1
	}cinsiyet;
	
	typedef enum{
		pztesi
		sali
		carsa
		persembe  //3
		cuma
	}gunler;
	
	typedef struct{   
		int yas;
		char *isim;                    //karakter pointer,string tutacak
		//enum {bay,bayan} cinsiyet;   //Cinsiyet isminde enumarator tan�mlanm�s yaln�zca bay veya bayan degerini alailir
	    cinsiyet c;                    //enumu ta�mlay�nca buray� da de�i�tiridk. // insan�n,c isminde de�i�keni var,bu de�i�kenin tipi cinsiyet ve bu c,nsiyet bir enumarator ve bay veya bayan  alabiliyor
	    gunler tatilgunu;
	}Insan;                              //insan ismini verdik

    
	 int main(){
     	insan ali;
     	ali.yas=30;
     	ali.c=bay; //baz� ortamlar bu bay � anlamaz o yuzden enum olarak tan�mlamak gerek(scope farkl� old. i�in..))
        ali.tat�lgunu=persembe;
		 
		 printf("alinin yasi: %d  %u  %u" ,ali.yas, ali.c, ali.tatilgunu);
		 
		 // enumaratorlar say�d�r int tipindedir eksi olamazlar, dolasy�s�yla %u cunku unsigned dir
     	
     	
     }
     
*c dili otomasyon i�in kullnan�lm�yor,yani struct felan goremey�z.otomasyon da art�k genelde object oriented diller kullan�l�yor 
*low level programlamada c kullan�l�yor

/******************************************************************************************************************************************
******************************************************************************************************************************************

STRING 
	String B�R KARAKTER D�Z�S�D�R, karakter dzisinden tek fark� sonunda end of string ("\0") karakteri olmas�d�r.. dizgi bitti�ini belirtir.
	Stringin bitti�ini nas�l anlayacak.
	Normalde B�R D�ZG� TNAIMLADIK 20 KARAKTERL�K B�R YER ACTIK RAMDE. ADAMA �SM�N� SORDUK , ADAM AL� DER, 3 KARAKTER GER� KALANINI BASMAMASI ���N \0 KONUR.
	
int main(){
     
	char isim[20];        //srting tan�mlad�k, 20 karakterlik dizi, 20 karakter sonras�nda eger alan bossa cal�s�r sans iste. ram de o alan doluysa patlar.
	scanf("%s",isim);     // neden &isim demed�k, poinet oldugu i�in onun gosterdi�i adrese yaz anlam�ndayd�
	printf("merhaba %s",isim);                      //ama diziler zaten pointer
	
	char *soyisim;
	soyisim=(char*)malloc(sizeof(char)*20);
	scanf("%s",soyisim);
	
	include sting.h k�t�phanesi:strlen falan filan....haz�r fonksyonlar var
	***shallow copy=tek bir kopya var ikisi yan� yere gosteryor,biri de�i�ti�inde di�eridede�i�iyor
    ***deep copy=2 kopya var ramde,biri biriini digeri di�erini gosteriyor,biri de�i�ti�inde di�eri de�i�mez,�st�ne kopyalama
    
	

 */
 
 //Struct ornek:

typedef enum{
	bay,
	bayan
}cinsiyet;

typedef struct{
	int yas;
	char *isim;
	cinsiyet c;
}insan;

int emeklimi(insan*);   //prototip
//-------------------------------------MAIN----------------------------------------------------
int main(int argc, char** argv) {
	 
	 insan ali;
	 ali.yas=30;
	 ali.c=bay;
	 
	 insan *veli;
	 veli=(insan*)malloc(sizeof(insan));
	 veli->yas=65;
	 veli->c=bay;
	 
	 
	// printf(" %d %u",ali.yas,ali.c);
	 //printf("\n %d %u",veli->yas,veli->c);
	 if(emeklimi(&ali))
		printf("ali emeklidir\n");
	else
		printf("ali emekli degildir\n");
	

	
	if(emeklimi(veli))
		printf("veli emeklidir\n");
	else
		printf("veli emekli degildir");
	
	return 0;
}

int emeklimi(insan *birey){
	if(birey->c==bay && birey->yas>60)
		return 1;
	if(birey->c==bayan && birey->yas>50)
		return 1;
	return 0;
}
