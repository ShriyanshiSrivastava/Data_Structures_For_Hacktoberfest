#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string data;
    int slot;
    Node* next;
};

Node* create_list(Node* root,string x, int time){
    Node* temp=new Node;
    Node* temp2=root;
    temp->data=x;
    temp->slot=time;
    temp->next=NULL;
    if(root==NULL || root->slot > time){
        temp->next=temp2;
        root=temp;
    }
    else{
        while(temp2->next!=NULL && temp2->next->slot < time){
            temp2=temp2->next;
        }
        temp->next=temp2->next;
        temp2->next=temp;
    }
    return root;
}

void print(Node* root,int i){
    cout<< i << " day of week->"<<" ";
    Node* temp2=root;
    while(temp2!=NULL){
        cout << temp2->data << " " << temp2->slot << "   ";
        temp2=temp2->next;
    }
    cout << "\n";
}

int count(Node* root){
    Node * temp=root;
    int c1=0;
    while(temp!=NULL){
        c1++;
        temp=temp->next;
    }
    return c1;
}

int main(){
     Node* arr[7];
     for(int i=0;i<7;++i){
         arr[i]=NULL;
     }
     for(int i=0;i<7;++i){
         cout << "Enter how many values you want to enter in list " << i+1 << endl;
         int k;
         cin >> k;
         for(int j=0;j<k;++j){
             string input;int time;
             cout << "Enter input Value: ";
             cin >> input >> time; 
             arr[i]=create_list(arr[i],input,time);
         }
     }
     for(int i=0;i<7;++i){
         print(arr[i],i+1);
     }
    int max[2]={0,0};
    for(int i=0;i<7;++i){
        int l=count(arr[i]);
        if(l>max[1]){
            max[1]=l;
            max[0]=i;
        }
    }
    cout << "Bussiest day is " << max[0]+1 << " day of week." << endl;
    return 0;
}