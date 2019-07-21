package at.ac.uibk;

import java.util.Scanner;

public class Hectares {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in); // create object
        System.out.print("Enter years: ");
        int input = scan.nextInt(); // read input

        System.out.println("The farmer owns " + calcHect(input) + " hectares of forest after " + input + " years.");
    }

    public static double calcHect(int years){
        return calcHectTR(years, 60000);

    }

    public static double calcHectTR(int year, double hectares){ // tail recursive function
        if (year == 0){
            hectares = Math.round(hectares * 100.0) / 100.0; // round to two decimals
            return hectares;
        }
        return calcHectTR(year-1, (hectares*1.05)-3500);
    }
}
