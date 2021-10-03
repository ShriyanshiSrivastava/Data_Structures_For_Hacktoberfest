#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class linked_list
{
    private:
        node *head,*tail;
    public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(int n)
    {
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
    void display()
    {
        node *temp = new node;
        temp=head;
        cout<<"List : ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    int n,ch;
    linked_list a;
    cout<<"Enter the 1 to enter data and 2 to display and 0 to exit :-"<<endl;
    do
    {
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter data : ";
            cin>>n;
            a.add_node(n);
        }
        else if(ch==2)
        {
            a.display();
        }
    }
    while(ch);
    cout<<"Exit :)";
    return 0;
}
