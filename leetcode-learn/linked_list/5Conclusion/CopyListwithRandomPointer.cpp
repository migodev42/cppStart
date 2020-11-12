#include <iostream>

using std::cout;
using std::endl;

/*

    [O1空间实现方法](https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/)
    - 在每个原有节点后插入copy
    - 将copy的random指向正确的位置
    - 解开origin和copy

    [on空间方法](https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/)
    - 对每个节点映射一个copy节点
    - random指向正确位置
    - 解开origin和copy
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    void print(Node* head){
        Node* curr = head;
        cout << "nodes: ";
        while(curr){
            cout << curr->val  << " ";
            curr = curr->next;
        }
        cout << endl;    
        
        Node* curr_rand = head;
        while(curr_rand){
            cout << curr_rand->random  << " ";
            curr_rand = curr_rand->next;
        }
        cout << endl;    
    }
    Node* copyRandomList(Node* head) {
        if(!head) return head;        
        Node* curr = head;

        /* 每个node之后插入它的copy */
        while(curr){
            Node* tmp = curr->next;
            Node* copy = new Node(curr->val);
            copy->next = tmp;
            curr->next = copy;
            curr = tmp;
        }

        curr = head;        
        /* 拷贝random */
        while(curr && curr->next){
            curr->next->random = curr->random ? curr->random->next : nullptr;
            curr = curr->next->next;
        }

        /* 解开copy和origin */
        Node* dummyhead = new Node(0);                
        Node* origin=head;
        Node* copy=head->next;        
        dummyhead->next = copy;
        while(origin&&origin->next && copy && copy->next){            
            
            origin->next=origin->next->next;
            copy->next = copy->next->next;
            
            copy = copy->next;
            origin = origin->next;
        }        
        copy->next = nullptr;
        origin->next = nullptr;            
        return dummyhead->next;
    }
};
