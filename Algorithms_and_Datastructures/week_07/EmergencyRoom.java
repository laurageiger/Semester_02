package ex1;

import java.util.*;

public class EmergencyRoom {
    public static void main(String[] args) {
        PriorityQueue<Patient> priorityQueue = new PriorityQueue<>(200, new PatientComparator());

        Patient patient1 = new Patient("John Alpha", "SERIOUS", 0, true);
        Patient patient2 = new Patient("Mark Bravo", "SERIOUS", 1, false);
        Patient patient3 = new Patient("Steven Charlie", "SEVERE", 1, true);
        Patient patient4 = new Patient("Christian Delta", "MODERATE", 2, true);
        Patient patient5 = new Patient("Matthew Echo", "MODERATE", 2, false);
        Patient patient6 = new Patient("Sebastian Foxtrott", "SEVERE", 4, false);
        Patient patient7 = new Patient("Anna Golf", "SEVERE", 4, true);
        Patient patient8 = new Patient("Maria Hotel", "SERIOUS", 5, false);


        priorityQueue.add(patient1);
        priorityQueue.add(patient2);
        priorityQueue.add(patient3);
        priorityQueue.add(patient4);

        System.out.println("Priority Queue after adding patient1 - patient4:");
        for(Patient patient : priorityQueue){
            System.out.println(patient.getName());
        }
        System.out.println("\n");

        priorityQueue.remove();

        System.out.println("Priority Queue after removing next patient:");
        for(Patient patient : priorityQueue){
            System.out.println(patient.getName());
        }
        System.out.println("\n");

        priorityQueue.add(patient5);

        System.out.println("Priority Queue after adding patient5:");
        for(Patient patient : priorityQueue){
            System.out.println(patient.getName());
        }
        System.out.println("\n");

        priorityQueue.remove();
        priorityQueue.remove();

        System.out.println("Priority Queue after removing next two patients:");
        for(Patient patient : priorityQueue){
            System.out.println(patient.getName());
        }
        System.out.println("\n");

        priorityQueue.add(patient6);
        priorityQueue.add(patient7);
        priorityQueue.add(patient8);

        System.out.println("Priority Queue after adding patient6 - patient8:");
        for(Patient patient : priorityQueue){
            System.out.println(patient.getName());
        }
        System.out.println("\n");

        priorityQueue.remove();
        priorityQueue.remove();
        priorityQueue.remove();
        priorityQueue.remove();
        priorityQueue.remove();

        System.out.println("Priority Queue after removing all patients:");
        for(Patient patient : priorityQueue){
            System.out.println(patient.getName());
        }

    }
}
