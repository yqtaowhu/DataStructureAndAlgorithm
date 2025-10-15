/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int size=nums.size();
        for(int a=0;a<size-3;++a)
        {
            if(a>0&&nums[a]==nums[a-1])continue;
            for(int b=a+1;b<size-2;++b)//以下代码与三数之和一样的
            {
                if(b>a+1&&nums[b]==nums[b-1])continue;
                int i=b+1,j=size-1;
                while(i<j)
                {
                    int sum=nums[a]+nums[b]+nums[i]+nums[j];
                    if(sum<target)
                        while(i<j&&nums[i]==nums[++i]);
                    else if(sum>target)
                        while(i<j&&nums[j]==nums[--j]);
                    else{
                        result.push_back(vector<int>{nums[a],nums[b],nums[i],nums[j]});
                        while(i<j&&nums[i]==nums[++i]);
                        while(i<j&&nums[j]==nums[--j]);
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

