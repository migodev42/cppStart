#include <vector>
#include <deque>
#include <utility>
#include <queue>

// #include 
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
using std::vector;
using std::deque;
using std::pair;
using std::make_pair;
using std::queue;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 使用deque实现
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> rs;
//         deque<pair<TreeNode*, int>> q;
//         if (!root) {
//             return rs;
//         }
//         q.push_back(make_pair(root, 0));
//         while (q.size() != 0)
//         {
//             pair<TreeNode*, int> next = q.front();
//             auto level = next.second + 1;
//             TreeNode* node = next.first;
            
//             // rs为二维数组，每一层的节点存放为一个数组
//             if (rs.size() < level) {
//                 rs.resize(level);
//             }

//             rs[level - 1].push_back(node->val);
//             // cout << level << node->val;
//             // you may want to print the current node here or do other processing
            
//             // 处理完的节点出队列
//             q.pop_front();
            
//             // 下一层的子节点依次入队列
//             if (node->left)
//                 q.push_back(make_pair(node->left, level));
//             if (node->right)
//                 q.push_back(make_pair(node->right, level));
//         }
//         return rs;
//     }
// };

// 使用queue实现
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {        
        vector<vector<int>> result;
        if(!root) return result;

        queue<pair<TreeNode*,int>> cursor; // 每此往队列push节点时候，需要记录层级
        cursor.push({root,0});
        
        while(cursor.size()){
            auto curritem = cursor.front();
            TreeNode* currnode = curritem.first;
            int currlevel = curritem.second;
            
            // 每一层的result中的数组需要初始化，避免[]取值符号取到超出数组范围的位置
            if(result.size()<currlevel+1){
                result.resize(currlevel+1);
            }
            result[currlevel].push_back(currnode->val);
            
            // 处理完一个节点后弹出
            cursor.pop();
            if(currnode->left){
                cursor.push({currnode->left, currlevel+1});
            }
            if(currnode->right){
                cursor.push({currnode->right, currlevel+1});
            }

        }
        return result;
    }
};