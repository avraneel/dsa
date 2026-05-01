from linkedlist import LinkedList


def remove_nth_from_end(head, n):
    # Step 1: Calculate length
    l = 0
    curr = head

    while curr:
        l += 1
        curr = curr.next

    if l == 1:
        return None
    # Step 2: Nth from beginning = Length - nth from end + 1
    n_begin = l - n + 1

    # if first node to be removed
    if n_begin == 1:
        return head.next

    # Step 3: Delete the n_begin node from beginning
    curr = head
    i = 1
    prev = None

    while i < n_begin:
        prev = curr
        curr = curr.next
        i += 1

    item = prev.next.next
    prev.next = item

    curr = head
    return head


ll = LinkedList([1, 2, 3, 4, 5])
new_head = remove_nth_from_end(ll.head, 3)
new_ll = LinkedList(items=[], head=new_head)
new_ll.print()
