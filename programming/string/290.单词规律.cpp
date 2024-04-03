using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include<sstream>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 1. 熟悉stringstream用法
    // 2. 双射关系
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string t;
        vector<string> v;
        while(ss >> t) {
            v.push_back(t);
        }
        int m = pattern.size(), n = v.size();
        if(m!=n) return false;
        unordered_map<char, string> c2str;
        unordered_map<string, char> str2c;
        // a -> dog , b -> dog 避免这种情况
        for(int i=0; i < m; i++) {
            char c = pattern[i];
            if(c2str.count(c) && c2str[c] != v[i]) {
                return false;
            }
            if(str2c.count(v[i]) && str2c[v[i]] != c) {
                return false;
            }
            c2str[pattern[i]] = v[i];
            str2c[v[i]] = c;
        }
        return true;
    }
};