import java.util.Collections;
import java.util.LinkedList;


public class Greedy {

    public static void main(String[] args) {
        LinkedList<Task> tasks = new LinkedList<>();
        tasks.add(new Task(1,2,20));
        tasks.add(new Task(2,1,200));
        tasks.add(new Task(3,3,100));
        tasks.add(new Task(4,1,50));
        tasks.add(new Task(5,1,150));

        System.out.println(greedyAlgorithm(tasks, 3));
    }
    public static LinkedList<Integer> greedyAlgorithm(LinkedList<Task> tasks, int slots){
        LinkedList<Integer> timeSlot = new LinkedList<>();
        Task highestProfitTask = new Task();

        for(int i = 0; i < slots; i++){
            for(Task x : tasks){
                if(x.getDeadline() > i && x.getProfit() > highestProfitTask.getProfit()){
                    highestProfitTask = x;
                }
            }
            tasks.remove(highestProfitTask);
            timeSlot.add(highestProfitTask.getProfit());
            highestProfitTask.setProfit(0);
        }
        return timeSlot;
    }
}
