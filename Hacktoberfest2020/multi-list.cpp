#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string data;
    Node* next;
};

Node* create_list(Node* root,string x){
    Node* temp=new Node;
    Node* temp2=root;
    temp->data=x;
    temp->next=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
    return root;
}

void print(Node* root,int i){
    cout<< i << " day of week->"<<" ";
    Node* temp2=root;
    while(temp2!=NULL){
        cout << temp2->data << " ";
        temp2=temp2->next;
    }
    cout << "\n";
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
             string input;
             cout << "Enter input Value: ";
             cin >> input; 
             arr[i]=create_list(arr[i],input);
         }
     }
     for(int i=0;i<7;++i){
         print(arr[i],i+1);
     }
    return 0;
}