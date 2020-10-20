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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode();
        dummy -> next = head;
        ListNode *cur = dummy;
        
        while(cur && cur->next){
            auto tmp = cur->next;
            if(tmp->val ==val){
                cur->next = cur->next->next;
                delete tmp;
                continue;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};