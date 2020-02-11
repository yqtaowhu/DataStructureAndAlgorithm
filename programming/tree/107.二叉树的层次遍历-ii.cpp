/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> v(size,0);
            for(int i=0; i<size; i++) {
                root = que.front();
                que.pop();
                v[i] = root->val;
                if(root->left) {
                    que.push(root->left);
                } 
                if(root->right) {
                    que.push(root->right);
                }
            }
            res.insert(res.begin(), v);
        }
        return res;
    }
};
// @lc code=end

