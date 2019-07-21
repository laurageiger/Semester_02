import java.util.Iterator;
public class BinarySearchTree {

    private Node root;

    public BinarySearchTree() {
        this.root = null;
    }

    public Node addRoot(int data){
        this.root = new Node(data);
        return this.root;
    }

    public Node addRight(int data, Node node){
        Node rightChild = new Node(data);
        node.setRight(rightChild);
        return rightChild;
    }

    public Node addLeft(int data, Node node){
        Node leftChild = new Node(data);
        node.setLeft(leftChild);
        return leftChild;
    }

    public Node addNode(int data, Node node){ // recursive function for adding nodes in a sorted way
        if(data > node.data){
            if(node.getRight() == null) {
                return addRight(data, node);
            }
            else{
                return addNode(data, node.getRight());
            }
        }
        else if(data < node.data){
            if(node.getLeft() == null){
                return addLeft(data, node);
            }
            else{
                return addNode(data, node.getLeft());
            }
        }
        return root;
    }

    public void print(){ // caller function for the recursive printRec function
        printRec(this.root);
    }

    public void printRec(Node root){

        if(root != null){
            printRec(root.left);
            System.out.print(root.data + " ");
            printRec(root.right);
        }
    }

    public Iterator breadthFirst() { // returning breadth first iterator
        return new BreadthFirstIterator();
    }

    private class BreadthFirstIterator implements Iterator {
        private Queue queue;

        public BreadthFirstIterator(){
            queue = new Queue(10);
            queue.enqueue(root);
        }

        @Override
        public boolean hasNext() {
            return !queue.isEmpty();
        }

        @Override
        public Node next() {
            Node node = queue.dequeue();

            if(node.left != null){
                queue.enqueue(node.getLeft());
            }
            if(node.right!= null){
                queue.enqueue(node.getRight());
            }

            return node;
        }
    }


    public Iterator depthFirst() { // returning depth first iterator
        return new DepthFirstIterator();
    }

    private class DepthFirstIterator implements Iterator {
        private Stack stack;

        public DepthFirstIterator(){
            stack = new Stack(10);
            stack.push(root);
        }

        @Override
        public boolean hasNext() {
            return !stack.isEmpty();
        }

        @Override
        public Node next() {
            Node node = stack.pop();

            if(node.right != null){
                stack.push(node.getRight());
            }
            if(node.left != null){
                stack.push(node.getLeft());
            }

            return node;
        }
    }

    public Node getRoot() {
        return root;
    }

    public void setRoot(Node root) {
        this.root = root;
    }
}
