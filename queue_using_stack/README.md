We are given a stack data structure with push and pop operations, the task is to implement a queue using instances of stack data structure and operations on them.

**Method 1 (By making enQueue operation costly)** This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation just pops from stack1. To put the element at top of stack1, stack2 is used.

<img src="https://raw.githubusercontent.com/catlevo/Images/master/232_queue_using_stacksBPush%5B1%5D.png?token=AupMvdZ2iUHc3GVLBVgrIdf9sJYjPweIks5cqOJhwA%3D%3D" width="1200" height="500">

**Method 2 (By making deQueue operation costly)** In this method, in en-queue operation, the new element is entered at the top of stack1. In de-queue operation, if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned.
