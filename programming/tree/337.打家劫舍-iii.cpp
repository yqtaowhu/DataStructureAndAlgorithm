/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    // 树形 DP：每个节点向上返回一个状态对 {偷当前节点的最大金额, 不偷当前节点的最大金额}
    // 用一个返回值不够（父节点的决策依赖子节点「偷 / 不偷」两种状态），所以返回 pair 一次性带上来
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};                 // 终止条件：空节点两种状态都是 0
        pair<int, int> left  = dfs(root->left);   // 信任递归：左右子树的状态对
        pair<int, int> right = dfs(root->right);

        // 偷当前节点：左右孩子都不能偷，只能取它们「不偷」的状态
        int rob    = root->val + left.second + right.second;
        // 不偷当前节点：左右孩子偷不偷都行，各自取两种状态的较大值
        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, notRob};
    }

    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);        // 根节点偷 / 不偷取较大值
    }
};
// @lc code=end
