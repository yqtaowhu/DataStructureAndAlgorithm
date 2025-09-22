
// 普通方法就是直接遍历
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int res = 0, size = nums.size();
        int tmp = 0;
        for(int i=0; i < size; i++) {
            for(int j=i; j < size; j++) {
                tmp += nums[j];
                if(tmp == k) {
                    res++;
                }
            }
            tmp = 0;
        }
        return res;
    }

    int subarraySum(vector<int>& nums, int k) {
        // 子数组想到前缀和
        //  1,1,−1,1,−1，k=1
        // 0,1,2,1,2,1      也就是找s[j] - s[i] = k(i<j)的个数
        // 如果遍历还是o(n2), 使用hash表，  s[i] = s[j] - k, 遍历j时，看有多少个s[j] - k
        int n = nums.size(), res = 0;

        vector<int>  ps(n+1, 0);
        for(int i=0; i < n; i++) {
            ps[i+1] = ps[i] + nums[i];
        }
        unordered_map<int, int> map{{0, 1}};  // 0出现1次
        // 这里遍历的是前缀和
        for(int i=1; i < n+1; i++) {
            res += map.count(ps[i] - k) ? map[ps[i] - k] : 0;
            map[ps[i]]++;
        }
        return res;
    }
    // 一边计算前缀和一边计算
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, s = 0;
        unordered_map<int, int> cnt{{0, 1}}; // s[0]=0 单独统计
        for (int x : nums) {
            s += x;
            // 注意不要直接 += cnt[s-k]，如果 s-k 不存在，这会插入 s-k，消耗更多空间
            ans += cnt.contains(s - k) ? cnt[s - k] : 0;
            cnt[s]++;
        }
        return ans;
    }
};