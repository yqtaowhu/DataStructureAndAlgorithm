/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *pre = &preHead; // 用一个fake节点，方便处理
        int carry = 0;
        while(l1 || l2 || carry) {
            int a = l1 ? l1->val: 0;
            int b = l2 ? l2->val: 0;
            int sum = a + b + carry;
            ListNode* nxt = new ListNode(sum%10);
            carry = sum / 10;
            pre->next = nxt;
            pre = nxt;
            l1 = l1 ? l1->next: l1;
            l2 = l2 ? l2->next: l2;
        }
        return preHead.next;
    }
};
// @lc code=end

