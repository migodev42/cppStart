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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* iter = dummyhead->next;
        ListNode* rs = nullptr;
        while(iter){
            if(iter==head){
                rs = new ListNode(iter->val);
                rs->next = nullptr;
            } 
            else{
                auto tmp = new ListNode(iter->val);
                tmp->next = rs;
                rs = tmp;
            }            
            iter = iter->next;
                       
        }
        return rs;
    }
};