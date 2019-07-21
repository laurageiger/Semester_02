package ex2;

import java.util.*;

public class InstituteManagerTest {

    public static void main(String[] args) {
        InstituteManager testIntersection = new InstituteManager();
        InstituteManager testUnion = new InstituteManager();
        InstituteManager testDifference = new InstituteManager();
        InstituteManager testDifference2 = new InstituteManager();

        HashMap<String, List<String>> institute1 = new HashMap<>();
        HashMap<String, List<String>> institute2 = new HashMap<>();
        HashMap<String, List<String>> institute3 = new HashMap<>();

        String[] financeEssentials = {"Dierdre Palomares", "Alvaro Leon", "Gustavo Osborn", "Laurinda Wahlstrom", "Murray Mccall"};
        String[] riskManagementEssentials = {"Alishia Dunmore", "Vannesa Poythress", "Dario Stillings", "Glady Juarbe"};
        String[] trainingInEnterprise = {"Tenisha Tinsley", "Jenette Palacios", "Ervin Hamil", "Germaine Wohl", "Esther Strohm", "Leona Tippie"};

        institute1.put("Finance Essentials", new ArrayList<>(Arrays.asList(financeEssentials)));
        institute1.put("Risk Management Essentials", new ArrayList<>(Arrays.asList(riskManagementEssentials)));
        institute1.put("Training in Enterprise Resource Planning in 10 Days", new ArrayList<>(Arrays.asList(trainingInEnterprise)));

        String[] molekulareAnalyse = {"Glady Juarbe", "Gustavo Osborn", "Laurinda Wahlstrom"};
        String[] metabarcodierung = {"Alishia Dunmore", "Alvaro Leon", "Glady Juarbe"};

        institute2.put("Molekulare Analyse von trophischen Interaktionen", new ArrayList<>(Arrays.asList(molekulareAnalyse)));
        institute2.put("Metabarcodierung von trophischen Interaktionen", new ArrayList<>(Arrays.asList(metabarcodierung)));

        String[] communityInterpreting = {"Laurinda Wahlstrom", "Murray Mccall", "Dierdre Palomares", "Alvaro Leon", "Gustavo Osborn"};
        String[] bibliothekspraxis = {"Dario Stillings", "Glady Juarbe", "Alishia Dunmore", "Vannesa Poythress"};

        institute3.put("Community Interpreting", new ArrayList<>(Arrays.asList(communityInterpreting)));
        institute3.put("Regionale Einführung in die Bibliothekspraxis", new ArrayList<>(Arrays.asList(bibliothekspraxis)));

        institute1 = changeKeyAndValue(institute1);
        institute2 = changeKeyAndValue(institute2);
        institute3 = changeKeyAndValue(institute3);

        System.out.println("\nUNION (A ∪ B ∪ C)");
        testUnion.union(testUnion.union(institute1, institute2), institute3);
        testUnion.printHashmap();

        System.out.println("\nINTERSECTION (A ∩ B ∩ C)");
        testIntersection.intersect(testIntersection.intersect(institute1, institute2), institute3);
        testIntersection.printHashmap();


        System.out.println("\nDIFFERENCE (A \\ (B ∪ C))");
        testDifference.difference(institute1,testDifference2.union(institute2,institute3));
        testDifference.printHashmap();

    }


    public static HashMap<String, List<String>> changeKeyAndValue(HashMap<String, List<String>> hashMap){
        HashMap<String, List<String>> mapToReturn = new HashMap<>();
        for(Map.Entry<String, List<String>> entry : hashMap.entrySet()) {
            for(String studentInstitute1 : entry.getValue()){
                if(!mapToReturn.containsKey(studentInstitute1)){
                    mapToReturn.put(studentInstitute1, new ArrayList<>());
                }
                mapToReturn.get(studentInstitute1).add(entry.getKey());
            }
        }
        return mapToReturn;
    }

}
