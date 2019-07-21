package submition;

import another.Edge;
import another.Graph;
import another.Vertex;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

public class CycleDetection {

    public List<Vertex> cycleDetection(Graph graph, Vertex vertex){
        List<Vertex> visited = new LinkedList<>();
        Stack<Vertex> stack = new Stack();

        stack.push(vertex);

        while(!stack.isEmpty()){
            Vertex current = stack.pop();
            List<Edge> outGoing = graph.outGoingEdges(current);

            for(Edge e : outGoing){
                if(!visited.contains(e.getTo()) && !visited.contains(e.getFrom())){
                    stack.push(e.getTo());
                }
            }

            visited.add(current);
        }


        for(int i = 0; i < visited.size(); i++){
            for(int j = i+1; j < visited.size(); j++){
                if(visited.get(i).equals(visited.get(j))){
                    System.out.println("A cycle has been detected");
                    break;
                }
            }
        }

        return visited;
    }


    public static void main(String[] args) {
        Graph graph = new Graph();

        Vertex vertex0 = graph.insertVertex(0);
        Vertex vertex1 = graph.insertVertex(1);
        Vertex vertex2 = graph.insertVertex(2);
        Vertex vertex3 = graph.insertVertex(3);
        Vertex vertex4 = graph.insertVertex(4);

        graph.insertEdge(vertex0, vertex1, 1);
        graph.insertEdge(vertex1, vertex2, 1);
        graph.insertEdge(vertex2, vertex3, 1);
        graph.insertEdge(vertex2, vertex4, 1);
        graph.insertEdge(vertex3, vertex4, 1);

        System.out.println("HashMap of Vertexes and Edges: \n" + graph);

        CycleDetection cycleDetection = new CycleDetection();
        System.out.println(cycleDetection.cycleDetection(graph, vertex0).toString());

    }
}
