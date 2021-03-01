/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
  重新创建新链表法
  时间O(n) 空间O(n)
 */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//       ListNode* dummy = new ListNode();

//       ListNode* curr = head;

//       while(curr){
//         ListNode* tmp = new ListNode(curr->val);
//         tmp->next = dummy->next;
//         dummy->next = tmp;
//         curr = curr->next;
//       }
//       return dummy->next;
//     }
// };

/* 双指针法 */
// class Solution {
//    public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* slow = nullptr;
//         ListNode* fast = nullptr;
//         ListNode* curr = head;
//         while (curr) {
//             ListNode* tmp = curr->next;
//             fast = curr;
//             fast->next = slow;
//             slow = fast;
//             curr = tmp;
//         }
//         return fast;
//     }
// };

/* 递归实现法 */
class Solution {
   public:
    ListNode* reverse(ListNode* slow, ListNode* fast) {
        if (!fast) return slow;
        ListNode* tmp = fast->next;
        fast->next = slow;
        slow = fast;
        fast = tmp;
        return reverse(slow, fast);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* slow = nullptr;
        ListNode* fast = nullptr;
        fast = head;
        return reverse(slow, fast);
    }
};

// @lc code=end
