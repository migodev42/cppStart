[Introduction - Doubly Linked List](https://leetcode.com/explore/learn/card/linked-list/210/doubly-linked-list/1291/)

We have introduced the singly linked list in previous chapters.
上一章节节介绍了单链表
>A node in a singly linked list has the value field, and a "next" reference field to link nodes sequentially.

In this article, we will introduce another type of linked list: `Doubly Linked List`.
这一章我们介绍双链表


The doubly linked list works in a similar way but has `one more reference field` which is known as `the "prev" field`. With this extra field, you are able to know the previous node of the current node.
```js
     next      next
node -> node1  -> node2
     <-        <-
     prev      prev
```


双链表数据结构：
``` cpp
// Definition for doubly-linked list.
struct DoublyListNode {
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};
```


Similar to a singly linked list, we will introduce how to access data, insert a new node or delete an existing node in a doubly linked list.

We can access data in the same exact way as in a singly linked list:

1.We are not able to access a random position in constant time.
2.We have to traverse from the head to get the i-th node we want.
3.The time complexity in the worse case will be O(N), where N is the length of the linked list.

For addition and deletion, it will be a little more complicated since we need to take care of the "prev" field as well. We will go through these two operations in next two articles.

After that, we provide an exercise for you to redesign the linked list using doubly linked list.


### Add Operation - Doubly Linked List 双链表增加操作

