/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   字符串压缩.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:32:23 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/25 20:32:41 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://leetcode.cn/problems/compress-string-lcci/solutions/?envType=study-plan-v2&envId=cracking-the-coding-interview
class Solution {
public:
    string compressString(string S) {
        int m = S.size();
        if(m <= 1) return S;
        string res = "";
        for(int i=0; i < m;) {
            int j = i + 1;
            if(S[j] == S[i]) {
                while(j < m && S[j] == S[i]) {
                    j++;
                }
                res += S[i] + to_string(j-i);
                //cout << j << " " << res << endl;
            } else {
                res += S[i] + to_string(1);
            }
            i = j;
        }
        return res.size() < m ? res : S;
    }
};