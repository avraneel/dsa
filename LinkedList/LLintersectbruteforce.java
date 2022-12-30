package LinkedList;
public class LLintersectbruteforce {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode curA = headA;
        ListNode curB = headB;
        ListNode ans = null;
        while(curA != null) {
            //System.out.println("Cur A = " + curA.val);
            while(curB != null) {
                //System.out.println("Cur B = " + curB.val);
                if(curA == curB) {
                    ans = curA;
                    return ans;
                }
                curB = curB.next;
            }
            curA = curA.next; 
            curB = headB;
        }
        return ans;
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */