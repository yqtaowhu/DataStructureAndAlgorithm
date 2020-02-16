/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-de-zui-da-lu-jing-he-by-leetcode/
class Solution {
public:
    int max_sum = INT_MIN;
    int max_gain(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left_gain = max(max_gain(root->left), 0);
        int right_gain = max(max_gain(root->right), 0);
        int sum = root->val + left_gain + right_gain;
        max_sum = max(max_sum, sum);

        //维护以前的路径
        return root->val + max(left_gain, right_gain);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};
// @lc code=end

