/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 1 2 2 1      ->  1->2-2   1 -> 2 -> nullptr
        // 1 2 2 2 1    ->  1 -> 2->2     1-> 2->2   1->2->2
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转链表
        ListNode *pre = nullptr, *cur = slow;
        while(cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        // pre
        while(head && pre) {
            if(head->val != pre->val) {
                return false;
            }
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};