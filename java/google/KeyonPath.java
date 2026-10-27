
import java.util.*;
import java.io.*;

public class KeyonPath {

    public static class Edge {
        int from;
        int to;
        int weight;

        public Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    public static List<List<int[]>> createAdjacencyArray(
            int V, int E, List<Edge> edges) {

        List<List<int[]>> graph = new ArrayList<>();

        for (int i = 0; i <= V; i++) {
            graph.add(new ArrayList<>());
        }

        for (Edge edge : edges) {
            graph.get(edge.from).add(new int[] { edge.to, edge.weight });
        }

        return graph;
    }

    public static int minimizeMaxSecurityKey(
            int V, int E, List<Edge> edges, int u, int v) {

        if (u == v) {
            return 0;
        }

        List<List<int[]>> graph = createAdjacencyArray(V, E, edges);

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));

        int[] distance = new int[V + 1];
        Arrays.fill(distance, Integer.MAX_VALUE);

        distance[u] = 0;
        pq.offer(new int[] { u, 0 });

        while (!pq.isEmpty()) {
            int[] removed = pq.poll();
            int node = removed[0];
            int maxWeight = removed[1];

            if (maxWeight > distance[node]) {
                continue;
            }

            if (node == v) {
                return maxWeight;
            }

            for (int[] edge : graph.get(node)) {
                int next = edge[0];
                int weight = edge[1];

                int newMax = Math.max(maxWeight, weight);

                if (newMax < distance[next]) {
                    distance[next] = newMax;
                    pq.offer(new int[] { next, newMax });
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in));

        String line = reader.readLine();

        if (line == null) {
            return;
        }

        String[] parts = line.trim().split("\\s+");
        int V = Integer.parseInt(parts[0]);
        int E = Integer.parseInt(parts[1]);

        List<Edge> edges = new ArrayList<>();

        for (int i = 0; i < E; i++) {
            parts = reader.readLine().trim().split("\\s+");

            int from = Integer.parseInt(parts[0]);
            int to = Integer.parseInt(parts[1]);
            int weight = Integer.parseInt(parts[2]);

            edges.add(new Edge(from, to, weight));
        }

        parts = reader.readLine().trim().split("\\s+");
        int u = Integer.parseInt(parts[0]);
        int v = Integer.parseInt(parts[1]);

        System.out.println(minimizeMaxSecurityKey(V, E, edges, u, v));
    }
}
