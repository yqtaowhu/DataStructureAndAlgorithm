/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 2 6 4
        // 1 5
        ListNode *a = headA, *b = headB;
        //while(a && b && a != b) {  这样ab都不会有空，进入死循环
        while(a != b) {
            a = a ? a->next : headB;  // 要让a>next可能为空，才能跳出循环
            b = b ? b->next : headA;
        }
        return a;
    }
};