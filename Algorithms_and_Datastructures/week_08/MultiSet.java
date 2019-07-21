package ex3;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MultiSet extends HashMap<Integer, List<String>>{
    private HashMap<Integer, List<String>> multiSet = new HashMap<>();

    @Override
    public List<String> put(Integer key, List<String> value) {
        List<String> listToReturn = new ArrayList<>();
        if(!this.getMultiSet().containsKey(key)){
            this.getMultiSet().put(key, value);
        }
        else{
            listToReturn.addAll(this.getMultiSet().get(key)); // return old list if key already in map
            this.getMultiSet().get(key).addAll(value);
        }
        return listToReturn;
    }

    public void printMultiset(){
        for(Map.Entry<Integer, List<String>> entry : this.getMultiSet().entrySet()){
            System.out.printf("%2d = %s\n", entry.getKey(), entry.getValue());
        }
    }

    public HashMap<Integer, List<String>> getMultiSet() {
        return multiSet;
    }

}
