#include <iostream>
using namespace std;

class queue_ll
{
private:
    struct node
    {
        int data;          // To store the value in the node
        node *next = NULL; // node to store address of the next node
    };
    node *front;
    node *rear;

public:
    queue_ll()
    {
        front = NULL; //Setting front and rear as NUll
        rear = NULL;
    }

    void enqueue(int num); //Function to add an element into the queue
    void dequeue();        //Function to delete an element from the queue
    void display();        //For displaying the queue
    bool isempty();        //To check if the queue is empty
    int peek();            //Return the front element in the queue
};
int main()
{
    queue_ll q;
    int n, ele, del;
    cout << "Enter the no of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element: ";
        cin >> ele;
        q.enqueue(ele); // Calling enqueue for every element to be inserted
    }
    q.display();

    cout << endl
         << "Enter no of elements you want to delete: ";
    cin >> del;
    for (int i = 0; i < del; i++)
    {
        q.dequeue();
    }
    q.display();
    cout << endl
         << "Peek element is: " << q.peek();
}
void queue_ll::enqueue(int ele)
{
    node *nn = new node;
    nn->data = ele;
    nn->next = NULL;
    if (front == NULL) // Case, where there are no elements in the queue
    {

        front = nn; // Both front and rear points to the node1
        rear = nn;
    }
    else
    {
        rear->next = nn; // Rear is still pointing to node1 therefore if we place address of node2 in the next of node1 it will create a link between the two nodes
        rear = nn;       // Now we let the pointer rear point towards node 2 making it the new rear, hence creating the list.
    }
}
void queue_ll::dequeue()
{

    int temp = front->data; // Storing data of the element to be deleted in temp variable
    cout << endl
         << "deleted element is: " << temp;
    front = front->next; // Now the front points to the next node, following the property of queue of deletion from front
}

void queue_ll ::display()
{
    if (isempty())
    {
        cout << endl
             << "underflow ";// Underflow is the condition where the queue is empty and no elements are left to be deleted from it
        return;
    }
    {
        struct node *ptr;
        ptr = front;
        cout << endl
             << "The queue is: ";
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