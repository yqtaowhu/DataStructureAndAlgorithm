/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。
*/
bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) {
        return false;
    }
    vector<int> res(26, 0);
    for(int i = 0; i < magazine.size(); i++) {
        res[magazine[i] - 'a']++;
    }
    for(int i = 0; i< ransomNote.size(); i++) {
        res[ransomNote[i] - 'a']--;
        if(res[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}