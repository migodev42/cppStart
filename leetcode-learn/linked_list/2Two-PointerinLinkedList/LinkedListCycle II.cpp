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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            if(fast == slow){
                ListNode *meet = fast;
                ListNode *start = head;
                while(meet != start){
                    meet = meet->next;
                    start = start->next;
                }
                return meet;
            }
        }
        return nullptr;
    }
};