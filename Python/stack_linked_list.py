# this is a implementation of a stack with a linked list using object orientation

# first we create a Node class, this class is responsible for each new node that the list will contain
class Node():
    def __init__(self, data):
        self.data = data
        self.next = None

# the class Stack it is responsible for storing the actual data (formed by Nodes)


class Stack():
    def __init__(self):
        self.top = None
        self._size = 0


# the push method it is responsible for add a new element on the list and every new element will become the top of the list (or stack)


    def push(self, elem):
        node = Node(elem)
        node.next = self.top
        self.top = node
        self._size += 1

# the pop method is used to pop the element out of the list, since we can only do push and pop from the top of the list, we will have to update the top

    def pop(self):
        result = self.isEmpty()
        if not result:
            node = self.top.data
            self.top = self.top.next
            self._size -= 1
            return node
        raise IndexError('empty stack')

# this method see if the stack is empty

    def isEmpty(self):
        if self._size == 0:
            return True
        return False

# this method returns the element present at the top of the stack

    def peek(self):
        result = self.isEmpty()
        if not result:
            return self.top.data
        raise IndexError('empty stack')

# this method returns the size of the stack

    def __len__(self):
        return self._size
