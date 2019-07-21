import java.util.Iterator;

public class BinarySearchTreeTest {
    public static void main(String[] args) {
        BinarySearchTree tree1 = new BinarySearchTree();
        Node root = tree1.addRoot(10);
        tree1.addNode(5, root);
        tree1.addNode(2, root);
        tree1.addNode(7, root);
        tree1.addNode(12, root);
        tree1.addNode(11, root);
        tree1.addNode(20, root);

        System.out.print("Print In-Order(Recursion):\n");
        tree1.print();

        System.out.println("\n");

        System.out.print("Print in breadth first order (Iterator):\n");
        Iterator<Node> breadthFirst = tree1.breadthFirst();
        while (breadthFirst.hasNext()) {
            System.out.print(breadthFirst.next().getData() + " ");
        }

        System.out.println("\n");

        System.out.print("Print in depth first order (Iterator):\n");
        Iterator<Node> depthFirst = tree1.depthFirst();
        while (depthFirst.hasNext()) {
            System.out.print(depthFirst.next().getData() + " ");
        }

    }
}
