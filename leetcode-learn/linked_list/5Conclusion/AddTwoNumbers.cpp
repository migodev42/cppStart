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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode();
        ListNode * curr = dummy;
        int add = 0;
        while(l1 && l2){
            int value = (l1->val + l2->val + add);
            if( value >=10) add = 1;
            else add = 0;
            curr->next = new ListNode(value%10);
            
            curr = curr -> next;
            l1 = l1->next;
            l2 = l2->next;
            
        }
        while(l1){
            int value = (l1->val + add);
            
            if(value>=10) add=1;
            else add=0;
            
            curr->next = new ListNode(value % 10);
            curr = curr -> next;
            l1 = l1->next;
        }
        
        while(l2){
            int value = (l2->val + add);            

            if(value>=10) add=1;
            else add=0;
            
            curr->next = new ListNode(value % 10);
            curr = curr -> next;
            l2 = l2->next;
        }
        if(add){
            curr -> next  = new ListNode(add);
        }
        
        return dummy->next;
    }
};