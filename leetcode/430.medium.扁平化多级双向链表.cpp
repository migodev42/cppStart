/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* traverse(Node* curr, Node* nxt){
        if(!nxt) return curr;
        nxt->prev = curr;
        curr->next = nxt;
        
        Node* tmpNext = nxt->next;
        Node* tail = traverse(nxt, nxt->child);
        nxt->child = nullptr;
        
        return traverse(tail, tmpNext);
    }
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* dummyHead = new Node();
        dummyHead->next = head;
        traverse(dummyHead, dummyHead->next);
        dummyHead->next->prev = nullptr;
        return dummyHead->next;
    }
};