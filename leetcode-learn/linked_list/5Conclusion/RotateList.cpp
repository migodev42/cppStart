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
        int size = getSize(head);
        int start_pos_from_end = k % size;
        cout << size << start_pos_from_end << endl;
        return head;
    }
};