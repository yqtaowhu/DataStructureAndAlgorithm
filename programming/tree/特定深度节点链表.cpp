/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   特定深度节点链表.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:00:22 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/09 21:00:34 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://leetcode.cn/problems/list-of-depth-lcci/description/?envType=study-plan-v2&envId=cracking-the-coding-interview
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> res;
        if(!tree) return res;
        queue<TreeNode*> que;
        que.push(tree);
        while(!que.empty()) {
            int size = que.size();
            ListNode preHead(0), *pre = &preHead;
            for(int i=0; i < size; i++) {
                tree = que.front();
                que.pop();
                if(tree->left) {
                    que.push(tree->left);
                }
                if(tree->right) {
                    que.push(tree->right);
                }
                ListNode *ln = new ListNode(tree->val);
                pre->next = ln;
                pre = ln;
            }
            res.push_back(preHead.next);
        }
        return res;

    }
};
