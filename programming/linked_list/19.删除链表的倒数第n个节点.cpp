/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    // 主要找到前驱的节点，有两种方法
    // 方法1， 遍历两遍，找到前驱节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode preHead(0), *pre = &preHead;
        pre->next = head;
        ListNode* cur = head;
        int len = 0;
        while(cur) {
            len += 1;
            cur = cur->next;
        }
        if(len < n) return nullptr;
        for(int i=0; i < len-n; i++) {
            pre = pre->next;
        }

        pre->next = pre->next->next;
    
        return preHead.next;
    }
    // 方法2， 遍历一遍，快慢指针，找到前驱节点
};
// @lc code=end

