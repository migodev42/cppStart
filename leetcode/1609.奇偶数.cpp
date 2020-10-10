/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        deque<pair<TreeNode*, int>> currdeque;
        deque<pair<TreeNode*, int>> lastdeque;
        
        vector<int> check={0};
        
        currdeque.push_back(make_pair(root,0));
        lastdeque.push_back(make_pair(nullptr,-1));
        cout << "start" << endl;
        while(!currdeque.empty()){
            
            auto curritem = currdeque.front();
            auto currnode = curritem.first;
            int currlevel = curritem.second;

            auto lastitem = lastdeque.front();
            auto lastnode = lastitem.first;
            int lastlevel = lastitem.second;
                                    
            if(currnode->val % 2 == currlevel %2) return false;
            
            if(lastlevel == currlevel){
                // 奇数层应该递增
                if(lastlevel>=0 && currlevel%2==1 ){
                    if(lastnode->val <= currnode->val) return false;   
                } 
                // 偶数层应该递减
                if(lastlevel>=0 && currlevel%2==0 ){
                    if(lastnode->val >= currnode->val) return false;   
                }
            }
                        
            lastdeque.pop_front();
            lastdeque.push_back(make_pair(currnode,currlevel));
            currdeque.pop_front();
            
            if(currnode->left){
                currdeque.push_back(make_pair(currnode->left,currlevel+1));
            }
            if(currnode->right){
                currdeque.push_back(make_pair(currnode->right,currlevel+1));
            }                                    
        }
        return true;
        
    }
};