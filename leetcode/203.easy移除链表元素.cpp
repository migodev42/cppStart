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
    ListNode* removeElements(ListNode* head, int val) {
        // dummyhead未分配到堆内存，return dummyhead之后自动析构
        ListNode dummyhead = ListNode();
        dummyhead.next = head;
        ListNode* cur = &dummyhead;
        while(cur->next){
            if(cur->next->val == val){                
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }            
        }
        return dummyhead.next;
    }
};