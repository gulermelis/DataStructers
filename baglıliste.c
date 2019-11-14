#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int data;
	struct dugum *next;
};

struct dugum* dugumOlustur(int icerik){
	struct dugum *yeni=(struct dugum*)malloc(sizeof(struct dugum));
	if(yeni==NULL){
		printf("heapde yer ayrýlmadý...");
	}
	yeni->data=icerik;
	yeni->next=NULL;
	
	return yeni;
}

void basaEkle(int icerik,struct dugum **listebasi){
	struct dugum* eklenecek=dugumOlustur(icerik);
	if(*listebasi==NULL){       //burda kontrol etmesekdee olur listebasi null sa bile zaten else de yeninin nextine null atar
		*listebasi=eklenecek;
	//	return;
	}
	else{
	struct dugum* gecici=*listebasi;
	eklenecek->next=gecici;
	*listebasi=eklenecek;
	}
	
}
void sonaEkle(int icerik,struct dugum **listebasi){
	struct dugum* eklenecek=dugumOlustur(icerik);
	if(*listebasi==NULL){
		*listebasi=eklenecek;
	}
	else{
		struct dugum *temp=*listebasi;  //listebasini ayrý degiskende tutarak traverse yapmalýyoz,yoksa liste basini kaybederiz hata veriyor
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=eklenecek;
	}
}

void arayaEkle(int icerik,int kiminOnune,struct dugum **listebasi ){
		struct dugum* eklenecek=dugumOlustur(icerik);
		struct dugum* start=*listebasi;
		struct dugum* ekSonrasi=NULL;
		if(*listebasi==NULL){
			*listebasi=eklenecek;
		}
		else if(start->data==kiminOnune){
			*listebasi=eklenecek;
			eklenecek->next=start;
		
		}
		else{
		
			while(start->next!=NULL){
				
				if(start->next->data==kiminOnune){  
				//yuakrdakþ while ýn içine start!=next  yaparsak, son elemanýn uzerýne gelir ama son eleamnýn next i null ve datasý diye birþey yok sorunlu olur..
					ekSonrasi=start->next;
					start->next=eklenecek;
					eklenecek->next=ekSonrasi;
				    return;
				}
				else{
						start=start->next;
				}
		
		  	}
		  	printf("ekleme yapýlmadý cunku onune eklenecek elemean listede yok\n");
		  		 
		}
	
}


void siraliEkle(int icerik,struct dugum **listebasi){
	struct dugum *yeni= dugumOlustur(icerik);
	struct dugum *start=*listebasi;
	struct dugum *a=NULL;

	while( start!=NULL &&  icerik >= start->data){
		if(icerik==start->data){
				break ;
		}
		a=start;
		start=start->next;
	 }
	
	 if( (*listebasi)==start){
	 	*listebasi=yeni;
	 	yeni->next=start;
	 }
	 else{
	 a->next=yeni;
	 yeni->next=start;
	 }
}
//buyukten kucuge sýralar
void sirala(struct dugum** listebasi){
	struct dugum *a,*b,*c,*d;
	if(*listebasi==NULL || (*listebasi)->next==NULL){
		return;
	}
	d=(*listebasi)->next; //2.dugum d de tutuluyor
	(*listebasi)->next=NULL; // ilk dugumun bagý koparýlýyor
	while(d!=NULL){ 
		c=d;
		d=d->next; // 2.dugum ilerletiliyor
		b=*listebasi;
			while(b!=NULL && b->data > c->data){
				a=b;
				b=b->next;
			
			}
			if(b==*listebasi){
				c->next=*listebasi;    //listebasinin onune eklemiþ oluyoruz bu iki satýrla..
				*listebasi=c;
			}
			else{
				a->next=c;
				c->next=b;
			}
		}	
			
	}
	
void elemanSil(int silinen, struct dugum **listebasi){
	struct dugum *a=*listebasi;
	struct dugum *b;
		while(a!=NULL && a->data!=silinen){
			b=a;
			a=a->next;
			
		}
		if(a==NULL){ 
			return;
		}
		else if(a==*listebasi){  //yani while hic girmemiþse bu demek oluyorki ilk eleman silinecek olandýr.
			*listebasi=(*listebasi)->next;
		}
		else{
				b->next=a->next; //while a girilmiþ, aradan bir eleman silinecek
		}
	
		free(a);
	}
	

		
		
	        
	

void yazdir(struct dugum *listebasi){  //adresini gondermiyoruz!!cunku listebasi degismicek
           
	 	while(listebasi!=NULL){
			printf("%4d " ,((*listebasi).data)); //listebasi->data
			listebasi=listebasi->next;  //(*listebasi).next demektir zaten, yani listebasýnýn gosterdiði yere git nextini al
		}
	
}





//ters cevir 
//liste yok et
//recursive=listeyaz-terstenyaz-terscevir
//ÇÝFTYONLULERDE: Basa ekle-sona ekle-araya ekle
//hepsi için elemanarama yap ??
//AÐACLARA GEÇÇ.....






int main(int argc, char *argv[]) {
	struct dugum *liste1=NULL;  // aslýnda bu degiþken listenin ilk dugumune iþaret eder,listedeki ilk eleman,listeninbasi..

	arayaEkle(150,200,&liste1);
	yazdir(liste1);
	printf("\n");
//	basaEkle(5,&liste1);
//	basaEkle(15,&liste1);
	sonaEkle(100,&liste1);
	sonaEkle(200,&liste1);
	sonaEkle(215,&liste1);
	yazdir(liste1);
//	printf("\naraya ekle fonk cagir\n");
//	sonaEkle(100,&liste1);
//	sonaEkle(200,&liste1);
/*	arayaEkle(150,200,&liste1);
	yazdir(liste1);
	printf("\n");
	arayaEkle(80,100,&liste1);
	yazdir(liste1);
	printf("\n");
	arayaEkle(20,25,&liste1);
	yazdir(liste1);
	printf("\n");
	arayaEkle(400,500,&liste1);
	yazdir(liste1);*/
/*	printf("\n");
	sirala(&liste1);
	yazdir(liste1);
	printf("\nsiralandii\n");*/
	elemanSil(200,&liste1);
	printf("\n");
		yazdir(liste1);
	
/*	siraliEkle(10,&liste1);
		yazdir(liste1);
		printf("\n");
	siraliEkle(8,&liste1);
		yazdir(liste1);
		printf("\n");
/*	siraliEkle(20,&liste1);
		yazdir(liste1);
		printf("\n");
	siraliEkle(15,&liste1);
		yazdir(liste1);
			printf("\n");
	siraliEkle(22,&liste1);
		yazdir(liste1);
			printf("\n");
	siraliEkle(27,&liste1);
		yazdir(liste1);
		printf("\n");
	siraliEkle(100,&liste1);
		yazdir(liste1);
	*/
	return 0;
}
