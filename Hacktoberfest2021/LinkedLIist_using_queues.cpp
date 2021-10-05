#include <iostream>
using namespace std;

class queue_ll
{
private:
    struct node
    {
        int data;
        node *next = NULL;
    };
    node *front;
    node *rear;

public:
    queue_ll()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int num);
    void dequeue();
    void display();
    bool isempty();
    int peek();
};
int main()
{
    queue_ll q;
    int n, ele,del;
    cout << "Enter the no of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element: ";
        cin >> ele;
        q.enqueue(ele);
    }
     q.display();

     cout<<endl<<"Enter no of elements you want to delete: ";
     cin>>del;
     for (int i = 0; i < del; i++)
    {
            q.dequeue();
    }
    q.display();
    cout << endl << "Peek element is: " << q.peek();
}
void queue_ll::enqueue(int ele)
{
    node *nn = new node;
    nn->data = ele;
    nn->next = NULL;
    if (front == NULL)
    {
        // nn->data = ele;
        // nn->next = NULL;
        front = nn;
        rear = nn;
    }
    else
    {
        // node *nn1 = rear;
        // nn1->next = nn;
        // rear = nn;
        rear->next = nn;
	    rear = nn;
    }
}
void queue_ll::dequeue()
{

    int temp = front->data;
    cout << endl
         << "deleted element is: " << temp;
    front = front->next;
}

void queue_ll ::display()
{
    if(isempty()){
        cout<<endl<<"underflow ";
        return;
    }
    {
        struct node *ptr;
        ptr = front;
        cout<<endl<<"The queue is: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}
bool queue_ll::isempty()
{
    if (front == NULL)
        return true;
    else
    {
        return false;
    }
}
int queue_ll::peek()
{
    return front->data;
}