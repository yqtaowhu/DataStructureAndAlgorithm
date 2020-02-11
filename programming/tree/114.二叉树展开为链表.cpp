/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    /*
        1.将左子树插入到右子树的地方
        2.将原来的右子树接到左子树的最右边节点
        3.考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null
    */
    void flatten(TreeNode* root) {
        while(root) {
            // 找到左子树的最右节点
            if(root->left == nullptr) {
                root = root->right;
            } else {
                // 找到左子树的最右节点
                TreeNode* pre = root->left;
                while(pre->right) {
                    pre = pre->right;
                }
                // 原先的右子树加到左子树的最右节点
                pre->right = root->right;
                // 左子树变成当前节点的右子树
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};
// @lc code=end

