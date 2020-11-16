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
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* createListNode(int k) {
            Node* head = new Node(k);
            head->next = head;
            return head;
    }
    void insertToNext(Node* toInsert, int insertVal) {
        Node* tmp = toInsert->next;
        toInsert->next = new Node(insertVal);
        toInsert->next->next = tmp;
        return;
    }
    Node* insert(Node* head, int insertVal) {
        if (!head) return createListNode(insertVal);
        Node* curr = head->next;
        Node* min_node = head;

        // 找最小值节点
        while (curr != head) {
            if (curr->val < min_node->val) min_node = curr;
            curr = curr->next;
        }

        // 插入到合适的位置
        if (min_node->val > insertVal) {
            Node* curr = min_node;
            while (curr->next != min_node) {
                curr = curr->next;
            }
            insertToNext(curr, insertVal);
        }
        else {
            Node* curr = min_node;
            while (curr->next != min_node) {
                if (curr->next->val <= insertVal) {
                    curr = curr->next;
                }
                else {
                    insertToNext(curr, insertVal);
                    break;
                }
            }
            if (curr->next == min_node) {
                insertToNext(curr, insertVal);
            }
        }
        return head;
    }
};