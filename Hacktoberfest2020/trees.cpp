#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
};

class Queue{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(){
        front=-1;
        rear=-1;
        size=10;
        Q=new Node*[size];
    }
    Queue(int s){
        front=-1;
        rear=-1;
        size=s;
        Q=new Node*[size];
    }
    
    void enqueue(Node *x){
        if(rear==size-1){
            cout << "Queue is full" << endl;
        }
        else if(front==-1 && size==-1){
            front=0;
            rear=0;
            Q[rear]=x;
        }
        else{
            rear++;
            Q[rear]=x;
        }
    }
    Node* dequeue(){
        Node* x;
        if(front==-1 && rear==-1){
            cout << "Queue is empty" << endl;
        }
        else if(front==rear){
            x=Q[front];
            front = -1;
            rear = -1;
        }
        else{
            x=Q[front];
            front++;
        }
        return x;
    }
    int isEmpty(){
        if(front==-1 && rear==-1){
            return 1;
        }
        else 
            return 0;
    }
};



class Tree{
    
public:
    Node *root;
    Tree():root(NULL){
        
    }
    void create_tree(){
        Queue q(100);
        Node *p,*t;
        int k;
        cout << "Enter root value: " << endl;
        cin >> k;
        root=new Node;
        root->data=k;
        root->left=NULL;
        root->right=NULL;
        q.enqueue(root);
        while(!q.isEmpty()){
            p=q.dequeue();
            cout << "Enter left child of: " << flush;
            cin >> k;
            if(k>-1){
                t=new Node;
                t->data=k;
                t->left=NULL;
                t->right=NULL;
                p->left=t;
                q.enqueue(t);
            }
            cout << "Enter right child of: " << flush;
            cin >> k;
            if(k>-1){
                t=new Node;
                t->data=k;
                t->left=NULL;
                t->right=NULL;
                p->right=t;
                q.enqueue(t);
            }
            
        }
    }
    
    void preorder(Node* root){
        Node *temp=root; 
        while(temp!=NULL){
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    
    void inorder(Node* root){
        Node *temp=root; 
        while(temp!=NULL){
            preorder(temp->left);
            cout << temp->data << " ";
            preorder(temp->right);
        }
    }
    
    void postorder(Node* root){
        Node *temp=root; 
        while(temp!=NULL){
            preorder(temp->left);
            preorder(temp->right);
            cout << temp->data << " ";
        }
    }
    
    void levelorder(Node* root){
        Queue q1;
        Node *temp,*t;
        q1.enqueue(root);
        while(!q1.isEmpty()){
            temp=q1.dequeue();
            cout << temp->data << " ";
            if(temp->left!=NULL){
                t=temp->left;
                q1.enqueue(t);
            }
            if(temp->right!=NULL){
                t=temp->right;
                q1.enqueue(t);
            }
        }
    }
    
    int height(Node* root){
        Node *temp=root;
        if(temp==NULL){
            return 0;
        }
        int m,n;
        m=height(temp->left);
        n=height(temp->right);
        if(m>n)
            return m+1;
        else
            return n+1;
    }
    
    int count(Node* root){
        Node *temp=root;
        if(temp==NULL){
            return 0;
        }
        int m,n;
        m=count(temp->left);
        n=count(temp->right);
        return m+n+1;
    }
    
    int leaf_node(Node* root){
        Node *temp=root;
        if(temp==NULL){
            return 0;
        }
        int m,n;
        m=count(temp->left);
        n=count(temp->right);
        if(temp->left==NULL && temp->right==NULL){
            return m+n+1;
        }
        else
            return m+n;
    }
};

int main(){
    Tree y;
    y.create_tree(y.root);
    y.preorder(y.root);
    cout << "\n";
    y.inorder(y.root);
    cout << "\n";
    y.postorder(y.root);
    cout << "\n";
    y.levelorder(y.root);
    cout << "\n";
    int h=y.height(y.root);
    int c=y.count(y.root);
    int l=y.leaf_node(y.root);
    cout << "Height = " << h << "\n" << "Number of nodes = " << c << "\n" << "Number of leaf nodes = " << l << endl;
    return 0;
}