/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head || k<=0) {
           return head;
       }
       ListNode *p = head;
       int len=1;
       //求链表长度，同时可以拿到最后一个节点
       while(p->next) {
           p = p->next;
           len++;
       }
       p->next = head; //链接收尾
       k = len - k%len;
       for(int i=0; i<k; i++) { //找到倒数第k的前驱节点
           p = p->next;
       }
       head = p->next;
       p->next = nullptr;
       return head;
    }
};
// @lc code=end

