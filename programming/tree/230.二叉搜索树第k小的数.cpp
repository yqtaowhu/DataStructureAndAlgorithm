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

// 同98题，验证是不是二叉搜索树
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历有序
        stack<TreeNode*> st;
		// 注意了，必须是LLONG_MIN
        int index = 0;
        while(!st.empty() || root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            index++;
            if(index == k) return root->val;
            root = root->right;
        }
        return -1;
    }
};