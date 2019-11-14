#include<stdio.h>
#include<stdlib.h>
  
 //A�a� d���m yap�m�z
struct node
{
    int key;
    struct node *left, *right;
};
  
// d���m olu�turan fonksiyon
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
  
/* Eleman ekleme i�lemini yapan fonksiyon */
struct node* insert(struct node* node, int key)
{
     
    if (node == NULL) return newNode(key);
  
     
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
  
     
    return node;
}
  
/* Verilen d���m�n alt a�ac�ndaki en k���k d���m� bulan fonksiyon.
   size konu anlat�m�nda -varsa sa� alt a�ac�n en k���k eleman�n� elde etmemiz gerekti�ini s�ylemi�tim
 */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
  
     
    while (current->left != NULL)
        current = current->left;
     
    //En k���k d���m return edilir.
    return current;
}
  
/* silme i�ini yapan esas fonksiyonumuz */
struct node* deleteNode(struct node* root, int key)
{
    // k�k d���m NULL ise root'u return ediyor
    if (root == NULL) return root;
  
    // Silinmek istenen eleman� �ncelikle bulmam�z gerekiyor.
    // Bu y�zden e�er silmek istedi�imiz d���m root'dan k���kse sol alt a�aca gidiyor
    if (key < root->key)
        root->left = deleteNode(root->left, key);
  
    // E�er silmek istedi�imiz d���m root'dan b�y�kse sa� alt a�aca gidiyor
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
  
    // Yukar�daki �artlardan hi�birisi sa�lanm�yorsa arad���m�z d���m� bulduk demektir.
    else
    {
        // E�er d���m�n solda �ocu�u yoksa...
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // e�er d���m�n sa�da �ocu�u yoksa...
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
  
        // ��in en can al�c� noktas� buras�, �imdi d���m�n 2 �ocu�u varsa nas�l eleman silece�iz ona bak�yoruz
        // minValueNode sa� alt a�a�taki en k���k de�eri bulur ve temp de�erine atar.
        struct node* temp = minValueNode(root->right);
  
        // Burada atama i�lemi yapt�k
        root->key = temp->key;
  
        // Burada ise silme i�lemini ger�ekle�tiriyoruz
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
  
//test a�amas�
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
