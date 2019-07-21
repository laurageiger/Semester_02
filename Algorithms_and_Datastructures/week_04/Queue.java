package at.ac.uibk;

public class Queue {
    private Integer[] array;
    private int capacity;
    private int f;
    private int r;

    public static void main(String[] args) {
        Queue queue = new Queue(5);

        queue.enqueue(5);
        queue.enqueue(1);
        System.out.println(queue.first());
        System.out.println(queue.dequeue());
        queue.enqueue(2);
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.isEmpty());
    }

    public Queue(int capacity){ // constructor
        this.array = new Integer[capacity];
        this.capacity = capacity;
        this.f = 0;
        this.r = 0;
    }

    public void enqueue(int elem){ // add elem if queue is not full
        if(((this.r+1)%this.capacity) == (this.f%this.capacity)){ // checks if queue is full
            System.out.println("Error: Queue is full");
        }
        else{
            this.array[this.r] = elem;
            this.r = (this.r+1)%this.capacity;
        }
    }

    public Integer first(){ // return first element of queue
        if(this.isEmpty()){
            return null;
        }
        return this.array[f];
    }

    public int dequeue(){ // delete element if queue is not empty
        if(this.isEmpty()){
            System.out.println("Queue is empty");
        }
        int t = this.array[f];
        this.array[f] = null;
        this.f = (this.f+1)%this.capacity;
        return t;
    }

    public boolean isEmpty(){
        return (this.f == this.r);
    }

}
