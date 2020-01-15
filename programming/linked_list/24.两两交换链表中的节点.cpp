/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
       if(!head) return nullptr;
       ListNode preHead(0), *pre = &preHead, *cur = head;
       pre->next = head;
       while(cur && cur->next) {
           ListNode* nxt = cur->next;
           cur->next = nxt->next;
           nxt->next = cur;
           pre->next = nxt;
           //更新pre和cur的位置
           pre = cur;
           cur = cur->next;
       }
       return preHead.next;
    }
};
// @lc code=end

