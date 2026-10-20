import java.util.*;

public class GameSequences {

    public static List<Integer> countMatchingSequences(
            int N, int M, List<List<Integer>> games,
            int Q, List<List<Integer>> queries) {

        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            StringBuilder prefix = new StringBuilder();

            for (int j = 0; j < M; j++) {
                prefix.append(games.get(i).get(j)).append('$');

                String key = prefix.toString();
                map.put(key, map.getOrDefault(key, 0) + 1);
            }
        }

        List<Integer> matches = new ArrayList<>();

        for (int i = 0; i < Q; i++) {
            StringBuilder prefix = new StringBuilder();

            for (int j = 0; j < M; j++) {
                int value = queries.get(i).get(j);

                if (value == -1) {
                    break;
                }

                prefix.append(value).append('$');
            }

            if (prefix.length() == 0) {
                matches.add(N);
            } else {
                matches.add(map.getOrDefault(prefix.toString(), 0));
            }
        }

        return matches;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        List<List<Integer>> games = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            List<Integer> row = new ArrayList<>();

            for (int j = 0; j < M; j++) {
                row.add(sc.nextInt());
            }

            games.add(row);
        }

        int Q = sc.nextInt();
        List<List<Integer>> queries = new ArrayList<>();

        for (int i = 0; i < Q; i++) {
            List<Integer> row = new ArrayList<>();

            for (int j = 0; j < M; j++) {
                row.add(sc.nextInt());
            }

            queries.add(row);
        }
        List<Integer> result = countMatchingSequences(N, M, games, Q, queries);
        for (int value : result) {
            System.out.println(value);
        }
        sc.close();
    }
}