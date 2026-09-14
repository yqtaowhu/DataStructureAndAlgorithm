/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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

// BST 模板 5：中序有序性 —— 相同值在中序序列中一定相邻
// 统计连续相等长度，更新最大频次和结果集
class Solution {
public:
    vector<int> res;
    int maxCount = 0, curCount = 0;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        // 处理当前节点：统计连续相等值的长度
        curCount = (prev && prev->val == root->val) ? curCount + 1 : 1;
        if (curCount == maxCount) {
            res.push_back(root->val);        // 并列众数，追加
        } else if (curCount > maxCount) {
            maxCount = curCount;
            res = {root->val};               // 新的最大频次，重置
        }
        prev = root;
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};
// @lc code=end
