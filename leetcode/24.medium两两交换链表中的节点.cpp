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
    ListNode* swapPairs(ListNode* head) {        
        if(!head || !head->next) return head;
        ListNode* fir = new ListNode();
        fir->next = head;
        ListNode* sec = head;
        
        head = head->next;
        while(fir && sec){
            auto  other = sec -> next ? sec -> next->next : nullptr;
            auto  pre = fir;
            auto  first = sec;
            auto  second = sec -> next;
            if(!second) break;

            pre -> next = second;
            first -> next = other;
            second -> next = first;
                        
            fir = sec ;
            sec = fir? fir -> next : nullptr;
        }
        return head;
    }
};