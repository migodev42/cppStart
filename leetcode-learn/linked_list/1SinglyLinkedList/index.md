``` cpp
// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};
```

It takes us **O(N)** time on average to visit an element by index, where N is the length of the linked list.

### Add Operation - Singly Linked List 单链表添加节点

If we want to add a new value after a given node prev, we should: 

- Initialize a new node cur with the given value;
- Link the "next" field of cur to prev's next node next;
- Link the "next" field in prev to cur.

Unlike an array, we don’t need to move all elements past the inserted element. Therefore, you can insert a new node into a linked list in O(1) time complexity, which is very efficient.
