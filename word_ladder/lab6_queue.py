import stacks

class Queue:
    def __init__(self):
        self.stackA = stacks.LinkedStack()
        self.stackB = stacks.LinkedStack()
        
    def is_empty(self):
        """Tests if the queue is logically empty"""
        return self.stackA.is_empty() and self.stackB.is_Empty()
        
    def enqueue(self, item):
        """Puts item into the back of the queue"""
        self.stackA.push(item)
        
    def first(self):
        """Returns the element at the front of the queue, if it exists.
        
        Raises an IndexError if the queue is empty.
        """
        if self.stackB.is_empty():
            while not self.stackA.is_empty():
                self.stackB.push(self.stackA.pop())
        return self.stackB.top()
        

    def dequeue(self):
        """Returns and removes the element at the front of the queue, if it exists.
        
        Raises an IndexError if the queue is empty.
        """
        if self.stackB.is_empty():
            while not self.stackA.is_empty():
                self.stackB.push(self.stackA.pop())
        return self.stackB.pop()
        
    def __len__(self):
        """Returns the size of the queue."""
        return len(self.stackA) + len(self.stackB)
