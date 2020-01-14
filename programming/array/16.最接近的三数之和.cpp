/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());//首先进行排序
        int n = nums.size();
        int distance = INT_MAX;
        int result;
        for (int i = 0; i < n - 2; i++)// 因为三个数，所以第一个数最大只能为len-3
        {
            //去掉重复值,这里一定要注意，i如果与前一个i所在值相同，则
            //不必计算了，直接另i++
            //不能写成nums[i]==nums[i+1]

            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int a = nums[i];
            int low = i + 1;
            int high = n - 1;
            while (low < high)
            {
                int b = nums[low];
                int c = nums[high];
                int sum = a + b + c;
                if (sum - target == 0)//即两者相等
                    return target;
                else
                {//主要语句，此主要是找到最小的distance
                    if (abs(sum - target) < distance)
                    {
                        distance = abs(sum - target);
                        result = sum;
                    }
                    if (sum - target > 0)
                    {
                        while (high < low&&nums[high] == nums[high - 1])
                            high--;
                        high--;
                    }
                    else 
                    {
                        while (low < high&&nums[low] == nums[low + 1])
                            low++;
                        low++;
                    }
                }

            }
        }
        return result;
 
    }
};
// @lc code=end

