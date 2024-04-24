/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21.合并两个有序链表.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:48 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/24 19:40:50 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *pre = &preHead;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
                
            }
            pre = pre->next;
        }
        pre->next=l1 ? l1 : l2;

        return preHead.next;
    }
};
// @lc code=end

