#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void dizi_yaz_3boyutlu(int (*dizi)[3][5], int size){

    int i,j,k;
    for(i=0; i<size; i++){
    
        for(j=0; j<3; j++){
        
            for(k=0; k<5; k++)
                printf("%4d \t %p",dizi[i][j][k], &dizi[i][j][k] );
            printf("\n");
        }
        
        printf("\n");
        
    }

}
//normalde dizi olustururken dizinin boyutunu degi�ken olarak diziye aktaram��yoruz ama pointerlar kullanarak bu mumkun
void tek_boyutlu_dizi_olustur(int **dizi,int elemansayisi){ //neden **? C�NK�: maindeki A degi�keni asl�nda heapte ayr�lan bolgenin ilk adresini tutuyor, A bir degi�ken tutsayd� sadece * yapard�k.
	*dizi=(int*)malloc(sizeof(int)*elemansayisi);    
	int i;
		for(i=0;i<elemansayisi;i++){
			// *dizi : heapte ayr�lan bolgenin adresini tutuyor, ozaman o alan�n i�ine eri�mek i�in **dizi yapmama�z gerek
			*(*dizi+i)=i;
			
		}	
}

void tek_boyutlu_dizi_yaz(int *dizi,int elemansayisi){
	int i;
	for(i=0;i<elemansayisi;i++){
		printf("%d \t %p\n", (*(dizi+i)), (dizi+i));
		
	}
}

// neden basta (int**) C�NK�: tekboyutlu dizi olusturda benim dizi degi�kenim integer deger tutan bir alana i�aret gosteriyordu,
	//suan ise integera pointer tutan (yani adres tutan)bir yere i�aret ediyor
	//yani tip donusmu i�in gerekli atayacag�m�z dizi degi�keninin tipine uyumlu olmas� i�in boyle yapt�k..OLEEEYY
void dinamik_matris_olustur(int ***dizi,int row,int column){
	*dizi=(int**)malloc(sizeof(int*)*row); //Satir sayisi kadar yer ay�r, sizeof(int*):bu yerler adres tutuyor,
	int i,j;
	for(i=0;i<row;i++){
		*(*dizi+i)=(int*)malloc(sizeof(int)*column);
		for(j=0;j<column;j++){
			*(*(*dizi+i)+j)=rand%3;
		}
		
	}
	
	
	
	
	
}
int main(int argc, char *argv[]) {
	
	int C[2][3][5]= {{{0,11,2,3,4},{10,877,12,13,14},{20,21,22,23,24}},
                 {{0,1,2,3,4},{10,877,152,13,14},{20,21,22,23,274}}};
                 
       // dizi_yaz_3boyutlu(C,2);
    
    int *A;
    int size=5;
    
    int **B;
    
    tek_boyutlu_dizi_olustur(&A,size);
    tek_boyutlu_dizi_yaz(A,size); //adresini gondermiyorum cunku bir de�i�iklik yapmayacag�m
    
    dinamik_matris_olustur(&B,3,4);
        
     
	return 0;
}


