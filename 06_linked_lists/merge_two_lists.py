from linkedlist import Node


def mergeTwoLists(self, list1, list2):
    p3 = Node(0)  # 0 is dummy
    curr = p3

    p1 = list1
    p2 = list2

    while p1 is not None and p2 is not None:
        if p1.val < p2.val:
            curr.next = Node(p1.val)
            p1 = p1.next
        else:
            curr.next = Node(p2.val)
            p2 = p2.next
        curr = curr.next

    if p1 == None:
        curr.next = p2
    elif p2 == None:
        curr.next = p1

    return p3.next
