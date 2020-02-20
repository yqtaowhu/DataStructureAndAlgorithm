/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode preHead(0), *pre = &preHead, *cur=head->next, *cur_0 = head;
        pre->next = head;
        while(cur) {
            // 1. 每次将pre初始化开头
            pre = &preHead;
            // 2. 找到第一个比cur大的节点
            while(pre->next && pre->next->val < cur->val) {
                pre = pre->next;
            }
            // 3. 注意特殊情况，不需要改变
            if(pre->next == cur) {
                cur = cur->next;
                cur_0 = cur_0->next;
                continue;
            }
            // 4. 改变节点指向
            ListNode* nxt = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur_0->next = nxt;
            cur = nxt;
        }
        return preHead.next;
    }
};
// @lc code=end

