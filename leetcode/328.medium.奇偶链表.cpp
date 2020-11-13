/**
 * Definition for singly-linked list.
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;        

        ListNode* even = head;
        ListNode* odd = head->next;                

        ListNode* dummyOdd = new ListNode();
        dummyOdd->next = head->next;

        if(!odd) return head;

        while(even && even->next && odd && odd->next){
            even->next=odd->next;
            even = even->next;
            odd->next= even->next;
            odd=odd->next;
        }
        even->next=dummyOdd->next;
        return head;
    }
};