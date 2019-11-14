#include<stdio.h>
#include<stdlib.h>
  
 //Ağaç düğüm yapımız
struct node
{
    int key;
    struct node *left, *right;
};
  
// düğüm oluşturan fonksiyon
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
  
/* Eleman ekleme işlemini yapan fonksiyon */
struct node* insert(struct node* node, int key)
{
     
    if (node == NULL) return newNode(key);
  
     
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
  
     
    return node;
}
  
/* Verilen düğümün alt ağacındaki en küçük düğümü bulan fonksiyon.
  -varsa sağ alt ağacın en küçük elemanını elde etmemiz gerektiğini söylemiştim
 */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
  
     
    while (current->left != NULL)
        current = current->left;
     
    //En küçük düğüm return edilir.
    return current;
}
  
/* silme işini yapan esas fonksiyonumuz */
struct node* deleteNode(struct node* root, int key)
{
    // kök düğüm NULL ise root'u return ediyor
    if (root == NULL) return root;
  
    // Silinmek istenen elemanı öncelikle bulmamız gerekiyor.
    // Bu yüzden eğer silmek istediğimiz düğüm root'dan küçükse sol alt ağaca gidiyor
    if (key < root->key)
        root->left = deleteNode(root->left, key);
  
    // Eğer silmek istediğimiz düğüm root'dan büyükse sağ alt ağaca gidiyor
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
  
    // Yukarıdaki şartlardan hiçbirisi sağlanmıyorsa aradığımız düğümü bulduk demektir.
    else
    {
        // Eğer düğümün solda çocuğu yoksa...
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        // eğer düğümün sağda çocuğu yoksa...
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
  
        // İşin en can alıcı noktası burası, şimdi düğümün 2 çocuğu varsa nasıl eleman sileceğiz ona bakıyoruz
        // minValueNode sağ alt ağaçtaki en küçük değeri bulur ve temp değerine atar.
        struct node* temp = minValueNode(root->right);
  
        // Burada atama işlemi yaptık
        root->key = temp->key;
  
        // Burada ise silme işlemini gerçekleştiriyoruz
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
  
//test aşaması
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
