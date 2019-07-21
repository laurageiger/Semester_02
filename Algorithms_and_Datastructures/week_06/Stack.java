public class Stack {
    private int capacity;
    private int index;
    private Node[] array;



    public Stack(int capacity){ // constructor
        this.array = new Node[capacity];
        this.capacity = capacity;
        this.index = 0;
    }


    public boolean push(Node node){ // push elem onto stack if not full
        if(this.index == this.capacity){
            return false;
        }
        this.array[this.index] = node;
        this.index++;
        return true;
    }

    public Node pop(){ // pop element and return it if stack not empty
        if(this.isEmpty()){
            return null;
        }
        this.array[this.index] = null;
        this.index--;
        return this.array[this.index];
    }

    public boolean isEmpty(){
        return (this.index == 0);
    }

}