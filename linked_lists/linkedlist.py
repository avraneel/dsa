class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


class LinkedList:
    def __init__(self, items):
        self.items = items
        self.head = self.create()

    def create(self):
        head_node = Node(self.items[0])
        curr = head_node

        for i in range(1, len(self.items)):
            item_node = Node(self.items[i])
            curr.next = item_node
            curr = curr.next

        return head_node

    def print(self):
        curr = self.head

        while curr:
            if curr.next:
                print(f"{curr.val}", end="->")
            else:
                print(f"{curr.val}")
            curr = curr.next
