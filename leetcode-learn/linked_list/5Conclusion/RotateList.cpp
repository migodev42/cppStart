#include <iostream>

using std::cout;
using std::endl;


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
    int getSize(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            ++size;
            curr = curr->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;
        int size = getSize(head);
        int start_pos_from_end = k % size;
        if (!start_pos_from_end) return head;

        cout << "size: " << size << " pos from end: " << start_pos_from_end << endl;

        ListNode* fast = head;
        ListNode* slow = head;

        while (start_pos_from_end--) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        cout << fast->val << endl;
        cout << slow->val << endl;


        ListNode* tmpHead = slow->next;
        slow->next = nullptr;
        ListNode* curr = tmpHead;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = head;
        return tmpHead;
    }
};