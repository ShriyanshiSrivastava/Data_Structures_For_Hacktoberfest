package QueueJava;

public class QueueOperations {
    static int front, rear, capacity, size;

    // Declaring the Queue as an array
    int Q[];

    public QueueOperations(int capacity){
        this.capacity = capacity; // Initializing th Queue with a fixed capacity
        Q = new int[capacity];
        front = this.size = 0;
        rear = capacity - 1;
    }

    // Function to check if the queue is full or not
    // Queue is full when size reaches its capacity
    public boolean isFull(){
        return Q.length == this.size;
    }

    // Function to check if Queue is completely empty or not
    // Queue is empty when size of it is 0
    public boolean isEmpty(){
        return size == 0;
    }

    // Function that returns the front element of the Queue
    public int front(){
        return Q[front];
    }

    // Function that returns the last element of the Queue
    public int rear(){
        return  Q[rear];
    }

    // Function to add an elelment in the Queue
    public void enqueue(int num){
       if(isFull()) return;
        rear = (rear + 1) % capacity;
        this.Q[rear] = num; // Adds the element at the end of the Queue
        size = size + 1;
    }

    // // Function to remove an elelment in the Queue
    public int dequeue(){
        int item = this.Q[front]; // Stores the first element to return when removed
        front = (front + 1) % capacity;
        size = size - 1; // Reduce the Queue size by 1
        return item;
    }

    // Driver method to verify the implementation of the Queue
    public static void main(String[] args) {
        QueueOperations q = new QueueOperations(3);
        System.out.println(q.isEmpty());
        System.out.println(q.isFull());
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        System.out.println(q.isFull());
        System.out.println(q.front());
        q.dequeue();
        System.out.println(q.front());
        q.dequeue();
        q.dequeue();
        System.out.println(q.isEmpty());
        System.out.println(q.isFull());

    }


}
