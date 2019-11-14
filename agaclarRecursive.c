#include<stdio.h>
#include<stdlib.h>
  
 //Aðaç düðüm yapýmýz
struct node
{
    int key;
    struct node *left, *right;
};
  
// düðüm oluþturan fonksiyon
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
// inorder traverse yapan fonksyion
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
  
/* Eleman ekleme iþlemini yapan fonksiyon */
struct node* insert(struct node* node, int key)
{
     
    if (node == NULL) return newNode(key);
  
     
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
  
     
    return node;
}
  
/* Verilen düðümün alt aðacýndaki en küçük düðümü bulan fonksiyon.
   size konu anlatýmýnda -varsa sað alt aðacýn en küçük elemanýný elde etmemiz gerektiðini söylemiþtim
 */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
  
     
    while (current->left != NULL)
        current = current->left;
     
    //En küçük düðüm return edilir.
    return current;
}
  
/* silme iþini yapan esas fonksiyonumuz */
struct node* deleteNode(struct node* root, int key)
{
    // kök düðüm NULL ise root'u return ediyor
    if (root == NULL) return root;
  
    // Silinmek istenen elemaný öncelikle bulmamýz gerekiyor.
    // Bu yüzden eðer silmek istediðimiz düðüm root'dan küçükse sol alt aðaca gidiyor
    if (key < root->key)
        root->left = deleteNode(root->left, key);
  
    // Eðer silmek istediðimiz düðüm root'dan büyükse sað alt aðaca gidiyor
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
  
    // Yukarýdaki þartlardan hiçbirisi saðlanmýyorsa aradýðýmýz düðümü bulduk demektir.
    else
    {
        // Eðer düðümün solda çocuðu yoksa...
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // eðer düðümün saðda çocuðu yoksa...
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
  
        // Ýþin en can alýcý noktasý burasý, þimdi düðümün 2 çocuðu varsa nasýl eleman sileceðiz ona bakýyoruz
        // minValueNode sað alt aðaçtaki en küçük deðeri bulur ve temp deðerine atar.
        struct node* temp = minValueNode(root->right);
  
        // Burada atama iþlemi yaptýk
        root->key = temp->key;
  
        // Burada ise silme iþlemini gerçekleþtiriyoruz
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
  
//test aþamasý
int main()
{
    /* 
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
  
    printf("Verilan agacin inorder Siralamasi ... Algoritma Uzmani \n");
    inorder(root);
  
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Verilan agacin inorder Siralamasi ... Algoritma Uzmani \n");
    inorder(root);
  
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Verilan agacin inorder Siralamasi ... Algoritma Uzmani \n");
    inorder(root);
  
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Verilan agacin inorder Siralamasi ... Algoritma Uzmani \n");
    inorder(root);
  
    return 0;
}
