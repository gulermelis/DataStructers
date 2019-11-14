#include <stdio.h>
#include <stdlib.h>

void dizi_yaz(int *dizi, int size){

    int i;

    for(i=0; i<size; i++)
        printf("%4d", *(dizi+i));
    printf("\n\n");

}

void dizi_yaz1(int (*dizi)[2],int row,int column){

    int i,j;
    for(i=0; i<row; i++){
    
        for(j=0; j<column; j++){

        printf("%20d\t",*(*(dizi+i)+j));
          //  printf("%4d",dizi[i][j]); //ayný

        }

        printf("\n");
    }

}
int main()
{
	int a[5][5]={1,2,3,4,5}; //diziyi tanimladik
//deðerleri bastýrýyoruz
int i,j;
for( i= 0;i<5;i++){
   for(j = 0;j<5;j++){
      printf("%d ",a[i][j]);
   }
   printf("\n");
}

printf("******************************************************************\n");
	int A[]={0,1,12,33,4,5,6,7,8,9};
    int d[]={5,10,15,20};
    int *p;
    int n;
    printf("%d\t %d\n",sizeof(d), sizeof (int));
    n=sizeof (d) / sizeof (int);
    p=d; //array can bu assingned directly to a pointer variable
   
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,*(p+i));
            
    }
    printf("\n");
    dizi_yaz(A,10);
    printf("\n");
	printf("\n");
    printf("-------------------------------------\n");
    int CC[4][3]={10,20,30};
    dizi_yaz1(CC,4,2);
     printf("-------------------------------------\n");
    dizi_yaz(CC,12);

          getch(); 
  }
