class Solution {
public:
    //数字字符串加法模板
    string add(string &s1, string &s2){
        int n1 = s1.size() - 1;//s1的最低位下标
        int n2 = s2.size() - 1;//s2的最低位下标
        int carry = 0;
        string ans;

        while(n1 >= 0 || n2 >= 0 || carry > 0){
            int t1 = n1 >= 0 ? s1[n1--] - '0' : 0;
            int t2 = n2 >= 0 ? s2[n2--] - '0' : 0;
            ans += (t1 + t2 + carry) % 10 + '0';//最低位放在最前面
            carry = (t1 + t2 + carry) / 10;//进位：逢10进1
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    //num1:[i, j) + num2:[j, k) = sum:[k···)
    bool isValid(string &num, int i, int j, int k){
        //以0开头的且不为0数字字符串不能作为数字
        if (num[i] == '0' && j != i + 1) return false;
        if (num[j] == '0' && k != j + 1) return false;

        string num1 = num.substr(i, j - i);
        string num2 = num.substr(j, k - j);

        string sum = add(num1, num2);
        //前面两数之和大于剩余数字字符的位数
        if (sum.size() + k > num.size()) return false;

        //后面的数字字符串从k开始遍历
        for (int s = k; s <= k - 1 + sum.size(); s++) {
            //逐位对比
            if (num[s] != sum[s - k]) return false;
        }
        //如果剩余的数字字符串正好匹配完就返回true
        if (sum.size() + k == num.size()) return true;
        
        //num2变为num1， sum变为num2 继续递归判断
        return isValid(num, j, k, sum.size() + k);
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isValid(num, 0, i, j)) return true;
            }
        }
        return false;
    }
};



class Solution {
public:


    bool judge(int j, int k, string num) {
        if (num[0] == '0' && j > 1) return false;
        if (num[j] == '0' && k > j + 1) return false;

        long long first = stoll(num.substr(0, j));
        long long second = stoll(num.substr(j, k - j));
        int next = k;

        while (next < num.size()) {
            long long third = first + second;
            first = second;
            second = third;
            string temp = to_string(third);

            for (int i = 0; i < temp.size(); i++) {
                if (next >= num.size() || num[next] != temp[i]) {
                    return false;
                }
                next++;
            }
        }
        return true;
    }

    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;

        for (int i = 1; i <= num.size() / 2; i++) {
            for (int j = i + 1; num.size() - j >= max(i, j - i); j++) {
                if (judge(i, j, num)) return true;
            }
        }
        return false;
    }
};