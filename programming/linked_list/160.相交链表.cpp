/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // 貌似这种更简单，容易理解
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2 = headB;
        while(p1 || p2) {
            if(p1 == p2) {
                return p1;
            }
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return NULL;
    }
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA,*p2=headB;
        while(p1!=p2) {
            p1= p1 ? p1->next : headB;
            p2= p2 ? p2->next : headA;
        }
        return p1;
    }
};
// @lc code=end

