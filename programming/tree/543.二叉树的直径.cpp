/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        // 仅仅多这一行，相比于求解树的深度
        res = max(res, left + right);
        // 以当前节点为根节点树的深度
        return max(left, right) + 1;
    }
};
// @lc code=end

