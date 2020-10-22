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
    ListNode *reverselist(ListNode* head){        
        ListNode *reverse = nullptr;
        ListNode *cur = head;
        while(cur){
            auto tmp = new ListNode(cur->val);
            tmp->next = reverse;
            reverse = tmp;
            cur = cur->next;
        }
        return reverse;
    }
    ListNode *findmid(ListNode* head){    
        ListNode *dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode *fast = dummyhead;
        ListNode *slow = dummyhead;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode *mid = findmid(head);        
        if(!mid) return true;
        ListNode *reverse = reverselist(mid->next);
        if(!reverse) return true;
        mid->next = nullptr;
        ListNode *cur=head;
        
        while(cur && reverse){
            if(cur->val!=reverse->val){
                cout << cur->val << ", " << reverse->val << endl;
                return false;  
            } 
            cur=cur->next;
            reverse=reverse->next;
        }
        int cnt = 0;
        while(cur || reverse){
            if(cur){
                cur= cur->next;  
                ++cnt;
            }else{
                reverse = reverse->next;
                ++cnt;
            }
        }
        if(cnt>1) return false;
        return true;
        
    }
};