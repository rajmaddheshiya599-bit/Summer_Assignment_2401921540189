#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* next) {
        val = x;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == nullptr) return nullptr;

        int size = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        int newidx = size - n + 1;

        // First node delete karna hai
        if (newidx == 1) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }

        temp = head;

        for (int i = 1; i < newidx - 1; i++) {
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};