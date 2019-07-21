import java.util.Scanner;

public class bracketMatching {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter brackets: ");
        String input = scan.nextLine();

        if(bracketMatchingRec(input, 0).equals("")){
            System.out.println(input + " - brackets are matching");
        }
        else{
            System.out.println(input + " - brackets are not matching");
        }
        System.out.println("\n");


        String test[] = {"({[]()})", "([ ])", "(][)", "(({(})))", "(()", "([)]", "(", ")"};
        for(int i = 0; i < test.length; i++){
            if(bracketMatchingRec(test[i], 0).equals("")){
                System.out.println(test[i] + " - brackets are matching");
            }
            else{
                System.out.println(test[i] + " - brackets are not matching");
            }
        }
    }

    public static String bracketMatchingRec(String input, int index) {
        /**
           removes all spaces
         */
        input = input.replaceAll(" ", "");

        /**
           returns string if brackets are uneven
           or if index is equal to the length of the string
        */
        if(input.length()%2 != 0 || index == input.length()){
            return input;
        }

        if ((input.charAt(index) == '(') || (input.charAt(index) == '{') || (input.charAt(index) == '[')) {
            return bracketMatchingRec(input, index + 1);
        }

        else{
            /**
                gets the opposite bracket
                checks if bracket at index-1 equals and removes brackets
             */
            if(input.charAt(index-1) != getOpposite(input.charAt(index))){
                return input;
            }

            input = removeCharAt(input, index-1);
            input = removeCharAt(input, index-1);
        }
        return bracketMatchingRec(input, index-1);
    }

    /**
        function for removing char at a given position
        returning new string without char
     */
    public static String removeCharAt(String s, int pos) {
        return s.substring(0, pos) + s.substring(pos + 1);
    }

    /**
        function for getting the opposite bracket
        returning opposite
     */
    public static char getOpposite(char bracket){
        switch(bracket) {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                 return '{';
        }
        return bracket;
    }
}
