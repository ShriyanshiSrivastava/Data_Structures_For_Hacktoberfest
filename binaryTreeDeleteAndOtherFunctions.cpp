#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

class queues{
    int size;
    int front;
    int rear;
    Node **Q;
public:
    queues():size(100){
        front = rear = -1;
        Q=new Node*[size];
    }
    queues(int s):size(s){
        front = rear = -1;
        Q=new Node*[size];
    }
    void push(Node* x){
        if(front==-1 && rear==-1){
            front=rear=0;
            Q[rear]=x;
        }
        else{
            rear++;
            Q[rear]=x;
        }
    }
    Node* pop(){
        Node* x;
        if(front==rear){
            x=Q[front];
            front=rear=-1;
        }
        else{
            x=Q[front];
            front++;
        }
        return x;
    }
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else return false;
    }
};

Node* create_node(int x){
    Node* temp=new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

Node* create_tree(Node* root, int x){
    if (root==NULL){
        root=create_node(x);
    }
    else if(root->data>x){
        root->left=create_tree(root->left,x);
    }
    else{
        root->right=create_tree(root->right,x);
    }
    return root;
}

Node* level_order(Node* root,int k){
    Node* p;
    queues q;
    q.push(root);
    while(!q.isEmpty()){
        p=q.pop();
        if(p->left!=NULL){
            q.push(p->left);
        }
        else if(p->left==NULL){
            Node* temp=create_node(k);
            p->left=temp;
            return root;
        }
        if(p->right!=NULL){
            q.push(p->right);
        }
        else if(p->right==NULL){
            Node* temp=create_node(k);
            p->right=temp;
            return root;
        }
    }
}

void print_level_order(Node* root){
    Node* p;
    queues q;
    q.push(root);
    while(!q.isEmpty()){
        p=q.pop();
        cout << p->data << " ";
        if(p->left!=NULL){
            q.push(p->left);
        }
        if(p->right!=NULL){
            q.push(p->right);
        }
    }
    cout << "\n";
}


void print_inorder(Node* root){
    if(root!=NULL){
        print_inorder(root->left);
        cout << root->data << " ";
        print_inorder(root->right);
    }
}


Node* find_min_in_right_subtree(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
} 

Node* delete_node(Node* root,int k){
    if(root==NULL){
        return root;
    }
    else if(root->data>k){
        root->left=delete_node(root->left,k);
    }
    else if(root->data<k){
        root->right=delete_node(root->right,k);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node* temp=find_min_in_right_subtree(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }
    }
}

int main(){
    Node *root=NULL;
    root=create_tree(root,50);
    root=create_tree(root,30);
    root=create_tree(root,20);
    root=create_tree(root,40);
    root=create_tree(root,70);
    root=create_tree(root,60);
    root=create_tree(root,80);
    print_inorder(root);
    cout << "\n";
    level_order(root,12);
    print_level_order(root);
    root=delete_node(root,20);
    cout << "\n";
    print_level_order(root);
    root=delete_node(root,30);
    cout << "\n";
    print_level_order(root);
    return 0;
}