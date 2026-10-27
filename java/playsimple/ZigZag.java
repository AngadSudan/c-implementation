import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class ZigZag {
    public static List<Integer> zigzagTraversal(TreeNode root) {
        List<Integer> traversal = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int level = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> temp = new ArrayList<>();
            level++;

            for (int i = 0; i < size; i++) {
                TreeNode removed = q.poll();
                temp.add(removed.val);

                if (removed.left != null) {
                    q.offer(removed.left);
                }
                if (removed.right != null) {
                    q.offer(removed.right);
                }
            }
            if (level % 2 == 0)
                Collections.reverse(temp);

            for (int i : temp)
                traversal.add(i);
        }

        return traversal;
    }

    public static TreeNode buildTree(List<Integer> arr) {
        if (arr.isEmpty() || arr.get(0) == -1)
            return null;
        TreeNode root = new TreeNode(arr.get(0));
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int i = 1;
        while (!q.isEmpty() && i < arr.size()) {
            TreeNode curr = q.poll();
            if (i < arr.size() && arr.get(i) != -1) {
                curr.left = new TreeNode(arr.get(i));
                q.add(curr.left);
            }
            i++;
            if (i < arr.size() && arr.get(i) != -1) {
                curr.right = new TreeNode(arr.get(i));
                q.add(curr.right);
            }
            i++;
        }
        return root;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> arr = new ArrayList<>();
        while (sc.hasNextInt()) {
            arr.add(sc.nextInt());
        }
        TreeNode root = buildTree(arr);
        List<Integer> result = zigzagTraversal(root);
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i) + (i == result.size() - 1 ? "" : " "));
        }
        System.out.println();
    }
}
