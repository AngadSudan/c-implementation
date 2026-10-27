import java.util.Scanner;

class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
        this.next = null;
    }
}

public class ReverseKGroups {
    public static Node reverseKGroup(Node head, int k) {
        Node ans = new Node(-1);
        Node ansHelper = ans;
        Node dummy = head;

        while (dummy != null) {
            Node kthNode = getNextNode(dummy, k);
            if (kthNode == null) {
                ansHelper.next = dummy;
                break;
            }

            Node nextNode = null;
            nextNode = kthNode.next;
            kthNode.next = null;

            Node newHead = reverse(dummy);

            ansHelper.next = newHead;
            while (ansHelper.next != null)
                ansHelper = ansHelper.next;

            dummy = nextNode;
        }
        return ans.next;
    }

    public static Node reverse(Node head) {
        Node prev = null;
        while (head != null) {
            Node next = head.next;

            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    public static Node getNextNode(Node head, int k) {
        while (head != null && k > 1) {
            head = head.next;
            k--;
        }

        return head;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt())
            return;
        int n = sc.nextInt();
        int k = sc.nextInt();
        Node dummy = new Node(0);
        Node curr = dummy;
        for (int i = 0; i < n; i++) {
            if (sc.hasNextInt()) {
                curr.next = new Node(sc.nextInt());
                curr = curr.next;
            }
        }
        Node head = dummy.next;
        head = reverseKGroup(head, k);
        curr = head;
        while (curr != null) {
            System.out.print(curr.val);
            if (curr.next != null) {
                System.out.print(" ");
            }
            curr = curr.next;
        }
        System.out.println();
    }
}
