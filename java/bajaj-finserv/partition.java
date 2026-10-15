import java.io.*;

public class partition {
    public static long minPartitionScore(String s) {
        int n = s.length();
        long ans = 0;
        int lastIndx[] = new int[26];

        for (int i = 0; i < n; i++) {
            lastIndx[s.charAt(i) - 'a'] = i;
        }

        int i = 0;
        while (i < n) {
            int last = lastIndx[s.charAt(i) - 'a'];
            int j = i + 1;
            while (j <= last) {
                last = Math.max(last, lastIndx[s.charAt(j) - 'a']);
                j++;
            }

            int len = j - i;
            ans += len * len;
            i = j;
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String s = reader.readLine();
        if (s != null) {
            s = s.trim();
            if (!s.isEmpty()) {
                System.out.println(minPartitionScore(s));
            }
        }
    }
}
