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

int height(struct btnode*root,int c)
{
    if(root==NULL)
    return 0;
    else
    {
     int i=height(root->left,i);
     int j=height(root->right,j);
     if(i>j)
     return i+1;
     else
     return j+1;
    }
    
    
}

int main()
{
   int ch,n,c;
   while(1)
   {
   printf("1.enter elements to tree\n2.height of tree\n3.exit\n");
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
       case 2:c=height(root,0);
       printf("the height of tree %d",c);
       case 3:exit(0);
       break;
       default:printf("invalid choice\n");
   }
   }

    return 0;
}