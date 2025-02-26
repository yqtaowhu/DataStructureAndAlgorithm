class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int size = blocks.size();
        if(size < k) return 0;
        int cnt = 0, res = INT_MAX;
        for(int i=0; i < k-1; i++) {
            if(blocks[i] == 'W') {
                cnt += 1;
            }
        }
        for(int i=k-1; i < size; i++) {
            if(blocks[i] == 'W') {
                cnt += 1;
            }
            res = min(res, cnt);
            if(blocks[i-k+1] == 'W') {
                cnt -= 1;
            }
        }
        return res;
    }
};