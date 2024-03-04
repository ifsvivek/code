#include <stdio.h>
#include <stdlib.h>
struct BST {
  int data;
  struct BST* left;
  struct BST* right;
};
typedef struct BST node;
node* insert(node* root, int key) {
  if (root == NULL) {
    root = (node*)malloc(sizeof(node));
    root->data = key;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  if (key < root->data)
    root->left = insert(root->left, key);
  else if (key > root->data)
    root->right = insert(root->right, key);
  return root;
}
void inorder(node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
  }
}
void preorder(node* root) {
  if (root != NULL) {
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(node* root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
  }
}

void search(node* root, int key) {
  if (root == NULL) {
    printf("Key not found\n");
    return;
  }
  if (root->data == key) {
    printf("Key found\n");
    return;
  }
  if (key < root->data)
    search(root->left, key);
  else
    search(root->right, key);
}
node* delete(node* root,int key){
    if(root==NULL){
        printf("Key not found\n");
        return NULL;
    }
    if(key<root->data)
        root->left=delete(root->left,key);
    else if(key>root->data)
        root->right=delete(root->right,key);
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            node* temp =root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            node* temp =root;
            root=root->left;
            free(temp);
        }
        else{
            node* temp = root->right;
            while(temp->left!=NULL)
                temp=temp->left;
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
}
int main() {
  int n, i, key, choice;
  node *root = NULL, *temp;
  printf("Enter the number of nodes\n");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter the element\n");
    scanf("%d", &key);
    root = insert(root, key);
  }
  while (1) {
    printf("\nEnter Choice\n1. Inorder\n2. Preorder\n3. Postorder\n4. Search\n5. Delete\n6.Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:printf("\nInorder is \n");
             inorder(root);break;
      case 2:printf("\nPre order is \n");
             preorder(root);break;
      case 3:printf("\nPost order is \n");
             postorder(root);break;
      case 4:printf("\nEnter the element to be searched: ");
             scanf("%d", &key);
             search(root, key);break;
      case 5:
           printf("\nEnter the element to be deleted: ");
            scanf("%d", &key);
            root=delete(root,key);
            break;
      case 6:
          exit(0);
      default:printf("Invalid choice\n");
    }
  }
}
