class Solution {
public:
    // 需要用一个标记vis

    void backtrace(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, 
                   vector<int>& vis) {
        if(tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        // 每次都从0开始，使用标记。。。。。
        for(int i=0; i < nums.size(); i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                tmp.push_back(nums[i]);
                backtrace(nums, res, tmp, vis);
                tmp.pop_back();
                vis[i] = 0;
            }

        }
        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> vis(nums.size(), 0);
        if(nums.empty()) return res;
        int size = nums.size();
        backtrace(nums, res, tmp, vis);
        return res;
    }
};