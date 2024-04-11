/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   141.环形链表.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:45:45 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/11 20:45:48 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow == fast;
    }
};
// @lc code=end

