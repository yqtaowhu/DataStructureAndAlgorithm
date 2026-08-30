



class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size(), n = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(m, 0);
        for(int i=0; i < m; i++) {
            //int left = 0, right = n;
            int s = spells[i];
            // 7 5 ->  2
            long long need = (success + s - 1) / s;   // ceil(success / s)
            int left = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            // while(left < right) {
            //     int mid = left + (right-left)/2;
            //     if(1LL * potions[mid] * s >= success) {
            //         right = mid;
            //     } else {
            //         left = mid + 1;
            //     }
            // }
            res[i] = n - left;
        }
        return res;
    }
};