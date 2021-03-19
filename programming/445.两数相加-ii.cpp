/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */

// @lc code=start
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
    ListNode* reverse_link_list(ListNode* head) {
        ListNode preHead(0), *pre = &preHead;
        pre->next = head;
        while(head && head->next) {
            ListNode* nxt = head->next;
            head->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return preHead.next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ll1 = reverse_link_list(l1);
        ListNode* ll2 = reverse_link_list(l2);
        ListNode preHead(0), *pre = &preHead;
        int carry = 0;
        while(ll1 || ll2 || carry) {
            int a = ll1 ? ll1->val : 0;
            int b = ll2 ? ll2->val : 0;
            int sum = a + b + carry;
            ListNode *tmp = new ListNode(sum % 10);
            tmp->next = pre->next;
            pre->next = tmp;
            carry = sum / 10;
            ll1 = ll1 ? ll1->next : NULL;
            ll2 = ll2 ? ll2->next : NULL;
        }
        return preHead.next;
    }
};
// @lc code=end

