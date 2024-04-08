// 滑动窗口

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1) return false;
        unordered_set<int>  hash;
        for(int i=0; i<nums.size(); i++) {
            if(i > k) {
                hash.erase(nums[i-k-1]);
            }
            if(hash.count(nums[i])) {
                return true;
            }
            hash.emplace(nums[i]);
        }
        return false;
    }
};

// 哈希表
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1) return false;
        unordered_map<int, int> hash;
        for(int i=0; i < nums.size(); i++) {
            if(hash.find(nums[i]) != hash.end()) {
                if(i - hash[nums[i]] <= k) {
                    return true;
                }
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};