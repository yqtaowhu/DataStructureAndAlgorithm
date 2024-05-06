/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   234.回文链表.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:00:00 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/06 21:00:01 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    ListNode *reverse_list(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *pre = nullptr;
        while(head) {
            ListNode *nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        // 1 2 2 1 
        // 1 2 3 4 5
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = reverse_list(slow);
        while(head && cur) {
            if(head->val != cur->val) {
                return false;
            }
            head = head->next;
            cur = cur->next;
        }
        return true;
    }
};
// @lc code=end

