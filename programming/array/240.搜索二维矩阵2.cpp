class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while(i < m && j >=0) {
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};