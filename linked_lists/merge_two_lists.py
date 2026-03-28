# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        p3 = ListNode(0)  # 0 is dummy
        curr = p3

        p1 = list1
        p2 = list2

        while p1 is not None and p2 is not None:
            if p1.val < p2.val:
                curr.next = ListNode(p1.val)
                p1 = p1.next
            else:
                curr.next = ListNode(p2.val)
                p2 = p2.next
            curr = curr.next

        if p1 == None:
            curr.next = p2
        elif p2 == None:
            curr.next = p1

        return p3.next
