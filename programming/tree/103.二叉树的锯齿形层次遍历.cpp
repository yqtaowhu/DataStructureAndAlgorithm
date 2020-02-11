/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        int leftToright = 1;
        while(!que.empty()) {
            int size = que.size();
            vector<int> v(size,0);
            for(int i=0; i<size; i++) {
                root = que.front();
                que.pop();

                if(leftToright) {
                    v[i] = root->val;
                } else {
                    v[size-i-1] = root->val;
                }

                if(root->left) {
                    que.push(root->left);
                } 
                if(root->right) {
                    que.push(root->right);
                }
            }
            leftToright = !leftToright;
            res.push_back(v);
        }
        return res; 
    }
};
// @lc code=end

