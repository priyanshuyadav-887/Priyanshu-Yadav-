class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int n = 0;
        ListNode curr = head;

        // count length
        while (curr != null) {
            n++;
            curr = curr.next;
        }

        int size = n / k;
        int extra = n % k;

        ListNode[] res = new ListNode[k];
        curr = head;

        for (int i = 0; i < k; i++) {
            if (curr == null) {
                res[i] = null;
                continue;
            }

            res[i] = curr;
            int partSize = size + (i < extra ? 1 : 0);

            for (int j = 1; j < partSize; j++) {
                curr = curr.next;
            }

            ListNode next = curr.next;
            curr.next = null;
            curr = next;
        }

        return res;
    }
}