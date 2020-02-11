/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void dfs(vector<vector<int> > &res, vector<int>& path, int exp, TreeNode* root) {
        if(!root) {
            return;
        }
        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && root->val == exp) {
            res.push_back(path);
        }

        dfs(res, path, exp-root->val, root->left);
        dfs(res, path, exp-root->val, root->right);
        
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(res, path, sum, root);
        return res;
    }
};
// @lc code=end

