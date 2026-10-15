import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class concatenateUniqueString {
    public static int maxLength(List<String> arr) {
        int[] freq = new int[26];
        return helperFn(arr, 0, freq);
    }

    public static int helperFn(List<String> arr, int index, int[] freq) {
        if (arr.size() == index)
            return 0;

        int notPick = helperFn(arr, index + 1, freq);
        int pick = 0;

        if (isUnique(arr.get(index)) && areUnique(arr.get(index), freq)) {
            for (char i : arr.get(index).toCharArray()) {
                freq[i - 'a']++;
            }

            pick = arr.get(index).length() + helperFn(arr, index + 1, freq);

            for (char i : arr.get(index).toCharArray()) {
                freq[i - 'a']--;
            }
        }

        return Math.max(pick, notPick);
    }

    public static boolean areUnique(String a, int[] freq) {
        for (char i : a.toCharArray()) {
            if (freq[i - 'a'] > 0) {
                return false;
            }
        }

        return true;
    }

    public static boolean isUnique(String word) {
        int[] freq = new int[26];
        for (char i : word.toCharArray()) {
            if (freq[i - 'a'] == 0) {
                freq[i - 'a']++;
            } else {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        if (line == null || line.trim().isEmpty())
            return;
        int n = Integer.parseInt(line.trim());
        List<String> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = reader.readLine();
            if (s != null) {
                arr.add(s.trim());
            }
        }
        System.out.println(maxLength(arr));
    }
}
