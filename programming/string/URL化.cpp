/*
URL化。编写一种方法，将字符串中的空格全部替换为%20。
假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。
*/
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int blank = 0;
        for(int i = 0; i < length; i++) {
            if(S[i] == ' ') {
                blank++;
            }
        }
        int end = length + blank * 2;
        int j = 0;
        // a b       %20b
        for(int i = end-1; i >=0; i--) {
            if(S[length-1-j] == ' ') {
                S[i] = '0';
                S[i-1] = '2';
                S[i-2] = '%';
                i= i - 2;
            } else {
                S[i] = S[length-1-j];
            }
            j++;
        }
        return S.substr(0, end);
    }
};