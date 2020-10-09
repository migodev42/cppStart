#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <iterator>
#include <deque>
#include <utility>

using std::vector;
using std::max;
using std::find;
using std::cout;
using std::endl;
using std::deque;
using std::stack;
using std::pair;
using std::ostream_iterator;
using std::make_pair;

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

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        deque<pair<Node*, int>> currque;
        deque<pair<Node*, int>> lastque;
        currque.push_back(make_pair(root, 0));
        lastque.push_back(make_pair(nullptr, -1));

        while (!currque.empty()) {

            auto curr = currque.front();
            auto last = lastque.front();

            auto curr_node = curr.first;
            auto curr_level = curr.second;

            auto last_node = last.first;
            auto last_level = last.second;

            if (!lastque.empty()) {
                lastque.pop_front();
            }
            if (last_level == curr_level) {
                last_node->next = curr_node;
            }

            auto curr_leftsub = curr_node->left;
            auto curr_rightsub = curr_node->right;

            currque.pop_front();
            lastque.push_back(make_pair(curr_node, curr_level));
            if (curr_leftsub) {
                currque.push_back(make_pair(curr_leftsub, curr_level + 1));
            }
            if (curr_rightsub) {
                currque.push_back(make_pair(curr_rightsub, curr_level + 1));
            }
        }
        return root;
    }
};