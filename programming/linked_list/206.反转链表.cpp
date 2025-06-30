/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   206.反转链表.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:10:42 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/06/30 11:55:50 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

// 以下两种方法必须熟练掌握
class Solution {
public:
    // 递归方法
    ListNode* dfs(ListNode* head, ListNode* prev=nullptr) {
        if(!head) {
            // 一定要注意呀
            return prev;
        }
        ListNode* nxt = head->next;
        head->next = prev;
        return dfs(nxt, head);
    }
    ListNode* reverseList(ListNode* head) {
        //return dfs(head, nullptr); // 递归方法
        // 迭代方法, 四行切记
        ListNode* prev = nullptr, *nxt;
        while(head) {
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};

// @lc code=end

