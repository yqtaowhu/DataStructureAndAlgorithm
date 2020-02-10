/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode *pre = new TreeNode(INT_MIN);
    TreeNode *first = nullptr, *second = nullptr;

    void dfs(TreeNode* root) {
        // 中序遍历
        if(!root) {
            return;
        }
        dfs(root->left);

        if(first == nullptr && pre->val > root->val) {
            first = pre;
        }
        if(first && pre->val > root->val) {
            second = root;
        }

        pre = root;

        dfs(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};
// @lc code=end

