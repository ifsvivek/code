#include<stdio.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST node;
node* insert(node *root,int key)
{
	if(root==NULL)
	{
	
	root=(node*)malloc(sizeof(node));
	root->data=key;
	root->left=NULL;
	root->right=NULL;
	return root;
    }
    if(key<root->data)
    	root->left=insert(root->left,key);
    else if(key>root->data)
    	root->right=insert(root->right,key);
	return root;
}
void inorder(node  *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(node  *root)
{
	if(root!=NULL)
	{
		
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node  *root)
{
	if(root!=NULL)
	{
		
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}

void search(node *root, int key) 
{  
    if (root == NULL)
    	{
    		printf("key not found\n");
    		return;
		}
	 if(root->data == key)
	   {
          printf("key found\n");
		  return;	 	
	   }  
    if (key<root->data) 
       search(root->left, key); 
  else
       search(root->right, key); 
}
int main()
{
	int n,i,key,choice;
	node *root=NULL,*temp;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		printf("enter the element\n");
		scanf("%d",&key);
		root=insert(root,key);
	}
	while(1)
	{
		printf("enter 1 for inorder\n 2 for preorder\n 3 for postorder\n 4 for search\n 5 for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\ninorder is \n");
	               inorder(root);
	               break;
	        case 2: printf("\npre order is \n");
	                preorder(root);
	                break;
	         case 3:  printf("\npost order is \n");
	                  postorder(root);
	                  break;
	        case 4:printf("\nenter the element to be searched");
	            scanf("%d",&key);
	            search(root,key);
	            break;
	        case 5: exit(0);
	        default:printf("invalid choice\n");
		}
	}
}
