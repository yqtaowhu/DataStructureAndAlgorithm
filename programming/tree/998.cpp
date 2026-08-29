class Solution {
private:
    string minPath = "";
    void cmpPath(TreeNode* root, string path) {
        if (!root) return;
        path = char(root->val + 'a') + path;
        if (!root->left && !root->right) {
            if (minPath.empty() || minPath > path) {
                minPath = path;
            }
        }
        cmpPath(root->left, path);
        cmpPath(root->right, path);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        cmpPath(root, "");
        return minPath;
    }
};