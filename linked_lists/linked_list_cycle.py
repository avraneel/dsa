# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Read more here https://cp-algorithms.com/others/tortoise_and_hare.html


class Solution:
    def hasCycle(self, head) -> bool:
        s = head
        f = head
        while s and f and f.next:
            s = s.next
            f = f.next.next
            if s == f:
                return True
        return False
