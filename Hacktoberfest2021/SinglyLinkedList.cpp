/*
    This code shows how to create a single linked list and traverse through it
*/

#include <iostream>
using namespace std;

//Structure for the node of single linked list
struct Node
{
    int data;
    Node* next;
};

//function to create a node with a particular data
Node* createNode(int data)
{
    Node *node= new Node();
    node->data=data;
    node->next=NULL;
    return node;
}

//inserting nodes to form the single linked list
Node* insert(Node *head, int data)
{
    //If head is NULL then th elinked list is empty
    if(head==NULL)
    head=createNode(data);
    else
    {
        Node *curr=head;
        //reaching to the last node of the linked list formed uptill now
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        //Linking a new node to the last node of the linked list
        curr->next=createNode(data);
    }
    
    return head;
}

//function to traverse through the linked list.It takes head of the linked list as parameter
void TraversingLinkedList(Node *head)
{
    //If head is NULL, then linked list is empty
    if(head==NULL)
    cout<<"Linked List is empty\n";
    else
    {
        cout<<"The linked list is: \n";
        Node *curr=head;//curr will point to the nodes of the linked list one by one in sequential manner
        //If curr is NULL, it means we have reached the end of the linked list
        while(curr!=NULL)
        {
            //Printing the data
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
}

int main()
{
//Forming the linked list
   Node *head=NULL;//Initially head is empty and points to NULL
   head=insert(head,10);
   insert(head,3);
   insert(head,98);
   insert(head,78);
   insert(head,3);
   //Traversing through the linked list
   TraversingLinkedList(head);
   return 0;
}


/* OUTPUT:
    The linked list is: 
    10 3 98 78 3
*/
