class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* root, int min_v, int max_v) {
        if(!root) return;
        int x = abs(min_v-root->val);
        int y = abs(max_v-root->val);
        ans = max(ans, max(x, y));
        min_v = min(min_v, root->val);
        max_v = max(max_v, root->val);

        dfs(root->left, min_v, max_v);
        dfs(root->right, min_v, max_v);
    } 
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        dfs(root, root->val, root->val);
        return ans;
        
    }
};