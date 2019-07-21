package submition;

import java.util.ArrayList;
import java.util.List;

public class Vertex {
    private int id;
    private List<Edge> edges = new ArrayList<>();
    private List<Vertex> adjacentVertex = new ArrayList<>();

    public Vertex(int i) {
        this.id = i;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public List<Edge> getEdges() {
        return edges;
    }

    public void setEdges(List<Edge> edges) {
        this.edges = edges;
    }

    public List<Vertex> getAdjacentVertex() {
        return adjacentVertex;
    }

    public void setAdjacentVertex(List<Vertex> adjacentVertex) {
        this.adjacentVertex = adjacentVertex;
    }

    public String toString(){
        StringBuilder toReturn = new StringBuilder();
        return toReturn.append(this.id).toString();
    }
}
