# Maintain Linked List Tail Pointer

**PROBLEM**

_head_ and _tail_ are global pointers to the first and last element, respectively, of a singly linked list of integers. Implment C functions for the following prototypes:
```
bool delete(Element *elem);
bool insertAfter(Element *elem, int data);
```
The argument to _delete_ is the element to be deleted. The two arguments to _insertAfter_ give the element after which the new element is to be inserted and the data for the new element. It should be possible to insert at the beginning of the list by calling _insertAfter_ with _NULL_ as the element argument. These functions should return a boolean indicating success.

Your functions must keep the head and tail pointers current.