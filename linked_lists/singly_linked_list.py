class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next: None


def traverse(head: Node):
    """
    Traverses the linked list, O(n) time
    """
    pointer = head
    while pointer is not None:
        print(pointer.data, end=" ")
        pointer = pointer.next
    print()


def insert_at_beginning(head: Node, data):
    """
    Inserts at beginning, O(1) time. \n
    This things works if LL is empty too!
    """
    new_node = Node(data)
    new_node.next = head
    head = new_node

    # returning head is required as head is re-binded to a new address
    return head


def insert_at_end(head: Node, data):
    """
    Inserts at end, O(n) time as we need to iterate to the end
    """
    new_node = Node(data)
    pointer = head

    if head is None:
        # if LL is empty
        head = new_node
        return head

    while pointer.next is not None:
        # Iterate till we reach the last element
        pointer = pointer.next
    # now pointer points to the last node whose next value is None
    pointer.next = new_node
    return head


def insert_at_specific_position(head: Node, data, pos):
    """
    Inserts at specific position, O(n) time needed
    """
    new_node = Node(data)
    pointer = head
    count = 1

    if pos == 1:
        # same as insert in beginning, we need to return head
        new_node.next = head
        head = new_node
        return head

    while count < pos - 1:
        """
        pos - 1 is important! if pos = 3,
        then for pos = 2, 2 < 3,
        and inside it will iterate!
        think how in normal array iterate how the
        value of count is arr.length AFTER the iteration
        we dont want that so we loop till pos - 1
        """
        pointer = pointer.next
        count += 1

    # new node's next value will point to the current node as pos
    new_node.next = pointer.next
    pointer.next = new_node

    # returning head is optional as we are just updating the last value
    return head


# Create first node
head = Node(10)

# Link the second node
head.next = Node(20)

# Link the third node
head.next.next = Node(30)

traverse(head)
head = insert_at_beginning(head, 40)
head = insert_at_end(head, 50)
traverse(head)
head = insert_at_specific_position(head, 100, 3)
traverse(head)
