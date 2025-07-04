class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int size = arr.size();
        if (size < k) return 0;
        threshold = threshold * k;
        int res = 0, sum = 0;
        // 初始化窗口
        for(int i=0; i < k-1; i++) {
            sum += arr[i];
        }
        for(int i=k-1; i < size; i++) {
            // insert
            sum += arr[i];
            // update
            if(sum >= threshold) {
                res += 1;
            }
            // delete
            sum -= arr[i-k+1];
        }
        return res;
    }
};