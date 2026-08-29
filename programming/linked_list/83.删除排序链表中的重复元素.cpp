/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   83.删除排序链表中的重复元素.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:29:20 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/28 15:29:21 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        
        ListNode* cur = head;
        while(cur->next) {
            if(cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;  // 释放被删除节点的内存
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 1 1 2 2 3
        if(!head || !head->next) return head;
        ListNode *cur = head;
        while(cur && cur->next) {
            ListNode *nxt = cur->next;
            while(nxt && nxt->val == cur->val) {
                nxt = nxt->next;
            }
            cur->next = nxt;
            cur = nxt;
        }
        return head;
        
    }
};