#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

void push(Node**head_ref, int new_data)
{
    Node * new_node=new Node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    new_node->prev=NULL;

    if(*head_ref!=NULL)
    {
        (*head_ref)->prev=new_node;
    }

    (*head_ref) = new_node;

}

void printDLL(Node*node)
{
    Node * last;
    cout<<"FORWARD DIRECTION"<<endl;
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        last=node;
        node=node->next;
    }

    cout<<endl;

    cout<<"REVERSE DIRECTION"<<endl;

    while(last!=NULL)
    {
        cout<<last->data<<" ";
        last=last->prev;
    }

    cout<<endl;
}

void deleteNode(Node** head_ref, Node* del) {
   if (*head_ref == NULL || del == NULL) {
      return;
   }
   // head node
   if (*head_ref == del) {
      *head_ref = del->next;
   }
   // middle node
   if (del->next != NULL) {
      del->next->prev = del->prev;
   }
   // end node
   if (del->prev != NULL) {
      del->prev->next = del->next;
   }
   free(del);
}
void deleting(Node** head_ref, int n) {
   if (*head_ref == NULL || n <= 0) {
      return;
   }
   Node* current = *head_ref;
   int i;
   for (int i = 1; current != NULL && i < n; i++) {
      current = current->next;
   }
   if (current == NULL) {
      return;
   }
   deleteNode(head_ref, current);
}
   
int main()
{
    Node * head=NULL;
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    printDLL(head);
    deleting(&head,1);
    printDLL(head);
    deleting(&head,3);
    printDLL(head);
    return 0;
}
