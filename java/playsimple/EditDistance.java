import java.util.Scanner;

class EditDistance {

    public static String findClosestWord(int n, String[] words, String s) {
        String bestWord = words[0];
        int minDistance = editDistance(bestWord, s);

        for (int i = 1; i < n; i++) {
            int currDistance = editDistance(words[i], s);

            if (currDistance < minDistance ||
                    (currDistance == minDistance &&
                            words[i].compareTo(bestWord) < 0)) {

                minDistance = currDistance;
                bestWord = words[i];
            }
        }

        return bestWord;
    }

    public static int editDistance(String a, String b) {
        int m = a.length();
        int n = b.length();

        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insert = dp[i][j - 1] + 1;
                    int delete = dp[i - 1][j] + 1;
                    int replace = dp[i - 1][j - 1] + 1;

                    dp[i][j] = Math.min(
                            insert,
                            Math.min(delete, replace));
                }
            }
        }

        return dp[m][n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) {
            sc.close();
            return;
        }
        int n = sc.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = sc.next();
        }
        String s = sc.next();
        System.out.println(findClosestWord(n, words, s));
    }
}