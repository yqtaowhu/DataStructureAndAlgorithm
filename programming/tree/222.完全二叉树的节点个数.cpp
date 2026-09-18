/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
/*
int countNodes(TreeNode* root) {
    return root ? countNodes(root->left) + countNodes(root->right) + 1 : 0;
}
*/

class Solution {
public:
    int height(TreeNode* root) {
        return root == nullptr ? -1 : 1 + height(root->left);
    }

    int countNodes(TreeNode* root) {
        int nodes = 0, h = height(root);
        while (root != nullptr) {
            // 右子树的高度比本身高度少一，说明，右子树最后一层有节点
            // 那么左子树是满二叉树
            if (height(root->right) == h - 1) {
                // 左子树满二叉树，直接计算
                nodes += 1 << h;
                // 计算右子树的个数
                root = root->right;
            } else {
                // 右子树是满二叉树
                nodes += 1 << h-1;
                // 计算左子树
                root = root->left;
            }
            h--;
        }
        return nodes;
    }
};

// @lc code=end

