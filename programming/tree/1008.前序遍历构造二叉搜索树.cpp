/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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

// 区间上界法：前序首元素为根，用 upper 约束递归边界
// 左子树上界 = 根值，右子树上界 = 父节点上界
// 每个元素只访问一次，时间 O(n)
class Solution {
public:
    int idx = 0;

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int upper) {
        if (idx >= (int)preorder.size() || preorder[idx] > upper)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left  = build(preorder, root->val);   // 左子树上界 = 当前根值
        root->right = build(preorder, upper);        // 右子树上界 = 父节点传下来的上界
        return root;
    }
};
// @lc code=end
