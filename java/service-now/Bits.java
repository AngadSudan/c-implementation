import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Bits {
    public static long countExcellentPairs(int[] nums, int k) {
        int pair = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int i : nums)
            set.add(i);

        List<Integer> newArr = new ArrayList<>();
        for (int i : set)
            newArr.add(i);

        for (int i = 0; i < newArr.size(); i++) {
            for (int j = 0; j < newArr.size(); j++) {
                if (countBits(newArr.get(i)) + countBits(newArr.get(j)) >= k) {
                    pair++;
                }
            }
        }

        return pair;
    }

    public static int countBits(int n) {
        int count = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null)
            return;
        int n = Integer.parseInt(line.trim());
        int[] nums = new int[n];
        String[] parts = br.readLine().trim().split("\\s+");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(parts[i]);
        }
        int k = Integer.parseInt(br.readLine().trim());
        System.out.println(countExcellentPairs(nums, k));
    }
}