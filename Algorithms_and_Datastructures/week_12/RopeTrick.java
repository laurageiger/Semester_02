package ex1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RopeTrick {
    public List<Integer> maxRevenue(List<Integer> priceList){
        List<Integer> listToReturn = new ArrayList<>(priceList.size());
        listToReturn.add(0);
        listToReturn.add(priceList.get(0));

        for(int n = 1; n < priceList.size(); n++){
            int max = 0;
            for(int i = 1; i <= n; i++){
                max = Integer.max(max, priceList.get(i) + listToReturn.get(n-i));
            }
            listToReturn.add(max);
        }
        listToReturn.remove(0);
        return listToReturn;
    }

    public static void main(String[] args) {
        RopeTrick ropeTrick = new RopeTrick();
        List<Integer> priceList = new ArrayList<>();
        Collections.addAll(priceList, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30);

        System.out.println("Price list:      " + priceList);
        System.out.println("Maximum revenue: " + ropeTrick.maxRevenue(priceList));
    }
}
