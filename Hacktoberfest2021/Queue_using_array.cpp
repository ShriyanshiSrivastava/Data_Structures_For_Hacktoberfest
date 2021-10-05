// Implementation of queue using array in CPP
#include <bits/stdc++.h>

using namespace std;

// Defining Queue Data Structure
class Queue {
    public:
        int front;
        int rear;
        int size;
        unsigned capacity;
        int* array;
    };

// Function to create a queue of defined capacity. Initially the size is 0.
// It initializes size of queue as 0
Queue* create_queue(unsigned capacity)
{
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// This is important, see the enqueue
	queue->rear = capacity - 1;
	queue->array = new int[queue->capacity];
	return queue;
}

// Queue is full when size
// becomes equal to the capacity
int isFull(Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue* queue)
{
	return (queue->size == 0);
}

// Function to push an element to the queue
void enqueue(Queue* queue, int element)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)
				% queue->capacity;
	queue->array[queue->rear] = element;
	queue->size = queue->size + 1;
	cout << element << " enqueued to queue\n";
}

// Function to remove an element from the queue 
int dequeue(Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int element = queue->array[queue->front];
	queue->front = (queue->front + 1)
				% queue->capacity;
	queue->size = queue->size - 1;
	return element;
}

// Function to get the front element of the queue
int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 

// Function to get the rear element of the queue
int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}


int main()
{
	Queue* queue = create_queue(1000);

	enqueue(queue,1);
	enqueue(queue,2);
	enqueue(queue,3);
	cout << "Front element is " << front(queue) <<  "\n";
    cout << "Rear element is " << rear(queue) << "\n";
	cout << dequeue(queue) << " dequeued from queue\n";
    enqueue(queue,4);
	cout << "Front element is " << front(queue) <<  "\n";
    cout << "Rear element is " << rear(queue) << "\n";
    cout << isEmpty(queue) << "\n";
    cout << isFull(queue) << "\n";

	return 0;
}

// This code is contributed by rathbhupendra
