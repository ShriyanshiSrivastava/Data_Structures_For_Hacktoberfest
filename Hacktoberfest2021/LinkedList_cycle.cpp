//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    int flag;
};
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;

    /* put in the data */
    new_node->data = new_data;

    new_node->flag = 0;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
bool hasCycle(Node *head) {
        unordered_set<Node*> s;
        while(head!=NULL){
            if(s.find(head)!=s.end())
                return true;
            s.insert(head);
            head=head->next;
        }
        return false;
}

int main(){
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;
    if (hasCycle(head))
        cout << "Cycle found";
    else
        cout << "No Cycle";

    return 0;
}
