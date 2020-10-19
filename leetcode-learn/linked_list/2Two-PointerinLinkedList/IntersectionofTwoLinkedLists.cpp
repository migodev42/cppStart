/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int stepA = 0;
        int stepB = 0;
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA && pA->next){
            pA = pA -> next;
            ++stepA;
        }
        
        while(pB && pB->next){
            pB = pB -> next;
            ++stepB;
        }
        
        if(pA && pB && pA == pB){
            // 存在交点
            int diff=0;
            ListNode *commonA = headA;
            ListNode *commonB = headB;
            if(stepA>stepB){
                diff=stepA-stepB;                
                while(diff--){
                    commonA = commonA->next; 
                }
            }else{
                diff=stepB-stepA;                
                while(diff--){
                    commonB = commonB->next; 
                }
            }
            
            while(commonB != commonA){
                commonA = commonA->next;
                commonB = commonB->next;
            }
            return commonA;
        }
        return nullptr;
        
    }
};