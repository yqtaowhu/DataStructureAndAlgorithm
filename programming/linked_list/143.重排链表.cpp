/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        // 找到中间节点，然后反转  1->2->3<-4<-5
        ListNode *low = head, *fast=head;
        while(fast && fast->next) {
            fast = fast->next->next;
            low = low->next;
        }
        // 反转链表
        ListNode *pre=low, *cur = pre->next;
        pre->next = nullptr;  //注意要不然会死循环
        while(cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        // 更改指针的改变即可
        ListNode* tail = pre;
        cur = head;
        while(cur != tail && tail != cur->next) {
            ListNode *tmp1 = cur->next;
            ListNode *tmp2 = tail->next;

            cur->next = tail;
            tail->next = tmp1;
            cur = tmp1;
            tail = tmp2;
        }
    }
};
// @lc code=end

