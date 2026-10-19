import java.util.Arrays;
import java.util.Scanner;

public class RodCutting {
    public static int maxRodValue(int n, int[] prices) {
        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; i++)
            dp[i] = prices[i - 1];

        for (int i = 1; i <= n; i++) {
            for (int j = i; j > 0; j--) {
                dp[i] = Math.max(dp[i],
                        (dp[i - j] + dp[j]));
            }
        }

        return dp[n];
    }

    public static int cutRod(int n, int[] prices, int[] dp) {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int price = prices[n - 1];
        for (int i = n - 1; i > 0; i--) {
            price = Math.max(price,
                    (cutRod(n - i, prices, dp) +
                            cutRod(i, prices, dp)));
        }

        return dp[n] = price;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] prices = new int[n];
            for (int i = 0; i < n; i++) {
                prices[i] = scanner.nextInt();
            }
            System.out.println(maxRodValue(n, prices));
        }
        scanner.close();
    }
}
