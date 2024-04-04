/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   222.完全二叉树的节点个数.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:38:16 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/04 19:38:17 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class Solution {
public:
    int depth(TreeNode *root) {
        return root ? depth(root->left) + 1: 0;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left == right) {
            // 左子树是满二叉树
            return countNodes(root->right) + (1 << left);
        } else {
            // 右子树满二叉树
            return countNodes(root->left) + (1 << right);
        }
    }
    // int countNodes(TreeNode* root) {
    //     if(!root) return 0;
    //     int left = 0, right = 0;
    //     left = countNodes(root->left);
    //     right = countNodes(root->right);
    //     return left + right + 1;

    // }
};