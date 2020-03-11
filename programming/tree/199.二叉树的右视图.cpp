/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            for(int i=0; i<size; i++) {
                root = que.front();
                que.pop();
                if(i == size-1) {
                    res.push_back(root->val);
                }
                if(root->left) {
                    que.push(root->left);
                }
                if(root->right) {
                    que.push(root->right);
                }
            }
        }
        return res;
    }
};
// @lc code=end

