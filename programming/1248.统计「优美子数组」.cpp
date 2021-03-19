/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
class Solution {
public:
    // [2,2,2,1,2,2,1,2,2,2]
    // 将奇数存储起来   3 6
    // 分别统计其左边和右边的奇数m,n -> (m+1)*(n+1)
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>index;
        for(int i = 0; i < n; i ++){
            //存奇数数字的下标
            if(nums[i] % 2)
                index.push_back(i);

        }
        if(index.size() < k) return 0;
        if(index.size() == k) return (index[0] + 1)*(n - index[k - 1]);
        int number = 0;
        for(int i = 0; i <= index.size() - k; i ++){
            if(i == 0) number += (index[0] + 1)*(index[k] - index[k - 1]);
            else if(i == index.size() - k) {
                number += (index[i] - index[i - 1])*(n - index[i + k - 1]);
            } else
                number += (index[i] - index[i - 1])*(index[i + k] - index[i + k - 1]);
        }
        return number;
    }
};
// @lc code=end

