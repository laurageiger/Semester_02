public class Queue {
    private Node[] array;
    private int capacity;
    private int f;
    private int r;

    public Queue(int capacity){ // constructor
        this.array = new Node[capacity];
        this.capacity = capacity;
        this.f = 0;
        this.r = 0;
    }

    public void enqueue(Node node){ // add elem if queue is not full
        if(((this.r+1)%this.capacity) == (this.f%this.capacity)){ // checks if queue is full
            System.out.println("Error: Queue is full");
        }
        else{
            this.array[this.r] = node;
            this.r = (this.r+1)%this.capacity;
        }
    }
    public Node first(){ // return first element of queue
        if(this.isEmpty()){
            return null;
        }
        return this.array[f];
    }

    public Node dequeue(){ // delete element if queue is not empty
        if(this.isEmpty()){
            System.out.println("Queue is empty");
        }
        Node t = this.array[f];
        this.array[f] = null;
        this.f = (this.f+1)%this.capacity;
        return t;
    }

    public boolean isEmpty(){
        return (this.f == this.r);
    }

}
