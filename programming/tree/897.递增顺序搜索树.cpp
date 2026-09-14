/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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

// BST 模板 5：中序有序性 —— 中序遍历过程中用 prev 串成只有右孩子的链
class Solution {
public:
    TreeNode* prev = nullptr;

    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* dummy = new TreeNode(0);  // 哨兵节点，简化头部处理
        prev = dummy;
        inorder(root);
        return dummy->right;
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        prev->right = root;     // 前驱的右指针指向当前节点
        root->left = nullptr;   // 断开左指针，形成右斜链
        prev = root;
        inorder(root->right);
    }
};
// @lc code=end
