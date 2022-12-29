// Link = https://leetcode.com/problems/intersection-of-two-linked-lists/description/

// See diagram in question,
// (n1 nodes)
//          \
//           (c common nodes)   
//          /
// (n2 nodes)

public class LLintersection {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        ListNode b = headB;
        if(headA == null || headB == null) return null;

       // First iteration a will come back to b's head after traversing to entire a's list and b will come to a's head similarly
       // they will meet in 2nd iteration as a will cover (n1 + c) + n2 and b will cover (n2 + c) + n1 nodes, which are equal. 
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