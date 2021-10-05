#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
  int data;
  node* next;
};

node* newnode(int key)
{
  node* node=new node;
  node->data=key;
  node->next=NULL;
  return node;
}

void printlist(node* head)
{
  node* p=head;
  while(!p=NULL)
  {
    cout<<p->data;
    p=p->next;
  }
}

void appendnode(node** head, int key)
{
  node* current=*head;
  node* node=newnode(key);
  if(current==NULL)
  {
    *head=node;
  }
  else
  {
    while(current->next!=NULL)
    {
      current=current->next;
    }
    current->next=node;
  }
}

int main()
{
  int keys[]={1,2,3,4};
  int n=sizeof(keys)/sizeof(key[0]);
  struct node* head=NULL;
  for(int i=0; i<n; i++)
  {
    appendnode(&head,keys[i]);
  }
  printlist(head);
  return 0;
}
