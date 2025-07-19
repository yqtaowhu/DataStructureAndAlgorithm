class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int x) {
        if(!root) return;
        if(root->val >= x) {
            ans += 1;
        }
        x = max(x, root->val);
        dfs(root->left, x);
        dfs(root->right, x);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root, root->val);
        return ans;
    }
};