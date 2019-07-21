package submition;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Graph {
    private Map<Vertex, List<Edge>> hashMap;

    public Graph(){
        this.hashMap = new HashMap<>();
    }

    public Vertex insertVertex(int x){
        Vertex toInsert = new Vertex(x);
        if(!this.hashMap.containsKey(toInsert)){
            hashMap.put(toInsert, new ArrayList<>());
            return toInsert;
        }
        else{
            System.out.println("Vertex has already been added");
            return null;
        }
    }

    public Edge insertEdge(Vertex from, Vertex to, int storing){
        Edge toInsert = new Edge(from, to, storing);
        if(!this.hashMap.containsKey(from)){
            this.hashMap.put(from, new ArrayList<>());
        }
        else if(!this.hashMap.containsKey(to)){
            this.hashMap.put(to, new ArrayList<>());
        }
        else if(this.hashMap.get(to).contains(toInsert)){
            System.out.println("Edge has already been added");
            return null;
        }
        else{
            this.hashMap.get(to).add(toInsert);
            this.hashMap.get(from).add(toInsert);
        }
        return toInsert;
    }

    public String toString() {
        StringBuilder toReturn = new StringBuilder();
        for (Map.Entry<Vertex, List<Edge>> entry : this.hashMap.entrySet()) {
            toReturn.append(entry.toString() + "\n");
        }
        return toReturn.toString();
    }

    public Vertex opposite(Vertex from, Edge edge){
        if(edge.getTo().equals(from)){
            return edge.getFrom();
        }
        else{
            return edge.getTo();
        }
    }

    public Vertex[] endVertices(Edge edge){
        Vertex[] toReturn = new Vertex[2];
        toReturn[0] = edge.getTo();
        toReturn[1] = edge.getFrom();
        return toReturn;
    }

    public List<Edge> outGoingEdges(Vertex vertex){
        List<Edge> forIterator = new ArrayList<>();
        for(Map.Entry<Vertex, List<Edge>> entry : this.hashMap.entrySet()){
            if(entry.getKey().equals(vertex)){
                forIterator.addAll(entry.getValue());
            }
        }
        return forIterator;
    }

    public Map<Vertex, List<Edge>> getHashMap() {
        return hashMap;
    }
}
