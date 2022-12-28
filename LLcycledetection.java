
// Detect if cycle is present in LL

// Link: https://leetcode.com/problems/linked-list-cycle/description/

 class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
    val = x;
    next = null;
    }
 }
 
public class LLcycledetection {
    // This is Floyd's Hair and Tortoise algorithm, used for cycle detection in LL using 
    // Fast and Slow pointers
    public boolean hasCycle(ListNode head) {
        ListNode fast = head, slow = head;
        
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast) {  
                // IMP!! Comparing references to the same node, NOT the int val!!!
                return true;
            }
        }

        return false;
    }
}
