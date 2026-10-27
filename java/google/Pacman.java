import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Pacman {
    static int[] dr = { -1, 1, 0, 0 };
    static int[] dc = { 0, 0, -1, 1 };

    public static boolean canPacmanEscape(int R, int C, String[] grid) {
        boolean[][] unsafe = new boolean[R][C];
        int startR = -1, startC = -1;
        int endR = -1, endC = -1;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                char ch = grid[i].charAt(j);

                if (ch == 'P') {
                    startR = i;
                    startC = j;
                } else if (ch == 'E') {
                    endR = i;
                    endC = j;
                }

                if (ch == 'R' || ch == 'B' || ch == 'G' || ch == 'Y') {
                    unsafe[i][j] = true;

                    for (int d = 0; d < 4; d++) {
                        int nr = i + dr[d];
                        int nc = j + dc[d];

                        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                            unsafe[nr][nc] = true;
                        }
                    }
                }
            }
        }

        if (startR == -1 || endR == -1) {
            return false;
        }

        if (unsafe[startR][startC] || unsafe[endR][endC]) {
            return false;
        }

        boolean[][] visited = new boolean[R][C];
        Queue<int[]> queue = new LinkedList<>();

        queue.offer(new int[] { startR, startC });
        visited[startR][startC] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int r = current[0];
            int c = current[1];

            if (r == endR && c == endC) {
                return true;
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < R &&
                        nc >= 0 && nc < C &&
                        !visited[nr][nc] &&
                        !unsafe[nr][nc] &&
                        grid[nr].charAt(nc) != '#') {

                    visited[nr][nc] = true;
                    queue.offer(new int[] { nr, nc });
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        if (sc.hasNextInt()) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            String[] grid = new String[R];

            for (int i = 0; i < R; i++) {
                grid[i] = sc.next();
            }

            System.out.println(canPacmanEscape(R, C, grid) ? "YES" : "NO");
        }

        sc.close();
    }
}