class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            return head;
        }
        if (k == 1) {
            return head;
        }
        ListNode one = head;
        int total = 0;
        while (one != null) {
            total += 1;
            one = one.next;
        }
        one = head;
        if (k == total) {
            ListNode prev = null;
            ListNode current = head;
            while (current != null) {
                ListNode next = current.next;
                current.next = prev;
                prev = current;
                current = next;
            }
            return prev;
        }
        int amount = total / k;
        int count = 0;
        ListNode point = null;
        while (count < amount) {   
            int pos = 0;
            ListNode prev = null;
            if (count == 0) {
                point = one;
                while (pos < k) {
                    ListNode next = one.next;
                    one.next = prev;
                    prev = one;
                    one = next;
                    pos++;
                }
                point.next = one;
                head = prev;
            } else {
                ListNode prevprev = point;
                prev = one;
                ListNode three = prev;
                one = one.next;
                while (pos + 1 < k) {
                    ListNode next = one.next;
                    one.next = prev;
                    prev = one;
                    one = next;
                    pos++;
                }
                prevprev.next = prev;
                three.next = one;
                point = three;
            }
            count++;
        }
        return head;
    }  
}
