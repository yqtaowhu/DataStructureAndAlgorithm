/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    // 广度优先搜索很简单
    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i=0; i < size; i++) {
                root = que.front();
                que.pop();
                if(!root->left && !root->right) {
                    res += root->val;
                }
                if(root->left) {
                    root->left->val += 10*root->val;
                    que.push(root->left);
                }
                if(root->right) {
                    root->right->val += 10*root->val;
                    que.push(root->right);
                }
            }
        }
        return res;
    }
    // 深度优先搜索
    int dfs(TreeNode* root, int prevSum) {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    
};
// @lc code=end

