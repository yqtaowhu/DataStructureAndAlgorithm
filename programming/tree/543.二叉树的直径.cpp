/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int res = 0;
    // 遍历树的深度的时候，附带计算res即可
    int depth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = depth(root->left);
        int right = depth(root->right);
        res = max(res, left + right);  // 顺便记录, 因为每一个节点都会遍历到，所以可以顺便更新res的值
        return max(left, right) + 1;   // 返回的是树的深度

    }
    int diameterOfBinaryTree(TreeNode* root) {
        // 4->3 --->    1->2->4 + 1->3
        depth(root);
        return res;
    }

    // 迭代的方法
    int depth(TreeNode* root) {
        return root ? max(depth(root->left), depth(root->right)) + 1 : 0;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode*> st;
        int res = 0;
        while(!st.empty() || root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            int left = depth(root->left);
            int right = depth(root->right);
            //cout << root->val << " " << left << " " << right << endl;
            res = max(left + right, res);
            root = root->right;
        }
        return res;
    }
};
// @lc code=end

