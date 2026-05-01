def reverseList(head):
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
