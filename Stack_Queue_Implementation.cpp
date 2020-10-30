#include <iostream>
using namespace std;
int stack1[100],top = -1; //globally defining the value of top ,as the stack is empty .
void push (int stack1[ ] , int x , int n)
{
    if ( top == n-1 )          //if top position is the last of position of stack, means stack is full .
    {
        cout <<"Stack is full. Overflow condition!"<<endl;
    }
    else
    {
        top = top +1 ;          //incrementing top position
        stack1[ top ] = x ;       //inserting element on incremented position .
    }
}
bool isEmpty ( )
{
    if ( top == -1 )  //stack is empty .
        return true ;
    else
        return false;
}
void pop (int stack1[ ] ,int n )
{

    if( isEmpty ( ) )
    {
        cout <<"Stack is empty . Underflow condition! "<< endl ;
    }
    else
    {
         top = top - 1 ; //decrementing top’s position will detach last element from stack .
    }
}
int size1( )
{
    return top + 1;
}
int topElement (int stack1[] )
{
    return stack1[top];
}
void Display_st()
{
    if (top == - 1)
        cout<<"Stack is empty"<<endl;
    else
    {
        cout<<"Stack elements are : ";
        for(int i = 0; i <= top; i++)
            cout<<stack1[i]<<" ";
        cout<<endl;
    }
}
// Now lets implementing these functions on the above stack
int queue1[100], n = 100, front1 = - 1, rear = - 1;
void Insert()
{
    int val;
    if (rear == n - 1)
    cout<<"Queue Overflow"<<endl;
    else
    {
        if (front1 == - 1)
        front1 = 0;
        cout<<"Insert the element in queue : "<<endl;
        cin>>val;
        rear++;
        queue1[rear] = val;
    }
}
void Delete()
{
    if (front1 == - 1 || front1 > rear)
    {
        cout<<"Queue Underflow ";
        return ;
    }
    else
    {
        cout<<"Element deleted from queue is : "<< queue1[front1] <<endl;
        front1++;;
    }
}
void Display()
{
    if (front1 == - 1)
        cout<<"Queue is empty"<<endl;
    else
    {
        cout<<"Queue elements are : ";
        for(int i = front1; i <= rear; i++)
            cout<<queue1[i]<<" ";
        cout<<endl;
    }
}
int main( )
{
    int ch,chx;
    do
    {
        cout<<"1) Insert in stack"<<endl;
        cout<<"2) Insert in queue"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>chx;
        switch(chx)
        {
            case 1:
                cout<<"\n1) Insert element to stack"<<endl;
                cout<<"2) Delete element from stack"<<endl;
                cout<<"3) Display all the elements of stack"<<endl;
                cout<<"4) Exit"<<endl;
                do
                {
                    cout<<"Enter your choice : ";
                    cin>>ch;
                    switch (ch)
                    {
                        case 1: int n;
                            cout<<"Enter data : ";
                            cin>>n;
                            push(stack1 , n , 100);
                            break;
                        case 2: pop(stack1,100);
                            break;
                        case 3: Display_st();
                            break;
                        case 4: cout<<"Exit"<<endl;
                            break;
                        default: cout<<"Invalid choice"<<endl;
                    }
                    cout<<endl;
                }while(ch!=4);
                break;
            case 2:
                cout<<"\n1) Insert element to queue"<<endl;
                cout<<"2) Delete element from queue"<<endl;
                cout<<"3) Display all the elements of queue"<<endl;
                cout<<"4) Exit"<<endl;
                do
                {
                    cout<<"Enter your choice : ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1: Insert();
                            break;
                        case 2: Delete();
                            break;
                        case 3: Display();
                            break;
                        case 4: cout<<"Exit"<<endl;
                            break;
                        default: cout<<"Invalid choice"<<endl;
                    }
                    cout<<endl;
                }while(ch!=4);
                break;
            case 3: cout<<"\nExit"<<endl;
                break;
                cout<<endl;
            default: cout<<"\nInvalid choice"<<endl;
            cout<<endl;
        }
    }while(chx!=3);
    return 0;
}
