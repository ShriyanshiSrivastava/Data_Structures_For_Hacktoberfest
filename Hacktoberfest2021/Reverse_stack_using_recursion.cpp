//This is the code for Reversal of Stack using Recursion
#include<iostream>
using namespace std;
class stack
{
  public:
  int size;
  int top;
  int *arr;
  stack(int s)//Constructor
  {
    arr=new int[s];
    size=s;
    top=-1;
  }
  void push(int data)//Push into stack
  {
    if(top==size-1)
    {
      cout<<"Stack Overflow!"<<endl;
    }
    else
    {
      arr[++top]=data;
    }
  }
  void pop()//Pop the value from stack
  {
    if(top==-1)
    {
     cout<<"Stack Empty!"<<endl;
    }
    else
    {
      top--;
    }
  }
  int topElement()//Feth the top element
  {
    return arr[top];
  }
  bool isEmpty()//Check whether stack is empty or not
  {
    if(top==-1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  void display()//Display the stack
  {
    if(top==-1)
    {
      cout<<"Stack Empty!"<<endl;
    }
    else
    {
      while(!isEmpty())
      {
        cout<<topElement()<<" ";
        pop();
      }
      cout<<endl;
    }
  }
  void pushAtPosition(int x)//Insert at correct position
  {
    if(isEmpty())
    {
      push(x);
    }
    else
    {
      int y=topElement();
      pop();
      pushAtPosition(x);
      push(y);
    }
  }
  void reverse()
  {
    if(!isEmpty())
    {
      int x=topElement();
      pop();
      reverse();
      pushAtPosition(x);
    }
  }
};
int main(int argc, char const *argv[])
{
  int n,x;
  cout<<"Enter the Stack size: ";
  cin>>n;
  stack st(n);
  cout<<"Enter the values: ";
  for(int i=0;i<n;i++)
  {
    cin>>x;
    st.push(x);
  }
  st.reverse();
  cout<<"Displaying Stack after reversing: ";
  st.display();
  return 0;
}