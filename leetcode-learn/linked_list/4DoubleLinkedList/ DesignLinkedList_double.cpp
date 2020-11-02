class MyLinkedList {
private:
    struct Node {
		int val;
		Node *next;
        Node *prev;
        Node(): next(nullptr), prev(nullptr) {}
		Node(int x): val(x), next(nullptr), prev(nullptr) {}
	};
    
    Node *dummyhead;
	int size;
public:
        
    /** Initialize your data structure here. */
    MyLinkedList(){
        dummyhead = new Node();
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // 超出链表范围（index从0开始，size从1开始）
        if(index>size-1 || index <0) return -1;
        
        Node * cur = dummyhead->next;
        while(index--){
            cur = cur -> next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        newnode->next = dummyhead->next;
        dummyhead->next = newnode;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {  
        Node* cur = dummyhead;
        while(cur->next){
            cur = cur->next;
        }
        Node* newnode = new Node(val);
        cur->next = newnode;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {   
        // index可以等于size，因为add操作可以在尾部（index从0开始，size从1开始）
        if(index > size) return;
        Node* cur = dummyhead;
        
        while(index--){
            cur = cur->next;
        }
        Node* newnode = new Node(val);
        newnode->next = cur->next;
        cur -> next = newnode;                
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // index不能等于size，因为delete操作的元素需要存在（index从0开始，size从1开始）
        if(index>=size || index <0) return;
        
        Node* cur = dummyhead;
        while(index--){
            cur = cur->next;
        }

        auto tmp = cur->next;
        auto tail = tmp?tmp->next:nullptr;
        cur -> next = tail;
        delete tmp;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */