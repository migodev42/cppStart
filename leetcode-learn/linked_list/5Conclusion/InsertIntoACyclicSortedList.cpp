/* 
    Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list. 

    Input:
    LinkedList = 1->2->4
    (the first and last node is connected,
    i.e. 4 --> 1)
    data = 2
    Output: 1 2 2 4

    Input:
    LinkedList = 1->4->7->9
    (the first and last node is connected,
    i.e. 9 --> 1)
    data = 5
    Output: 1 4 5 7 9
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
    ListNode* insertIntoACyclicSortedList(ListNode* head, int k) {
        if(!head){
            
        }
        
    }
};