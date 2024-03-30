#include<string>
using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        // 核心思路，每一个字母都可以固定到一个数字的二进制的位置上
        // 如果当前和新的字母& ！= 0， 则重复了，否则进行或操作
        int res = 0;
        for(auto c: astr) {
            int move_bit = c - 'a';
            int tmp = 1 << move_bit;
            if((res & tmp) != 0) {
                return false;
            } else {
                res = res | tmp;
            }
        }
        return true;
    }
};