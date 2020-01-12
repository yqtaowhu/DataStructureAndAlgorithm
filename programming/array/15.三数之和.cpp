/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 最低复杂度o(n2), 排序+双指针
    // 不排序+哈希表也可以
    vector<vector<int>> threeSum(vector<int>&nums)
{
    vector<vector<int>> result;//返回二维数组
    sort(nums.begin(), nums.end());//首先进行排序
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)// 因为三个数，所以第一个数最大只能为len-3
    {
        //去掉重复值,这里一定要注意，i如果与前一个i所在值相同，则
        //不必计算了，直接另i++
        //不能写成nums[i]==nums[i+1]
        if (i > 0 && nums[i-1] == nums[i])
            continue;
        int a = nums[i];
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int b = nums[low];
            int c = nums[high];
            if (a+b+c==0)//满足条件，将其加入数组中
            {
                vector<int>v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                //继续寻找下一个满足条件的值，去重值
                while (low < high&&nums[low] == nums[low + 1]) low++;
                low++;
                while (high > low&&nums[high] == nums[high - 1]) high--;
                high--;
            }
            else if (a + b + c>0)
            {
                while (high > low&&nums[high] == nums[high - 1])
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
    return result;
}
};
// @lc code=end

