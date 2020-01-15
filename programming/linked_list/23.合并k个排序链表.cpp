/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummy(INT_MIN);
		ListNode *tail = &dummy;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
    // 注意两两合并的写法
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		const size_t k = lists.size();
		if (k == 0) return NULL;
		if (k == 1) return lists[0];
		for (size_t i = 1; i < k; i = i * 2) 
			for (size_t j = 0; j < k - i; j += i * 2)
                // [j, i+j] i理解成跳跃的间隔
				lists[j] = mergeTwoLists(lists[j], lists[i + j]);
		return lists[0];
	}
};
// @lc code=end

