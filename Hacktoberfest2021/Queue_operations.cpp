#include <iostream>
using namespace std;
class queues
{

    int q[100]; //Queue as an array
    int f = -1; //Declaring front as -1
    int r = -1; //Declaring rear as -1
    int n;      //Number of elements to go in the queue

public:
    void enqueue(int ele); //Function to add an element into the queue
    int dequeue();         //Function to delete an element from the queue
    void display();        //For displaying the queue
    bool isfull();         //To check if the queue is full
    bool isempty();        //To check if the queue is empty
    int peek();            //To check the front element in the queue
};
int main()
{

    queues q;
    int n;
    cout << "Enter the number of elements to be inserted: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        q.enqueue(n);
    }
    q.display();

    int del;
    cout << "Enter the number of elements to be deleted: ";
    cin >> del;
    for (int i = 0; i < del; i++)
    {
        q.dequeue();
    }
    q.display();
    cout << "The element at peek is: " << q.peek();
}
void queues::enqueue(int size)
{
    int ele;
    cout << "Enter the element of the queue: ";
    cin >> ele;

    if (isfull()) //i.e r == n-1
    {
        cout << "Overflow" << endl; //Overflow is the condition where the queue is already full and no more elements can be inserted
        return;
    }
    else
    {
        if (isempty()) //since we are inserting the first element f and r is still -1 , so we have to increase f once and r for each element
        {
            f = 0;
        }
        r++;
        q[r] = ele; // placing the element as r is increased for every element
    }
}
int queues::dequeue()
{
    int temp;
    if (isempty()) // i.e f and r is -1
    {
        cout << "Underflow" << endl; //Underflow is the condition where the queue is empty and no elements are left to delete from it
    }
    else
    {
        temp = q[f]; //Storing the element to be stored as deletion is only from front in queues
        if (f >= r)
        {
            f = r = -1;
        }
        else
        {
            f++; //Simply increasing front so the elements will no longer count in the queue, hence deletion from the front
        }
    }
    cout << "Deleted element is: " << temp << endl;
}
void queues::display()
{
    if (isempty())
    {
        cout << "underflow";
    }
    else
    {
        cout << "The queue is: ";
        for (int i = f; i <= r; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
}
bool queues ::isempty()
{
    if (f == -1 && r == -1)
    {
        return true;
    }
    else
        return false;
}
bool queues::isfull()
{
    if (r == n - 1) // r =n-1 means that the rear pointer will point at the last index of the taken array(i.e for size = 5 r will be 4)
    {
        return true;
    }
    else
        return false;
}
int queues::peek()
{
    return q[f];
}
//Please notw that overflow condition will never be encountered in this code because we have enqueued the elements as per the size of array.