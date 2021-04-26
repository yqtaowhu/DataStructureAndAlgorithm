/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        // 4 2 1 3
        // 4 2 1 3 5
        ListNode* slow = head, *fast = head;
        // 奇数，中间，偶数，左半
        while(fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 切分两半
        fast = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(fast);
        return merge(left, right);

    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode sub(0), *ptr = &sub;
        while (l1 && l2) {
            auto &node = l1->val < l2->val ? l1 : l2;
            ptr = ptr->next = node, node = node->next;
        }
        ptr->next = l1 ? l1 : l2;
        return sub.next;
    }
};
// @lc code=end

