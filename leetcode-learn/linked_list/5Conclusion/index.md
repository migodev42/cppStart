### [Summary](https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1230/)

单链表和双链表的很多操作都是相似的：
- Both of them are `not able to access the data at a random position` in constant time.
  都不能在常量时间内进行随机读取
- Both of them are able to `add a new node after given node or at the beginning of the list in O(1) time`.
  在链表首部添加节点的时间复杂度都是O（1）
- Both of them are able to `delete the first node` in O(1) time.
  删除链表首部第一个节点的时间复杂度都是O(1)

But it is a little different to `delete a given node` (including the last node).
有些区别在于删除某个节点的时候：
- In a singly linked list, it is not able to get the previous node of a given node so we have to spend O(N) time to find out the previous node before deleting the given node.
- In a doubly linked list, it will be much easier because we can get the previous node with the "prev" reference field. So we can delete a given node in O(1) time.

已知某个节点，单链表删除该节点需要先进行O(N)复杂度的遍历来找到该节点的前一个节点，而双链表可以直接进行删除时间复杂度O(1)