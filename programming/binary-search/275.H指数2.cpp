class Solution {
public:
    int hIndex(vector<int>& citations) {
        // [0], [100]
        int n = citations.size();
        int left=0, right=n;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(citations[mid] >= n-mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return n-left;
        
    }
};