/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
	bool isSymmetric(TreeNode *p, TreeNode *q) {
        if(!p || !q) {
            return p == q;
        }

		return (p->val == q->val) && isSymmetric(p->left, q->right) && 
            isSymmetric(p->right, q->left);
	}
	bool isSymmetric(TreeNode* root) {
		return isSymmetric(root, root);
	}
};
// @lc code=end

