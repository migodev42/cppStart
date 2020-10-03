- [Solve Tree Problems Recursively](https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/534/)

Recursion is one of the most powerful and frequently used techniques for solving tree problems.
递归是解决树相关问题最有用也最常用的方式。

a tree can be defined recursively as a node(the root node) that includes a value and a list of references to children nodes.
树可以被递归的描述为一个节点，包含其值和对其子节点的引用。

Recursion is one of the natural features of a tree. Therefore, many tree problems can be solved recursively. 
递归是树的自然属性，因此树的很多问题可以递归的解决。

Typically, we can solve a tree problem recursively using a top-down approach or using a bottom-up approach.

### "Top-down" Solution 自顶向下

So the "top-down" solution can be considered as a kind of **preorder** traversal. 
先序遍历
先遍历根节点
``` cpp
int answer;		       // don't forget to initialize answer before call maximum_depth
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
}
```
### "Bottom-up" Solution 自底向上
This process can be regarded as a kind of **postorder** traversa
后序遍历
将子节点遍历完后再开始遍历根节点
``` cpp
int maximum_depth(TreeNode* root) {
	if (!root) {
		return 0;                                 // return 0 for null node
	}
	int left_depth = maximum_depth(root->left);
	int right_depth = maximum_depth(root->right);
	return max(left_depth, right_depth) + 1;	  // return depth of the subtree rooted at root
}
```
### Conclusion 总结
t is not easy to understand recursion and find out a recursive solution for the problem. It needs practice.

When you meet a tree problem, ask yourself two questions: Can you determine some parameters to help the node know its answer? Can you use these parameters and the value of the node itself to determine what should be the parameters passed to its children? If the answers are both yes, try to solve this problem using a **"top-down"**recursive solution.
1 能否定义一个变量来得到当前节点的信息
2 这个变量能否向子节点传递

Or, you can think of the problem in this way: for a node in a tree, if you know the answer of its children, can you calculate the answer of that node? If the answer is yes, solving the problem recursively using a **bottom up** approach might be a good idea.
1 如果已知字节点的信息，能否在父节点计算出答案



