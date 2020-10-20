/**
 * 时间复杂度 O(N) 空间复杂度O(1)
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast =head;
        ListNode *slow =head;
        while(fast && fast->next){            
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *reverse = nullptr;
        while(cur){
            auto tmp = new ListNode(cur->val);
            tmp->next = reverse;
            reverse = tmp;
            cur = cur->next;
        }
        return reverse;
    }
    void reorderList(ListNode* head) {
        ListNode *mid = middleNode(head);
        if(!mid)return;
        ListNode *reverse = reverseList(mid->next);
        mid->next = nullptr;
        while(head && reverse){
            auto tmp = head->next;
            head->next = reverse;
            reverse = reverse->next;
            if(!head->next) break;
            head->next->next = tmp;
            head=tmp;
            
        }
    }
};