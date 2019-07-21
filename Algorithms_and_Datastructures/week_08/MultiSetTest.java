package ex3;

import java.util.ArrayList;
import java.util.List;

public class MultiSetTest {

    public static void main(String[] args) {
        MultiSet multiset = new MultiSet();

        String text = "Absolventen und Absolventinnen dieses Moduls kennen und verstehen wichtige Algorithmen und Datenstrukturen, und sind in der Lage, sich weitere Algorithmen und Datenstrukturen selbstständig zu erschließen, und in eigenen Programmen zu verwenden. Weiters haben sie ein Verständnis für die Komplexität der verschiedenen Algorithmen";
        text = text.replaceAll(",", "").replaceAll("[.]", "");
        String[] split= text.split(" ");

        for(String string : split){
           List<String> list = new ArrayList<>();
           list.add(string);
           multiset.put(string.length(), list);
        }

        multiset.printMultiset();
    }
}
