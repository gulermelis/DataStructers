#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int icerik;
	struct dugum *sol;  // struct dugum tipinde alaný gosteren iþaretci..
	struct dugum *sag;
};
 struct ikili_arama_agaci{
 	struct dugum *kok;  //bu ikili arama agacý yapýsýnýn içinde dugum tipinde bir pointer var,, agacýnn rootunu gosteren 
 };
 
 void ikili_arama_agaci_olustur(struct ikili_arama_agaci **agac1){
 	*agac1=(struct ikili_arama_agaci*)malloc(sizeof(struct ikili_arama_agaci));  //maindeki agacýn adresini agac1 e yazdýk, *agac1 e ayrýdýgýmýz alaný yazýyoruz..
	 if(*agac1==NULL){
	 	printf("heapde yer ayrilmadi");
	 } 	
	 (*agac1)->kok=NULL;
	 
 }
 
 struct dugum* dugumOlustur(int icerik){
 	struct dugum *node=(struct dugum*)malloc(sizeof(struct dugum)); //direk olusan alanýn adresininode pointerýna yazýyoruz
 	if(node==NULL){
 			printf("heapde yer ayrilmadi");
 			exit(1);
	 }
	 node->icerik=icerik;
	 node->sol=node->sag=NULL;
	 
	 return node;
 }
 //EKLEME
 void ekle(struct ikili_arama_agaci *agac,int icerik){ //rootu hýc degiþmiyor o yuzden adresii gondrmiyoruz
 	struct dugum *node;
 	struct dugum *iter;
 	struct dugum *geri;
 	iter=agac->kok;
 	while(iter!=NULL){
 		geri=iter;
 		if(icerik > iter->icerik){
 			iter=iter->sag;
		 }
		else if(icerik < iter->icerik){
			iter=iter->sol;
		}	
		else return;
		 	
	 }
	 node=dugumOlustur(icerik);
	 if(agac->kok==NULL){
	 	agac->kok=node;
	 	return;
	 }
	 if(icerik >geri->icerik){
	 	geri->sag=node;
	 	
	 }
 	else{
 		geri->sol=node;
	 }
 }
 
 //EKLE-RECURSÝVE
 /* Eleman ekleme iþlemini yapan fonksiyon 
struct node* insert(struct node* node, int key)
{
     
    if (node == NULL) return newNode(key);
  
     
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
  
     
    return node;
}
  */
  
 //DUGUM SAYISI
 int dugumSayisi(struct dugum *kok){
 	if(kok==NULL) return 0;
 	return 1+dugumSayisi(kok->sol)+(kok->sag);
 }
 
 //YAPRAK SAYISI
 int yaprakSayisi(struct dugum *kok){
	 if(kok==NULL) return 0;
 	else if(kok->sol==NULL && kok->sag==NULL) return 1;
 	else return yaprakSayisi(kok->sol)+yaprakSayisi(kok->sag);
}

//IC-DUGUM SAYISI
int foo(struct dugum *kok){
	if(kok==NULL) return;
	else if(kok->sag!=NULL || kok->sol!=NULL)
		return 1+foo(kok->sol)+foo(kok->sag); // sol veya sag null degilse
	else return 0; //yapraksa cýkýyor zaten sol ve sag null sa yapraktýr. hic childý yok demektir.
}

//YOKET
void yoket(struct dugum **kok){ //kok degeri degisecek o yuzden adresini yollluyoruz
	if(*kok!=NULL){
		yoket(&(*kok)->sol); //ok daha onceliklidir,, once solunu yok et
		yoket(&(*kok)->sag); //sonra sagýný yok et
		free(*kok);  // en son koku yok et
		*kok=NULL;
	}
}
 
 //SIL
 void sil(int silinecek, struct ikili_arama_agaci *agac){
 	struct dugum *d=agac->kok;
 	struct dugum *parent=NULL;
 	struct dugum *iter, *tutucu;
 	int sol;
 	while(d!=NULL){
 		if(silinecek>d->icerik) {
 			parent=d; d=d->sag; sol=0;
		 }
		 else if(silinecek< d->icerik){
		 	parent=d; d=d->sol; sol=1;
		 }
		 else break;
	 
	 }
	 if(d==NULL) return;
	 if(d->sol==NULL){
	 	if(parent==NULL) agac->kok=d->sag;
	 	else{
	 		if(sol==1) parent->sol=d->sag;
	 		else parent->sag=d->sag;
		 }
	 }
	 else if(d->sag==NULL){
	 	if(parent==NULL) agac->kok=d->sol;
	 	else{
	 		if(sol==1) parent->sol=d->sol;
	 		else parent->sag=d->sol;
		 }
	 }
	 else{
	 	iter=d->sol;
	 	tutucu=NULL;
	 	while(iter->sag!=NULL){
	 		tutucu=iter;
	 		iter=iter->sag;
		 }
		if(tutucu!=NULL) { //YANÝ WHÝLE GÝRMÝÞÝM 
			tutucu->sag=iter->sol;
			iter->sol=d->sol;			
		}
		iter->sag=d->sag;
	 	if(parent==NULL){
	         agac->kok=iter;
		 } //yani kok elemeaný rootu siliyorsam,  sagýmýn en solundakini getircem
	 	//parent null degil ortadan bir dugum silicem o zaman silicegimi dugumden onceki dugumu parent tutar, silicegimi parentta sol unda mý yoksa sagýnda mý
	 	//onu bulup, degýsýklýk yapacagýz, sileceðim dugumun yerine hangisi gecicek= sileceðim dugumun solunun en sagýndakimni bul,
	 	//sol==1 ise parent ýn soluna ekle, degilse parent ýn sagýna ekle.
	 	else{
	 		if(sol==1)  parent->sol=iter;
	 		else parent->sag=iter;
		 }
	 }
	 
	 free(d);
 		
	 }
 
 
 /*3 TÝP DOLASMA VARDIR..
 
 1-ÝNORDER: ONCE SOL-KOK-SAG
 */
void inorder_yardimci(struct dugum *kok){
	if(kok==NULL) return;
	inorder_yardimci(kok->sol);
	printf("%4d ",kok->icerik);
	inorder_yardimci(kok->sag);
	
}

void inorder(struct ikili_arama_agaci *agac){
	if(agac==NULL) return;
	inorder_yardimci(agac->kok);
	printf("\n");
}
 
 
 
int main(int argc, char *argv[]) {
	
	struct ikili_arama_agaci *agac=NULL;
	ikili_arama_agaci_olustur(&agac);
	
	ekle(agac,100); ekle(agac,50);

	ekle(agac,200);
	
	sil(100,agac);

	inorder(agac);

	
	
	
	
	
	
	
	
	
	
	return 0;
}
