/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    // BFS 分层 + 满二叉树编号：给每个节点标号 idx，左孩子 2*idx，右孩子 2*idx+1
    // 某一层的宽度 = 该层最右编号 - 最左编号 + 1（中间的 null 不影响编号）
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;   // 用 unsigned long long 防编号溢出
        q.push(make_pair(root, 0));
        unsigned long long maxWidth = 0;
        while (!q.empty()) {
            int size = q.size();
            unsigned long long offset = q.front().second;   // 本层起始编号，做归一化防止指数级膨胀
            unsigned long long first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                unsigned long long cur = q.front().second - offset;   // 相对本层起点的编号
                q.pop();
                if (i == 0) first = cur;
                if (i == size - 1) last = cur;
                if (node->left)  q.push(make_pair(node->left,  cur * 2));
                if (node->right) q.push(make_pair(node->right, cur * 2 + 1));
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return (int)maxWidth;
    }
};
// @lc code=end
