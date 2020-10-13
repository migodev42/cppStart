# Linked List
[Introduction](https://leetcode.com/explore/learn/card/linked-list/)

Similar to the `array`, the `linked list` is also a `linear` data structure
和数组类似，链表也是一种**线性**的数据结构
``` cpp
[23] -> [6] -> [15] -> nullptr
```

As you can see, each element in the linked list is actually a separate object while all the objects are `linked together by the reference field` in each element.
链表中每个元素都是分开存储的，而使用一个指针将每个元素连接在一起。


There are two types of linked list: singly linked list and doubly linked list. The example above is a singly linked list and here is an example of doubly linked list:
有两种链表：单向链表和双向链表
``` cpp
nullptr <- [23]   -> [6]   -> [15] -> nullptr
                <-       <-      
```

We will introduce more in later chapters. After this card, you will:
- Understand the structure of singly linked list and doubly linked list; 理解单链表和双向链表的数据结构
- Implement traversal, insertion, deletion in a singly or doubly linked list; 单链表和双向链表上实现遍历，插入，删除
- Analyze the complexity of different operations in a singly or doubly linked list; 分析在单链表和双向链表不同操作的复杂度
- Use two-pointer technique (fast-pointer-slow-pointer technique) in the linked list; 在单链表和双向链表上使用双指针
- Solve classic problems such as reverse a linked list; 解决一些链表的经典问题，比如翻转链表
- Analyze the complexity of the algorithms you designed; 分析算法的复杂度
- Accumulate experience in designing and debugging. 开发和调试的经验