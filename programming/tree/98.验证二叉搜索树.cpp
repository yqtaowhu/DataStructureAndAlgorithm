/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        // 中序遍历有序
        stack<TreeNode*> st;
		// 注意了，必须是LLONG_MIN
        long long last = LLONG_MIN;
        while(!st.empty() || root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(root->val <= last) {
                return false;
            }
            last = root->val;
            root = root->right;
        }
        return true;
    }
};
// @lc code=end

