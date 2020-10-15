/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/* 
    没有像之前的版本用两个队列，而是用一个pre来存储上一个节点的状态
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        queue<pair<Node*, int>> traverse;
        pair<Node*, int> pre;
        traverse.push(make_pair(root,0));
        
        while(traverse.size()){
            pair<Node*, int> curr = traverse.front();
            Node *currnode = curr.first;
            int currlevel = curr.second;

            if(pre.first){                
                if(pre.second == currlevel){
                    pre.first->next = currnode;
                }else{
                    pre.first->next = nullptr;
                }                
            }
            pre.first = currnode;
            pre.second = currlevel;

            traverse.pop();
            if(currnode->left) traverse.push(make_pair(currnode->left,currlevel+1));
            if(currnode->right) traverse.push(make_pair(currnode->right,currlevel+1));
        }
        return root;
    }
};