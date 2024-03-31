// 中序遍历即可
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        int last = -1e5, res = INT_MAX;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res = min(res, root->val - last);
            last = root->val;
            root = root->right;
        }
        return res;
    }
};