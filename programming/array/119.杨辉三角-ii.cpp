class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 第i行由第i-1行得到
        // 1 3 3 1 -> 1 4 6 4 1
        vector<int> res(rowIndex+1, 1);
        for(int i=2; i <= rowIndex; i++) {
            vector<int> tmp(i+1, 1);
            for(int j=1; j < i; j++) {
                tmp[j] = res[j-1] + res[j];
            }
            res = tmp;
        }
        return res;
        
    }
};

        
# @lc code=end

