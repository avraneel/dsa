from linkedlist import LinkedList


def reorderList(head):
    """
    Do not return anything, modify head in-place instead.
    """
    slow = fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    # reverse 2nd half
    curr = slow.next
    # slow.next = None
    # if we dont give this for [1,2,3,4] then
    # slow -> 2 and slow.next -> 3 so, 2 -> 3
    # even after reversing, [123] and [43]
    # and not [12] and [43], so, sever the connection
    prev = None

    while curr:
        nextNode = curr.next
        curr.next = prev
        prev = curr
        curr = nextNode

    # now merge them both
    p1 = head
    p2 = prev

    while p2:
        print(p1.val)
        print(p2.val)
        t1 = p1.next
        t2 = p2.next
        p1.next = p2
        p2.next = t1
        p1 = t1
        p2 = t2


ll = LinkedList([1, 2, 3, 4])

reorderList(ll.head)
