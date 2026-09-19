/*
 * @lc app=leetcode.cn id=3936 lang=cpp
 * @lcpr version=30204
 *
 * [3936] 将 0 移到末尾的最少交换次数
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size(), cnt=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                cnt++;
            }
        }
        //cout<<cnt<<endl;
        int j = n-cnt;
        for(int i=n-1;i>=j;i--) {
            //cout<<i<<" "<<nums[i]<<endl;
            if(nums[i]==0) {
                cnt--;
            }
        }
        return  cnt;
        
    }
};


class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int ans = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] != 0) {
                l++;
            } else if (nums[r] == 0) {
                r--;
            } else {
                // 交换 nums[l] 和 nums[r]
                ans++;
                l++;
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

 */

