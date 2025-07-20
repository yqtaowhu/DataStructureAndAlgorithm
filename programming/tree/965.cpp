class Solution {
public:
    bool dfs(TreeNode* root, int target) {
        if(!root) return true;
        if(root->val != target) return false;
        return dfs(root->left, target) && dfs(root->right, target);

    }

    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        return dfs(root, root->val);    
    }
};