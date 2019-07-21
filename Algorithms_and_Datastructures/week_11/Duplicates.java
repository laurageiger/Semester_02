
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Duplicates {
    public static List<Integer> removeDuplicates(List<Integer> list){
        if (list.size() == 1){
            return list;
        }
        int mid = list.size()/2;
        List<Integer> left = removeDuplicates(list.subList(0, mid));
        List<Integer> right = removeDuplicates(list.subList(mid, list.size()));

        return mergeLists(left, right);
    }

    private static List<Integer> mergeLists(List<Integer> leftList, List<Integer> rightList){
        int left = 0, right = 0;
        List<Integer> listToReturn = new LinkedList<>();

        while(left < leftList.size() && right < rightList.size()){
            if(leftList.get(left) < rightList.get(right)){
                listToReturn.add(leftList.get(left++));
            }
            else if(leftList.get(left) > rightList.get(right)){
                listToReturn.add(rightList.get(right++));
            }
            else{ // if numbers are equal don't copy and just increment index
                right++;
            }
        }
        // copy remaining elements
        listToReturn.addAll(leftList.subList(left, leftList.size()));
        listToReturn.addAll(rightList.subList(right, rightList.size()));
        return listToReturn;
    }

    public static void main(String[] args){
        List<Integer> list1 = new LinkedList<>();
        Collections.addAll(list1, 2, 3, 2, 5, 2, 6, 6, 4, 3, 1, 2, 2);

        System.out.println("Before removing duplicates: " + list1);
        System.out.println("After removing duplicates:  " + removeDuplicates(list1));

    }
}
