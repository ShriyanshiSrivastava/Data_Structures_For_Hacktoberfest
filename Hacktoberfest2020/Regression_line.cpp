#include<bits/stdc++.h>
#include <iostream>
using namespace std;
class node
{
    public:
    long double data;
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
    node* head_out()
    {
        return head;
    }
    void display()
    {
        node *temp = new node;
        temp=head;
        cout<<"List : ";
        while(temp->next!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
	long long int ch,n,i,j,p=0;
	linked_list LL[4];
	long double s1=0,s2=0,s3=0,s4=0;
    cout<<" Enter the Xi elements ::"<<endl;
	cout<<" Enter the 1 to enter data and 0 to exit :"<<endl;
    do
    {
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter data : ";
            cin>>n;
            LL[0].add_node(n);
            s1+=n;
            p++;
        }
        else if(ch!=0)
            cout<<"Invalid input !!"<<endl;
    }
    while(ch);
	cout<<"\n The sum of Xi is ::"<<s1<<endl<<endl;
    cout<<" Enter Yi elements ::"<<endl;
    cout<<" Enter the 1 to enter data and 0 to exit :"<<endl;
    do
    {
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter data : ";
            cin>>n;
            LL[1].add_node(n);
            s2+=n;
        }
        else if(ch!=0)
            cout<<"Invalid input !!"<<endl;
    }
    while(ch);
    cout<<endl<<endl;
    cout<<" The Sum of Yi is ::"<<s2<<endl<<endl;
    if(s1>0)
        cout<<" The Equation 1 is ::\n "<<fixed<<s2<<" = a"<<p<<"  + "<<fixed<<s1<<"b "<<endl;
    else
        cout<<" The Equation 1 is ::\n "<<fixed<<s2<<" = a"<<p<<"  "<<fixed<<s1<<"b "<<endl;
    cout<<endl<<endl;
    node *temp1,*temp2;
    temp1=LL[0].head_out();
    temp2=LL[1].head_out();
    while(temp1!=NULL)
    {
        LL[2].add_node(temp1->data*temp2->data);
        s3+=temp1->data*temp2->data;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<" The Sum of Xi*Yi is ::"<<fixed<<s3<<endl;
    temp1=LL[0].head_out();
    temp2=LL[0].head_out();
    while(temp1!=NULL)
    {
        LL[3].add_node(temp1->data*temp2->data);
        s4+=temp1->data*temp2->data;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<"\n The sum of Xi*Xi is ::"<<fixed<<s4<<endl;
    cout<<" \n The Equation 2 is ::\n ";
    cout<<fixed<<s3<<" = a"<<s1<<" +  b"<<fixed<<s4<<endl;

    // FOR REGRESSION LINE
    long double a,b;
    b=((s1*s2)-(p*s3))/((s1*s1)-(s4*p));
    a=((s2-(s1*b))/p);
    cout<<"\nFor regression line :-"<<endl<<" a = "<<fixed<<a<<" and b = "<<fixed<<b<<endl;
    cout<<" Equation of line :: y = "<<fixed<<a<<" + "<<fixed<<b<<"x"<<endl<<endl;

    //for R^2
    long double y_mean,denominator=0,numerator=0,R_sq;
    y_mean=s2/p;
    temp1=LL[0].head_out();
    temp2=LL[1].head_out();
    while(temp2!=NULL)
    {
        denominator+=(temp2->data-y_mean)*(temp2->data-y_mean);
        temp2=temp2->next;
    }
    while(temp1!=NULL)
    {
        numerator+=(a+(b*temp1->data)-y_mean)*(a+(b*temp1->data)-y_mean);
        temp1=temp1->next;
    }
    R_sq=numerator/denominator;
    cout<<"For Coefficient of Determination (R2) :-\n";
    cout<<" The numerator for R^2 = "<<fixed<<numerator<<endl;
    cout<<" The denominator for R^2 = "<<fixed<<denominator<<endl;
    cout<<" R^2 = "<<fixed<<R_sq<<endl<<endl;
    return 0;
}
