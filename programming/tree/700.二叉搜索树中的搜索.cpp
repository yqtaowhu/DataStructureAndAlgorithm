/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    // 迭代，非常简单，找到值，相等的返回即可
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && root->val != val) {
            root = (root->val < val) ? root->right: root->left;
        }
        return root;    
    }
    // 迭代
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if(root == NULL) return NULL;
    //     if(root->val == val) {
    //         return root;
    //     } else if(root->val > val) {
    //         return searchBST(root->left, val);
    //     } else {
    //         return searchBST(root->right, val);
    //     }
    // }
};
// @lc code=end

