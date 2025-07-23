

// 最基础的做法
class Solution {
public:
    int res = 0;

    int help(vector<int>& nums) {
        int ans = 0;
        for(auto x: nums) {
            ans = ans ^ x;
        }
        return ans;
    }

    void backtrace(vector<int>& nums, vector<int>& tmp, int beg) {
        res += help(tmp);
        for(int i=beg; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrace(nums, tmp, i+1);
            tmp.pop_back();
        }
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> tmp;
        backtrace(nums, tmp, 0);
        return res;
        
    }
};