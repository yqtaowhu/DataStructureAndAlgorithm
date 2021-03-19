/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if(!s || !t) return s == t;
        return s->val == t->val && isSameTree(s->left, t->left) && 
            isSameTree(s->right, t->right);
    }

    bool dfs(TreeNode* s, TreeNode* t) {
        if (!s)
            return false;
        return isSameTree(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }
};
// @lc code=end

