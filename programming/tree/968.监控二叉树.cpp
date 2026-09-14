/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int cameras = 0;

    // 后序贪心：从叶子往上，尽量把相机放在「父节点」上以覆盖更多节点
    // 每个节点返回其状态：0 = 未覆盖, 1 = 已覆盖(自身无相机), 2 = 自身有相机
    int dfs(TreeNode* root) {
        if (!root) return 1;                      // 空节点视为「已覆盖」，避免在空处浪费相机
        int left  = dfs(root->left);
        int right = dfs(root->right);

        // 只要有一个孩子未被覆盖，当前节点必须装相机
        if (left == 0 || right == 0) {
            cameras++;
            return 2;
        }
        // 有一个孩子装了相机，当前节点被覆盖（自身无需相机）
        if (left == 2 || right == 2) return 1;
        // 两个孩子都已覆盖但都没相机，当前节点无人覆盖，向上交给父节点处理
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        // 后序结束后，若根节点仍未覆盖，需要额外补一个相机
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
};
// @lc code=end
