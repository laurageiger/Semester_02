package ex2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class InstituteManager {

    private HashMap<String, List<String>> hashMap = new HashMap<>();

    public HashMap<String, List<String>> intersect(HashMap <String, List<String>> institute1, HashMap<String, List<String>> institute2){
        for(Map.Entry<String, List<String>> entry : institute2.entrySet()) {
            if(institute1.containsKey(entry.getKey())) {
                List<String> list = new ArrayList<>();
                list.addAll(institute1.get(entry.getKey()));
                list.addAll(institute2.get(entry.getKey()));
                this.hashMap.put(entry.getKey(), list);
            }
        }
        return this.hashMap;
    }

    public HashMap<String, List<String>> union(HashMap<String, List<String>> institute1, HashMap<String, List<String>> institute2){
        this.hashMap.putAll(institute1);

        for(Map.Entry<String, List<String>> entry : institute2.entrySet()){
            if(!this.hashMap.containsKey(entry.getKey())){
                this.hashMap.put(entry.getKey(), entry.getValue());
            }
            else{
                this.hashMap.get(entry.getKey()).addAll(entry.getValue());
            }
        }
        return hashMap;
    }


    public HashMap<String, List<String>> difference(HashMap <String, List<String>> institute1, HashMap<String, List<String>> institute2) {
        for(Map.Entry<String, List<String>> entry : institute1.entrySet()){
            if(!institute2.containsKey(entry.getKey())){
                this.hashMap.put(entry.getKey(), entry.getValue());
            }
        }
        return hashMap;
    }

    public void printHashmap(){
        for(Map.Entry<String, List<String>> entry : this.hashMap.entrySet()){
            System.out.print(entry.getKey() + " = [");
            String listCommaSeparated = String.join(", ", entry.getValue());

            System.out.print(listCommaSeparated + "]\n");
        }
    }
}
