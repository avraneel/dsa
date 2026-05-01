class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


class LinkedList:
    """
    Linked List helper class to create LL from array or head,
    and print it
    """

    def __init__(self, items=[], head=None):
        """
        If initialized with a pre-defined `head`, will use `head`
        If not, then will use `items` array
        If both are empty then `items` array is taken as `[]` by default
        creating an empty list
        """
        self.items = items
        self.head = head if head else self.create()

    def create(self):
        if len(self.items) == 0:
            return

        head_node = Node(self.items[0])
        curr = head_node

        for i in range(1, len(self.items)):
            item_node = Node(self.items[i])
            curr.next = item_node
            curr = curr.next

        return head_node

    def print(self):
        """
        Prints the LL in `[1->2->3->4->5]` format
        """
        curr = self.head
        print("[", end="")
        while curr:
            if curr.next:
                print(f"{curr.val}", end="->")
            else:
                print(f"{curr.val}", end="")
            curr = curr.next
        print("]")
