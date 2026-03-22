# Linked List

Stacks are **Last In First Out (LIFO)**.

## Reflection Questions

### Why is a linked list efficient for stack implementation?

There are several reasons a linked list is efficient for stacks.

1. The first is that it isn't required to be a fixed size. Elements can be added and removed as needed without having to resize the container.
1. The second reason is that the elements are not required to be stored sequentially in memory.
1. Another reason linked lists make excellent stacks is because the pop and push operations are always constant time complexity $O(1)$.

### What is the time complexity of push and pop operations?

Both operations for a stack that is implemented with a Linked List would be $O(1)$ time complexity. This is because the container stores a pointer to the top node of the stack and accessing the value is a simple read operation.

### What happens if memory is not deallocated after pop?

If memory is not deallocated after a value is removed from the stack it would cause a memory leak. The node would be created and stored in memory but never removed from memory causing an ever increasing number of nodes.

### Compare a stack implemented with an array versus a linked list.

There are a few reason a linked list implementation is preferred over an array.

1. The first is because linked lists are dynamically sized and do not require resizing the container.
1. The second is that in order to prevent index out of bounds the modulus operator must be used to roll over the the index and the head and tail of the current stack must be tracked.
