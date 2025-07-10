/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 注意了，此题不能广搜，会很复杂
class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int sum) {
        if(!root) {
            return;
        }
        sum = 10*sum + root->val;
        if(!root->left && !root->right) {
            res += sum;
        }

        dfs(root->left, sum);
        dfs(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
// @lc code=end

