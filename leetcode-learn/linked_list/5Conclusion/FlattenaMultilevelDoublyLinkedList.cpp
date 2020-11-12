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
        curr->next = nxt;
        nxt->prev = curr;
        
        auto tmpNext = nxt->next;
        Node* tail = traverse(nxt, nxt->child);
        nxt->child=nullptr;
        
        return traverse(tail,tmpNext);            
    }
    Node* flatten(Node* head) {
        if(!head) return head;
        
        Node* dummy = new Node();
        dummy->next = head;
        traverse(dummy, head);
        
        dummy->next->prev = nullptr;
        return dummy->next;
    }
};