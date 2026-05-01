# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head):
        nextNode = None
        curr = head
        prev = None

        while curr is not None:
            # store next
            nextNode = curr.next

            # reverse the node
            curr.next = prev

            # update the pointers
            prev = curr
            curr = nextNode

        return prev
