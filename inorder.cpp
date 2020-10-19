/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct btnode
{
    int data;
    struct btnode *left;
    struct btnode *right;
};
struct btnode *root;
struct btnode* createbtnode(int n)
{
    struct btnode *node= (struct btnode*)malloc(sizeof (struct btnode));
    node->data=n;
    node->left=NULL;
    node->right=NULL;
    return node;
    
}
void inorder(struct btnode *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
int main()
{
   int ch,n,c;
   while(1)
   {
   printf("1.enter elements to tree\n2.inorder traversal.\n6.exit\n");
   printf("enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
       case 1: root=createbtnode(1);
       root->left=createbtnode(2);
       root->right=createbtnode(3);
       root->left->left=createbtnode(4);
       root->left->right=createbtnode(5);
       break;
       case 2: inorder(root);
       printf("\n");
       break;
       case 6:exit(0);
       break;
       default:printf("invalid choice\n");
   }
   }

    return 0;
}