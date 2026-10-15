import java.io.*;

public class Main {
    public static int maximizeMinimum(int R, int C, int[][] matrix) {
        int ans = 0;
        for (int i = 1; i <= R; i++) {
            for (int j = i + 1; j <= R; j += i) {
                ans = Math.max(ans, maxMin(matrix, i - 1, j - 1));
            }
        }

        return ans;
    }

    public static int maxMin(int[][] matrix, int i, int j) {
        int min = Integer.MAX_VALUE;
        for (int col = 0; col < matrix[0].length; col++) {
            min = Math.min(min,
                    Math.max(matrix[i][col], matrix[j][col]));
        }

        return min;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null)
            return;
        String[] parts = line.trim().split("\\s+");
        int R = Integer.parseInt(parts[0]);
        int C = Integer.parseInt(parts[1]);
        int[][] matrix = new int[R][C];
        for (int i = 0; i < R; i++) {
            line = br.readLine();
            if (line == null)
                break;
            parts = line.trim().split("\\s+");
            for (int j = 0; j < C; j++) {
                matrix[i][j] = Integer.parseInt(parts[j]);
            }
        }
        System.out.println(maximizeMinimum(R, C, matrix));
    }
}