/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
          if(slow==fast){
            ListNode* headstart = head;
            ListNode* curr = slow;
            while(curr != headstart){
              headstart = headstart->next;
              curr = curr->next;
            }
            return curr;
          }
        }
        return nullptr;
    }
};
// @lc code=end
