package ex2;

import java.util.HashMap;
import java.util.Map;

public class EditDistance{
    private Map<MultiKey, Integer> hashMap = new HashMap<>();

    public int editDistance(String x, String y){
        int x_len = x.length();
        int y_len = y.length();

        for(int i = 0; i < x_len; i++){
            for(int j = 0; j < y_len; j++){
                MultiKey key = new MultiKey(i, j);
                if (i == 0){
                    this.hashMap.put(key, j);
                }
                else if (j == 0){
                    this.hashMap.put(key, i);
                }
                else{
                    int delta = 0;

                    // Extract last char of x and y
                    char last_x = x.charAt(i- 1);
                    char last_y = y.charAt(j - 1);

                    // delta is 0 if the last characters match, else 1
                    if (last_x != last_y) delta = 1;

                    // Case for the last characters of x and y matching,
                    // or the last char of x needs to be replaced by another
                    int diagonal = this.hashMap.get(new MultiKey(i-1, j-1)) + delta;

                    // Case for deleting the last character from x
                    int vertical = this.hashMap.get(new MultiKey(i-1, j)) + 1;

                    // Case for inserting a new character at the end of x
                    int horizontal = this.hashMap.get(new MultiKey(i, j-1)) + 1;

                    // The edit distance is the minimum of all 3 possibilities
                    int ret = Math.min(diagonal, Math.min(vertical, horizontal));

                    this.hashMap.put(key, ret);
                }
            }
        }
        return this.hashMap.get(new MultiKey(x_len-1, y_len-1));
    }

    public static void main(String[] args){
        EditDistance edit = new EditDistance();
        long start = System.currentTimeMillis();
        System.out.println(edit.editDistance("Deterministic", "Algorithmic"));
        long end = System.currentTimeMillis();
        System.out.println("Time taken="+(end - start)+"ms");
    }
}
