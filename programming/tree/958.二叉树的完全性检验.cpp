/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode* root) {
        // 层序遍历，空节点之后不能再出现空节点， [1,2,3,4,5,null,7]不是完全二叉树
        queue<TreeNode*> que;
        que.push(root);
        bool end = false;
        while(!que.empty()) {
            root = que.front();
            que.pop();
            if(end && root) {
                return false;
            }
            if(!root) {
                end = true;
                continue;
            }
            que.push(root->left);
            que.push(root->right);
        }
        return true;

    }
};
// @lc code=end

