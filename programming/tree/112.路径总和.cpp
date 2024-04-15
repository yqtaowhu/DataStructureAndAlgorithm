/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   112.路径总和.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:17:35 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/15 21:18:20 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution {
public:
    // bfs, 第一反应就是bfs，切记了
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            for(int i=0; i < size; i++) {
                root = que.front();
                que.pop();
                if(root->left) {
                    root->left->val += root->val;
                    que.push(root->left);
                }
                if(root->right) {
                    root->right->val += root->val;
                    que.push(root->right);
                }
                if(!root->left && !root->right && root->val == targetSum) {
                    return true;
                }
            }
        }
        return false;
    }
    // dfs
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
// @lc code=end

