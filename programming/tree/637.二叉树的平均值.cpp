class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            double cnt = 0;
            for(int i=0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                cnt += cur->val;
                if(cur->left) {
                    que.push(cur->left);
                }
                if(cur->right) {
                    que.push(cur->right);
                }
            }
            res.push_back(cnt / size);
        }
        return res;
    }
};