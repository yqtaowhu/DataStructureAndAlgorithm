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
	    stack<TreeNode*>st;
        long long pre = LONG_LONG_MIN;
        while (root || st.size()>0) {
		    if (root) {
			    st.push(root);
			    root = root->left;
		    }   
		    else {
				root = st.top();
				st.pop();
				
                if(root->val <= pre) {
                    return false;
                }
                pre = root->val;

				root = root->right;
			}
		}
        return true;
}
};
// @lc code=end

