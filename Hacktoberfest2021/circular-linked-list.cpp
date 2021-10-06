#include <iostream>
using namespace std;

class cll
{
    struct node
    {

        int data;
        struct node *next;
    };
    struct node *head;

public:
    cll()
    {
        head = NULL;
    }
    void create();
    void disp();

};

int main()
{
    cll l1;

    l1.create();
     cout<<"The circular linkedlist is: ";
    l1.disp();
 
}

void cll::create()
{
    int n, num;
    cout << "Enter number of elements: ";
    cin >> n;
    node *save = new node;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the element: ";
        cin >> num;
        // cout<<endl;

        node *temp = new node();
        if (head == NULL)
        {
            head = temp;
            save = head;
            temp->data = num;
            temp->next = head;
        }
        else
        {
            temp->data = num;
            temp->next = head;
            head = temp;
            save->next = head;
        }
    }
}
void cll::disp()
{
    node *ptr = head;
    while (ptr->next != head)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout<<ptr->data<<" ";
}


