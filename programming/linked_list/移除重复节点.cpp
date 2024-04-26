/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   移除重复节点.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:42:44 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/26 20:42:45 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head || !head->next) return head;
        unordered_set<int> s;
        s.insert(head->val);
        ListNode *cur = head->next, *pre=head;
        while(cur) {
            if(!s.count(cur->val)) {
                s.insert(cur->val);
                pre->next = cur;
                pre = cur;
            } 
            cur = cur->next;
        }
        pre->next = nullptr;
        return head;
    }
};