/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
       // pre   cur   nxt 三个指针比较好理解
       while(cur && cur->next) {
           ListNode* nxt = cur->next;
           // cur == nxt, pre->next = nxt;
           // cur != nxt, pre=pre->next, cur = cur->next;
           if(nxt->val == cur->val) {
               cur = nxt;
               pre->next = cur;
           } else {
               pre = cur;
               cur = nxt;
           }
       }
       return preHead.next; 
    }
};
// @lc code=end

