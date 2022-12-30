package LinkedList;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

// Striver Solution: 

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;

        // Initialize l1 to smaller element
        if(l1.val > l2.val) {
            ListNode t = l1;
            l1 = l2;
            l2 = t;
        }

        ListNode res = l1;

        while(l1 != null && l2 != null) {
            ListNode tmp = null;

            while(l1 != null && l1.val <= l2.val) {
                tmp = l1;
                l1 = l1.next;
            }

            // Important step:
            // Let, tmp is pointing to a node addressed 0x25, so tmp.next will 
            // update 0x25's next link to the one from another list. (**NOT tmp's link**, but the link of the node to
            // which tmp is pointing)
            // TMP ONLY **REFERS** TO THE NODE, CHANGING TMPS LINK WILL CHANGE THE LINK TO 
            // THE NODE ITSELF AND NOT TEMP. TMP IS MERELY A PLACEHOLDER FOR THE NODE
            // Draw diagram with arrow if not clear.
            tmp.next = l2;

            ListNode t = l1;
            l1 = l2;
            l2 = t;
        }

        return res;
    }
}
