class Solution {
public:

    bool evaluateTree(TreeNode* root) {
        if(!root) return true;
        // 叶子结点
        if(!root->left) return root->val;
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        if(root->val == 2) {
            return l | r;
        } else {
            return l & r;
        }
        
    }
};