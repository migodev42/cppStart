/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
   public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr){};
        LinkedNode() : val(0), next(nullptr){};
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummy = new LinkedNode();
        _size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1. */
    int get(int index) {
        if (index > _size - 1 || index < 0) return -1;
        LinkedNode* curr = _dummy;
        while (index--) {
            curr = curr->next;
        }
        return curr->next->val;
    }

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked
     * list. */
    void addAtHead(int val) {
        LinkedNode* newval = new LinkedNode(val);
        newval->next = _dummy->next;
        _dummy->next = newval;
        ++_size;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* curr = _dummy;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new LinkedNode(val);
        ++_size;
    }

    /** Add a node of value val before the index-th node in the linked list. If
     * index equals to the length of linked list, the node will be appended to
     * the end of linked list. If index is greater than the length, the node
     * will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > _size || index < 0) return;
        LinkedNode* curr = _dummy;
        while (index--) {
            curr = curr->next;
        }
        LinkedNode* tmp = new LinkedNode(val);
        tmp->next = curr->next;
        curr->next = tmp;
        ++_size;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index > _size - 1 || index < 0) return;
        LinkedNode* curr = _dummy;
        while (index--) {
            curr = curr->next;
        }
        LinkedNode* tmp = curr->next;
        curr->next = tmp->next;
        delete tmp;
        --_size;
    }

   private:
    int _size;
    LinkedNode* _dummy = nullptr;
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
// @lc code=end
