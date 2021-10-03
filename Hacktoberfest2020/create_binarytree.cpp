/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int c=0;
struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};
struct bstnode *root;
void createbstnode(int n)
{
    struct bstnode *parent;
    struct bstnode *node= (struct bstnode*)malloc(sizeof (struct bstnode));
    node->data=n;
    node->left=NULL;
    node->right=NULL;
    parent=root;
    if(root==NULL)
    {
        root=node;
    }
    else
    {
        struct bstnode* curr;
        curr=root;
        while(curr)
        {
            parent=curr;
            if(node->data>curr->data)
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        if(node->data>parent->data)
        {
            parent->right=node;
        }
        else
        {
            parent->left=node;
        }
    }
}
int main()
{
   int ch,n;
   while(1)
   {
   printf("1.enter elements to tree\n5.exit\n");
   printf("enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
       case 1: createbstnode(50);
       createbstnode(60);
       createbstnode(30);
       createbstnode(70);
       createbstnode(20);
       createbstnode(65);
       createbstnode(25);
       break;
       default:printf("invalid choice\n");
   }
   }
    return 0;
}

