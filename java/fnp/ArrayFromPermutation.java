import java.util.Scanner;

public class ArrayFromPermutation {
    public static int[] buildArray(int[] nums) {
        int n = nums.length;
        int ans[] = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt())
            return;
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int[] ans = buildArray(nums);
        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i] + (i == ans.length - 1 ? "" : " "));
        }
        System.out.println();
    }
}
