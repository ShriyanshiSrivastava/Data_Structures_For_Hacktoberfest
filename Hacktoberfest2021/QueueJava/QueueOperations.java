package QueueJava;

public class QueueOperations {
    static int front, rear, capacity, size;

    int Q[];

    public QueueOperations(int capacity){
        this.capacity = capacity;
        Q = new int[capacity];
        front = this.size = 0;
        rear = capacity - 1;
    }

    public boolean isFull(){
        return Q.length == this.size;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public int front(){
        return Q[front];
    }

    public int rear(){
        return  Q[rear];
    }

    public void enqueue(int num){
       if(isFull()) return;
        rear = (rear + 1) % capacity;
        this.Q[rear] = num;
        size = size + 1;
    }

    public int dequeue(){
        int item = this.Q[front];
        front = (front + 1) % capacity;
        size = size - 1;
        return item;
    }

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
