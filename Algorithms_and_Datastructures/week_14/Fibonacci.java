public class Fibonacci {
    static int calcFibonacci(int input){
        // variables for storing recent calculations
        int a = 0;
        int b = 1;

        if(input == 0){
            return 0;
        }
        for(int i = 2; i <= input; i++){
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    public static void main(String[] args) {
        System.out.println(calcFibonacci(6));
    }
}
