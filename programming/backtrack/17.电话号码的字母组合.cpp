class Solution {
public:
    const string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    void dfs(string digits, string &tmp, int i) {
        if(i == digits.size()) {
            res.push_back(tmp);
            return;
        }
        //for(int i=beg;i < MAPPING[digits[i]].size(); i++) {
        for (auto c : MAPPING[digits[i] - '0']) {
            //cout << "1: " << c << endl;
            tmp.push_back(c);
            dfs(digits, tmp, i+1);
            tmp.pop_back();
            // if (!tmp.empty()) {
            //     cout << "2: " << tmp[tmp.size()-1] << endl;
            // }
            
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        string tmp;
        dfs(digits, tmp, 0);
        return res;
        
    }
};