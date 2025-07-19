class Solution {
public:
    // 判断是不是回文，奇数的个数即可
    int res = 0;
    unordered_map<int ,int> map;
    void dfs(TreeNode* root, int odd_num) {
        if(!root) return;
        
        // 修改状态
        map[root->val]++;
        if(map[root->val] % 2 == 1) odd_num++;
        else odd_num--;
        
        // 叶子节点判断
        if(!root->left && !root->right && odd_num <= 1) {
            res++;
        }
        
        // 递归子节点
        dfs(root->left, odd_num);
        dfs(root->right, odd_num);
        
        // 回溯状态
        if(map[root->val] % 2 == 1) odd_num--;  // 先调整odd_num
        else odd_num++;
        map[root->val]--;  // 再恢复map
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};