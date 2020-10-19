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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyhead = new ListNode();
        dummyhead->next = head;
        
        ListNode *forward = dummyhead;
        ListNode *needremove = dummyhead;
        
        while(forward->next && n--){
            forward = forward->next;
        }
        
        
        while(forward->next){
            forward = forward ->next;
            needremove = needremove -> next;
        }
        
        auto tmp = needremove->next;
        needremove->next = tmp->next;
        delete tmp;
        return dummyhead->next;
    }
};