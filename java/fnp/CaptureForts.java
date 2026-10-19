import java.util.*;

public class CaptureForts {
    public int captureForts(int[] forts) {
        int n = forts.length;
        int ans = 0;
        int i = 0;

        while (i < n) {
            if (forts[i] == 0) {
                i++;
                continue;
            }
            int j = i + 1;

            while (j < n && forts[j] == 0) {
                j++;
            }

            if (j < n && forts[i] != forts[j]) {
                ans = Math.max(ans, j - i - 1);
            }

            i = j;
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt())
            return;

        int n = scanner.nextInt();
        int[] forts = new int[n];

        for (int i = 0; i < n; i++) {
            forts[i] = scanner.nextInt();
        }

        CaptureForts solver = new CaptureForts();
        System.out.println(solver.captureForts(forts));
    }
}
