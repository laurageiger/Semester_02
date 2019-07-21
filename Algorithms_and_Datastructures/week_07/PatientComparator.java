package ex1;

import java.util.*;

public class PatientComparator implements Comparator<Patient>{

    /*   return value compare:
        -1   --> prioritise first patient
         1   --> prioritise second patient
         0   --> prioritise none
     */

    @Override
    public int compare(Patient p1, Patient p2) {
        if(p1.getSeverityGrade()> p2.getSeverityGrade()){
            return -1;
        }
        else if(p1.getSeverityGrade() < p2.getSeverityGrade()){
            return 1;
        }
        else{
            if(p1.getTimeOfAdmission() < p2.getTimeOfAdmission()){
                return -1;
            }
            else if(p1.getTimeOfAdmission() > p2.getTimeOfAdmission()){
                return 1;
            }
            else{
                if(p1.isInsuredPrivately() == true){
                    return -1;
                }
                else if(p2.isInsuredPrivately() == true){
                    return 1;
                }
            }
        }
        return 0;
    }
}
