#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

ListNode *deleteNode(ListNode* head, ListNode* node) {
    if(!head) {
        return head;
    }
    if(head == node) {
        return head->next;
    }
    // node是尾结点
    ListNode *cur = head;
    if(!node->next) {
        while(cur && cur->next && cur->next->next) {
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;
    }
    // node不是尾结点, O(1)时间复杂度
    node->val = node->next->val;
    node->next = node->next->next;
    return head;
}

void print_funciton(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode *p0 = new ListNode(1);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(3);
    ListNode *p3 = new ListNode(4);
    ListNode *p4 = new ListNode(5);
    p0->next = p1; p1->next = p2;
    p2->next = p3; p3->next = p4;
    print_funciton(p0);

    ListNode *head = deleteNode(p0, p4);
    print_funciton(head);
}