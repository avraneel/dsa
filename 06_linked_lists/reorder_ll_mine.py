def reorder_ll(head):
    slow = fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    # now slow is at middle of list

    # reverse 2nd half
    nextNode = None
    curr = slow
    prev = None

    while curr:
        nextNode = curr.next
        curr = prev

        prev = curr
        curr = nextNode

    # now merge them both
    p1 = head
    p2 = prev

    while p1.next is not slow and p2:
        t1 = p1.next
        t2 = p2.next
        p1.next = p2
        p2.next = t1
        p1 = t1
        p2 = t2

    p1.next = p2
