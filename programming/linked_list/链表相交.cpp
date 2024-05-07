/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   链表相交.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:04:20 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/07 21:04:23 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        while(l1 != l2) {
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        return l1;
    }
};