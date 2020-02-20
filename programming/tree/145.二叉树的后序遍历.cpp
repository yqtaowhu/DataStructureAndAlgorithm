/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
     vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            root = st.top();
            st.pop();
            res.push_back(root->val);

            if(root->left) {
                st.push(root->left);
            }
            if(root->right) {
                st.push(root->right);
            }
        }
        reverse(res.begin(), res.end());
        return res; 
    }
};
// @lc code=end

