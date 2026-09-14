/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
class Solution {
public:
    // 找到以 node 为根的子树中的最小节点（一路向左）
    TreeNode* getMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;                 // 没找到，返回空
        if (root->val == key) {
            // 情况 1：叶子或只有一个孩子 —— 用那个孩子（可能为空）直接顶替自己
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            // 情况 2：左右孩子都在 —— 用右子树的最小节点（中序后继）替换当前节点
            TreeNode* minNode = getMin(root->right);
            // 先在右子树里把后继删掉，再把 root 的左右子树接到后继上
            root->right = deleteNode(root->right, minNode->val);
            minNode->left  = root->left;
            minNode->right = root->right;
            return minNode;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);   // 目标在右子树
        } else {
            root->left = deleteNode(root->left, key);     // 目标在左子树
        }
        return root;
    }
};
// @lc code=end
