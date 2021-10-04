#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};


void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node;

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}


int counting(Node * ptr)
{
    int count = 0;

    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;

    }

    return count;
}

int Adding(Node* add)
{
    Node * ptr=add;
    int sum=0;
    while(ptr!=NULL)
    {
        sum+=ptr->data;
        ptr=ptr->next;
    }

    return sum;
}

int main()
{
    Node* head = NULL;
 
    push(&head, -10);
    push(&head, 1);
    push(&head, 8);
    push(&head, 6);
    push(&head, 7);
    push(&head, 10);
    push(&head, 15);
    push(&head, 18);
    push(&head, 25);
    push(&head, 50);

    cout << "Sum of nodes = "<< Adding(head);

    cout<<endl<<"Number of Nodes= "<<counting(head)<<endl;


    return 0;
}


