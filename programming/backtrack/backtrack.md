- [回溯相关算法练习](#回溯相关算法练习)
  - [1.全排列](#1全排列)
  - [2.全排列](#2全排列)

# 回溯相关算法练习

## [1.全排列](https://leetcode-cn.com/problems/permutations/)
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
经典的回溯算法，标准的模板，一定要切记了
```
class Solution {
public:
    void help(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, vector<int>& vis) {
        if(tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i=0; i < nums.size(); i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                tmp.push_back(nums[i]);
                help(res, nums, tmp, vis);
                tmp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> vis(nums.size(), 0);
        help(res, nums, tmp, vis);
        return res;
    }
};
```

## [2.全排列](https://leetcode-cn.com/problems/permutations-ii/)
注意剪枝！！！！
参考: https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/
```
class Solution {
public:
    void help(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, vector<int>& vis) {
        if(tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i=0; i < nums.size(); i++) {
            // 当前和前一个相同，并且前一个还没有使用， 剪枝
            if(i > 0 && nums[i] == nums[i-1] && vis[i-1] == 0) {
                continue;
            }
            if(vis[i] == 0) {
                vis[i] = 1;
                tmp.push_back(nums[i]);
                help(res, nums, tmp, vis);
                tmp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> vis(nums.size(), 0);
        help(res, nums, tmp, vis);
        return res;
    }
};
```