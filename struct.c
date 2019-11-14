#include <iostream>
#include <stdio.h>
#include <stdlib.h>


/* 
        STRUCT ve dizgiler(String)
Struct lar aslýnda c programlama dilinin temelini olusturuyor
c de birden fazla tipi birleþtirerek tek bir tip olusturmak istersek STRUCT kullanýyoruz.
yeni bir tip tanýmlýyoruz
OLUSUM YAPISI:
--insan tipinde içinde 3 tip barýndýran bir tip tanýmlanamasý-- (enumarator tanýmlarý devc de gerek yok)
   
    typedef enum{   ---yani burda enum tanýmlýyoruz-- enumdan tip tanýmlama--içerdiði 2 tipten birisidr, 
    	bay,    //0       --bu kod sunu yaptý:cinsiyet tipi, mainde de struct içindede butun kod da tanýmlý hale getirdi
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
		//enum {bay,bayan} cinsiyet;   //Cinsiyet isminde enumarator tanýmlanmýs yalnýzca bay veya bayan degerini alailir
	    cinsiyet c;                    //enumu taýmlayýnca burayý da deðiþtiridk. // insanýn,c isminde deðiþkeni var,bu deðiþkenin tipi cinsiyet ve bu c,nsiyet bir enumarator ve bay veya bayan  alabiliyor
	    gunler tatilgunu;
	}Insan;                              //insan ismini verdik

    
	 int main(){
     	insan ali;
     	ali.yas=30;
     	ali.c=bay; //bazý ortamlar bu bay ý anlamaz o yuzden enum olarak tanýmlamak gerek(scope farklý old. için..))
        ali.tatýlgunu=persembe;
		 
		 printf("alinin yasi: %d  %u  %u" ,ali.yas, ali.c, ali.tatilgunu);
		 
		 // enumaratorlar sayýdýr int tipindedir eksi olamazlar, dolasyýsýyla %u cunku unsigned dir
     	
     	
     }
     
*c dili otomasyon için kullnanýlmýyor,yani struct felan goremeyýz.otomasyon da artýk genelde object oriented diller kullanýlýyor 
*low level programlamada c kullanýlýyor

/******************************************************************************************************************************************
******************************************************************************************************************************************

STRING 
	String BÝR KARAKTER DÝZÝSÝDÝR, karakter dzisinden tek farký sonunda end of string ("\0") karakteri olmasýdýr.. dizgi bittiðini belirtir.
	Stringin bittiðini nasýl anlayacak.
	Normalde BÝR DÝZGÝ TNAIMLADIK 20 KARAKTERLÝK BÝR YER ACTIK RAMDE. ADAMA ÝSMÝNÝ SORDUK , ADAM ALÝ DER, 3 KARAKTER GERÝ KALANINI BASMAMASI ÝÇÝN \0 KONUR.
	
int main(){
     
	char isim[20];        //srting tanýmladýk, 20 karakterlik dizi, 20 karakter sonrasýnda eger alan bossa calýsýr sans iste. ram de o alan doluysa patlar.
	scanf("%s",isim);     // neden &isim demedýk, poinet oldugu için onun gosterdiði adrese yaz anlamýndaydý
	printf("merhaba %s",isim);                      //ama diziler zaten pointer
	
	char *soyisim;
	soyisim=(char*)malloc(sizeof(char)*20);
	scanf("%s",soyisim);
	
	include sting.h kütüphanesi:strlen falan filan....hazýr fonksyonlar var
	***shallow copy=tek bir kopya var ikisi yaný yere gosteryor,biri deðiþtiðinde diðeridedeðiþiyor
    ***deep copy=2 kopya var ramde,biri biriini digeri diðerini gosteriyor,biri deðiþtiðinde diðeri deðiþmez,üstüne kopyalama
    
	

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
