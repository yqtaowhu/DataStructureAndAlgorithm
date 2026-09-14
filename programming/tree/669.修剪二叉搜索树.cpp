/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// BST 模板 6：值域递归剪枝
// val < low → 自身和左子树都丢弃，返回修剪后的右子树
// val > high → 自身和右子树都丢弃，返回修剪后的左子树
// 在范围内 → 递归修剪左右子树，保留当前节点
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left  = trimBST(root->left,  low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @lc code=end
