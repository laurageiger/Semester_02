package ex3;

import java.util.LinkedList;
import java.util.Queue;

public class StackUsingQueues {
    private Queue<Integer> queue1 = new LinkedList<>();
    private Queue<Integer> queue2 = new LinkedList<>();

    public void push(Integer integer){
        if(queue1.isEmpty()){
            queue1.add(integer);
            while(!queue2.isEmpty()){
                queue1.add(queue2.poll());
            }
        }
        else if(queue2.isEmpty()){
            queue2.add(integer);
            while(!queue1.isEmpty()){
                queue2.add(queue1.poll());
            }
        }
    }

    public Integer pop(){
        if(!queue1.isEmpty()){
            return queue1.poll();
        }
        else if(!queue2.isEmpty()){
            return queue1.poll();
        }
        else{
            System.out.println("StackUsingQueues is empty");
        }
        return null;
    }

    public Integer size(){
        return queue1.size()+queue2.size();
    }

    public boolean isEmpty(){
        if(queue1.isEmpty() && queue2.isEmpty()){
            return true;
        }
        return false;
    }

    public Integer top(){
        if(!queue1.isEmpty()){
            return queue1.peek();
        }
        else if(!queue2.isEmpty()){
            return queue2.peek();
        }
        return null;
    }

    public String toString(){
        if(!queue1.isEmpty()){
            return queue1.toString();
        }
        else if(!queue2.isEmpty()){
            return queue2.toString();
        }
        return "[]";
    }

    public static void main(String[] args) {
        StackUsingQueues stack = new StackUsingQueues();

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        System.out.println("Print stack after adding 1, 2, 3, 4, 5");
        System.out.println(stack);
        System.out.println("\nTop element of stack");
        System.out.println(stack.top());

        System.out.println("\nPop until stack is empty");
        while(!stack.isEmpty()){
            System.out.print(stack.pop() + " ");
        }

        System.out.println("\n\nStack after removing all elements");
        System.out.println(stack);
    }
}
