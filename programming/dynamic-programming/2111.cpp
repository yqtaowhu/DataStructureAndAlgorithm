class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        if(k > n) return 0;
        int ans = 0;
        vector<int> g;
        for(int i=0; i < k; i++) {
            g.clear();
            int length = 0;
            for(int j=i; j < n; j+=k) {
                length++;
                auto it = upper_bound(g.begin(), g.end(), arr[j]);
                if(it == g.end()) {
                    g.push_back(arr[j]);
                } else {
                    *it = arr[j];
                }
            }
            ans += length - g.size(); 
        }
        return ans;
    }
};