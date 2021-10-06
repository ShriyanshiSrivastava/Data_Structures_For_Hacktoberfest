#include <iostream>
using namespace std;
struct Node 
{
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};
struct LL
{
	Node* head;
	LL() 
    { 
        head = NULL; 
    }
	void reverse()
	{
		Node* current = head;
		Node *prev = NULL, *next = NULL;
		while (current != NULL) 
        {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};
int main()
{
	LL ob;
	ob.push(1);
	ob.push(2);
	ob.push(3);
	ob.push(4);
	cout << "Original linked list"<<endl;
	ob.print();
	ob.reverse();
	cout << "\nLinked list after reversing"<<endl;
	ob.print();
	return 0;
}
