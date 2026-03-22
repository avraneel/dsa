class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


# Create first node
head = Node(10)

# Link the second node
head.next = Node(20)  # type: ignore

head.next.next = Node(30)  # type: ignore


def traverse(head: Node):
    pointer = head
    while pointer is not None:
        print(pointer.data, end=" ")
        pointer = pointer.next


traverse(head)
