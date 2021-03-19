/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head, *fast = head->next;
        ListNode* l1 = slow, *l2 = fast;
        while(fast && fast->next) {
            slow->next = fast->next;
            slow = slow->next;
            if(slow) {
                fast->next = slow->next;
                fast = fast->next;
            }
        }
        slow->next = l2;
        return l1;
    }
};
// @lc code=end

