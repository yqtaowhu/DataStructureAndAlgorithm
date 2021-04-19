/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }
        // 1->2->2->1      ->  1->2->2<-1
        // 1->2->3->2->1   ->  1->2->3<-2<-1
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转链表
        ListNode* cur = slow->next, *pre = slow;
        slow->next = nullptr;
        while(cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        ListNode* tail = pre;
        cur = head;
        while(cur && tail) {
            if(cur->val != tail->val) {
                return false;
            }
            cur = cur->next;
            tail = tail->next;
        }
        return true;
    }
};
// @lc code=end

