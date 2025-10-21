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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 小根堆
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val; // 最小堆
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq; 
        for(auto head: lists) {
            if(head) {
                pq.push(head);
            }
        }
        ListNode dummy(0);
        ListNode *pre = & dummy;
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            if(node->next) {
                pq.push(node->next);
            }
            pre->next = node;
            pre = pre->next;
        }
        return dummy.next;
        
    }
};


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

