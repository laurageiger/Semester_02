package at.ac.uibk;

public class Occurrences {

    public static void main(String[] args) {
	    int[] list = new int[] {0,1,1,3,5,6,1};

	    System.out.println("Count occurrences(iterative): " + countOccurrencesIter(list, 1));
	    System.out.println("Count occurrences(recursive): " + countOccurrencesRec(list, 1, 0));
    }

    public static int countOccurrencesIter(int[] list, int n){ // iterative function
        int count = 0;
        for(int i = 0; i < list.length; i++){
            if(list[i] == n){
                count++;
            }
        }
        return count;
    }

    public static int countOccurrencesRec(final int[] list, int n, int i){ // recursive function
        if(i == list.length){
            return 0;
        }
        else if(list[i] == n)
            return 1 + countOccurrencesRec(list, n, i+1);
        else
            return countOccurrencesRec(list, n,i+1);
    }


}
