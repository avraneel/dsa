// Link = https://leetcode.com/problems/intersection-of-two-linked-lists/description/

public class LLintersection {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        ListNode b = headB;
        if(headA == null || headB == null) return null;
        while(a != b) {
            if(a == null) 
                a = headB;
            else
                a = a.next;
            
            if(b == null)
                b = headA;
            else
                b = b.next;
        }

        return a; // If cycle then node will return or else 
                // if no cycle then both a and b will be null and null will be returned.


    }
}