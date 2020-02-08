/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode lowHead(0), highHead(0), *low = &lowHead, *high=&highHead, *cur = head;
        while(cur) {
            if(cur->val < x) {
                low->next= cur;
                low = low->next;
            } else {
                high->next = cur;
                high = high->next;
            }
            cur = cur->next;
        }
        low->next = highHead.next;
        high->next = nullptr;
        return lowHead.next;
    }
};
// @lc code=end

