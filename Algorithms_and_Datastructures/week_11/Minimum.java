import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Minimum {
    public static int min(List<Integer> list){
        return findMin(list, 0, list.size()-1);
    }

    public static int findMin(List<Integer> list, int left, int right){
        int mid = (right - left) / 2 + left;

        if(left == right){
            return list.get(left);
        }

        if(list.get(mid) < list.get(right)){
            return findMin(list, left, mid);
        }
        return findMin(list, mid+1, right);
    }

    public static void main(String[] args) {
        List<Integer> list = new LinkedList<>();
        Collections.addAll(list, 1, 5, 6, 19, 56, 101);

        List<Integer> listRotated = new LinkedList<>();
        Collections.addAll(listRotated, 19, 56, 101, 1, 5, 6);

        System.out.println("Sorted list: " + list);
        System.out.println("Minimum element: " + min(list));

        System.out.println("Sorted list: " + listRotated);
        System.out.println("Minimum element: " + min(listRotated));
    }


}
