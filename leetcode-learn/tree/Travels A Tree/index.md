-[Traverse a Tree - Introduction](https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/992/)

order是指的是root遍历的order

### Pre-order Traversal 先序遍历
Pre-order traversal is to visit the root first. Then traverse the left subtree. Finally, traverse the right subtree.
从root开始，遍历左子树，再遍历右子树.

### In-order Traversal 中序遍历
In-order traversal is to traverse the left subtree first. Then visit the root. Finally, traverse the right subtree.
先遍历左子树，再到root，再遍历右子树

Typically, for binary search tree, we can retrieve all the data in sorted order using in-order traversal. We will mention that again in another card([Introduction to Data Structure - Binary Search Tree](https://leetcode.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/)).
二分搜索树用的就是中序遍历

### Post-order Traversal 后序遍历
Post-order traversal is to traverse the left subtree first. Then traverse the right subtree. Finally, visit the root.
先遍历右子树，再遍历左子树,再到root

It is worth noting that when you delete nodes in a tree, deletion process will be in post-order. That is to say, when you delete a node, you will delete its left child and its right child before you delete the node itself.
删除节点的时候用后序遍历是很有用的，因为会先删除左右子节点，最后删除root

Also, post-order is widely use in mathematical expression. It is easier to write a program to parse a post-order expression. Here is an example:
数学表达式解析中也经常使用到后序遍历

You can easily figure out the original expression using the inorder traversal. However, it is not easy for a program to handle this expression since you have to check the **priorities of operations**.

If you handle this tree in postorder, you can easily handle the expression using a stack. Each time when you meet a operator, you can just pop 2 elements from the stack, calculate the result and push the result back into the stack.
如果使用栈来解决这个问题的话，是不行的

### Level-order Traversal - Introduction 层序遍历
Level-order traversal is to traverse the tree level by level.
一层一层的遍历树

`Breadth-First Search` is an algorithm to traverse or search in data structures like a tree or a graph.
广度优先搜索

Typically, we use a queue to help us to do BFS. If you are not so familiar with the queue, you can find more information about that in another card coming soon.
一般来说，我们使用队列来辅助我们做BFS广度优先搜索

