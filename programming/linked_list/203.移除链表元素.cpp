/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode preHead(0), *pre = &preHead;
        pre->next = head;
        while(head) {
            if(head->val == val) {
                pre->next = head->next;
                head = head->next;
            } else {
                head = head->next;
                pre = pre->next;
            }
        }
        return preHead.next;
    }
};
// @lc code=end

