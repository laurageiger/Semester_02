package at.ac.uibk;

import java.util.Scanner;

public class Stack {
    private int capacity;
    private int index;
    private Character[] array;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // create object
        System.out.print("Enter a word: ");
        String input = scan.nextLine(); // read input

        checkPal(input);
    }

    public static void checkPal(String input){
        Stack stack = new Stack(100);
        String reverse = "";

        for(int i = 0; i < input.length(); i++){ // push chars onto stack
            stack.push(input.charAt(i));
        }

        while(stack.index != 0){ // pop stack and put chars into string
           reverse += stack.pop();
        }

        if(reverse.equals(input)){ // check if input and reverse is equal
            System.out.println(input + " is a palindrome");
        }

        else{
            System.out.println(input + " is not a palindrome");
        }

    }

    public Stack(int capacity){ // constructor
        this.array = new Character[capacity];
        this.capacity = capacity;
        this.index = 0;
    }


    public boolean push(Character elem){ // push elem onto stack if not full
        if(this.index == this.capacity){
            return false;
        }
        this.array[this.index] = elem;
        this.index++;
        return true;
    }

    public Character pop(){ // pop element and return it if stack not empty
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