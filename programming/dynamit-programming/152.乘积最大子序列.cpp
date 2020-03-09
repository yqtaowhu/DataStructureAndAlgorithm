/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return -1;
        int len = nums.size();
        int res = nums[0];
        for(int i=0; i < len; i++) {
            int prob = nums[i];
            res = max(res, prob);           //当前一个数
            for(int j=i+1; j < len; j++) {  // 当前数开头的连乘
                prob *= nums[j];
                res = max(res, prob);
            }
        }
        return res;
    }
};
// 动态规划的方法
// https://leetcode-cn.com/problems/maximum-product-subarray/solution/dpfang-fa-xiang-jie-by-yang-cong-12/
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        } else if(n == 1) {
            return nums[0];
        }
        int p = nums[0];
        int maxP = nums[0];
        int minP = nums[0];
        for(int i = 1; i < n; i++) {
            int t = maxP;
            maxP = max(max(maxP * nums[i], nums[i]), minP *nums[i]);
            minP = min(min(t * nums[i], nums[i]), minP * nums[i]);
            p = max(maxP, p);
        }
        return p;
    }
};
*/
// @lc code=end

