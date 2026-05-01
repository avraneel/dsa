def ll_cycle_ii(head):
    slow = fast = head

    while fast != None and fast.next != None:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            # cycle detected
            slow = head  # reset slow
            while slow is not fast:
                # do one step this time
                slow = slow.next
                fast = fast.next
            return slow

    return None
