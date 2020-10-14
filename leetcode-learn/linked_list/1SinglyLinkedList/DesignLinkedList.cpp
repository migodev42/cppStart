#include <iostream>

using std::cout;
using std::endl;

class MyLinkedList {
private:
    struct Node {
		int val;
		Node *next;
		Node(int x): val(x), next(nullptr) {}
	};
    

public:
    Node *head;
	int size;        
    /** Initialize your data structure here. */
    MyLinkedList(){
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int res = -1;
        if (index >= size) {
            return res;
        }

        Node* cur = head;

        while(cur && index>0){
            cur = cur -> next;
            --index;
        }
        if(cur) return cur->val;

        return res;        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(!head){
            addAtHead(val);
            return;
        }
        Node* cur = head;
        while(cur->next){
            cur = cur->next;
        }
        Node* newnode = new Node(val);
        cur->next = newnode;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
         if(index==0){
            addAtHead(val);
            return;
        }
        if(index > size+1) return;        
        Node* cur = head;
        
        while(cur->next && index-1>0){
            cur = cur->next;
            --index;
        }
        if(cur){
            Node* newnode = new Node(val);
            newnode->next = cur->next;
            cur -> next = newnode;                
            ++size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index==0 && head){
            head = head->next;
            --size;
            return;
        }
        Node* cur = head;
        while(cur->next && index-1>0){
            cur = cur->next;
            --index;
        }
        if(cur){
            auto prev = cur;
            auto todel = cur->next;
            auto tail = todel? todel->next:nullptr;
            prev -> next = tail;
            --size;
        }
    }
};

int main() {
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    // myLinkedList->addAtTail(3);
    // myLinkedList->addAtIndex(1, 2);    // linked list becomes 1->2->3
    // myLinkedList->get(0);              // return 2
    // myLinkedList->deleteAtIndex(0);    // now the linked list is 1->3
    // myLinkedList->get(0);              // return 3
    // cout << myLinkedList-> head ->val << endl;
    cout << myLinkedList-> size << endl;
    int rs = myLinkedList->get(1);
    cout << rs << endl;
    
    
    
}