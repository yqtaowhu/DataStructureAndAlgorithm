/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if(!head) head;
        ListNode *low=head, *fast=head;
        while(fast && fast->next) {
            low = low->next;
            fast = fast->next->next;
            if(low == fast) {
                low = head;
                while(low) {
                    if(low == fast)
                        return low;
                    low = low->next;
                    fast = fast->next;
                }
            }
        }
        return nullptr;
    }
};
// @lc code=end

