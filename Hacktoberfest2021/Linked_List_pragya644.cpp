#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
} *head = NULL;

void Insert_At_Tail(node **head_ref, int value)
{
    node *new_node;
    new_node = new node;
    new_node->data = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Display(node*t)
{
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
}
int main()
{
    Insert_At_Tail(&head,10);
    Insert_At_Tail(&head,20);
    Insert_At_Tail(&head,30);

    Display(head);
    return 0;
}