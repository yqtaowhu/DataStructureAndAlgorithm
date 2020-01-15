/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) return head;
        int listLen = 0;
        ListNode preHead(0);
        preHead.next = head;
        ListNode* cur = &preHead, *pre = &preHead, *next = NULL;
        while (cur = cur->next) listLen++;
        while (listLen >= k) {
            cur = pre->next;
            next = cur->next;
            for (int i = 0; i < k - 1; i++) {
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }
            pre = cur;
            listLen -= k;
        }
        return preHead.next;
    }
};
// @lc code=end

