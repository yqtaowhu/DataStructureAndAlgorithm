/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode preHead(0), *pre=&preHead, *cur=head;
        pre->next = cur;
        while(cur && cur->next) {
            ListNode* nxt=cur->next;
            // 不相等，直接操作
            if(cur->val != nxt->val) {
                pre = cur;
                cur = nxt;
            } else {
                // cur == nxt, 一直移动nxt, 直到不相等
                while(nxt && cur->val == nxt->val)
                    nxt = nxt->next;
                cur = nxt;
                pre->next = cur;
            }
        }
        return preHead.next;
    }
};
// @lc code=end

