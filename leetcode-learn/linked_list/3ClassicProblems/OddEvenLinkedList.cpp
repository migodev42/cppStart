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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyodd = new ListNode();
        ListNode* dummyeven = new ListNode();
        
        ListNode* cur = head;
        ListNode* odd = dummyodd;
        ListNode* even = dummyeven;
        int idx = 0;
        while(cur){ 
            
            if(idx%2==1){
                if(even){
                    even->next = cur;
                    even = even->next;    
                }                
            }
            else{
                if(odd){
                    odd->next = cur;
                    odd = odd->next;                    
                }                
            }
            
            ++idx;
            cur = cur ->next;
        }

        even->next = nullptr;
        odd->next = dummyeven->next;

        return dummyodd->next;
        
    }
};