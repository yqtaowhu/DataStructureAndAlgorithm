/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   104.二叉树的最大深度.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:35:16 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/07/18 18:36:30 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 自底向上
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        return max(l_depth, r_depth) + 1;
    }
};


// 自顶向下

class Solution {
public:
    void dfs (TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }
        depth++;
        ans = max(ans, depth);
        dfs(node->left, depth);
        dfs(node->right, depth);
    };

    int ans = 0;
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end

