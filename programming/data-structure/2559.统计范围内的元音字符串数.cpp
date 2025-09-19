/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2559.统计范围内的元音字符串数.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:06:17 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/09/19 17:06:18 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> dp(words.size(),0);
        vector<int> res;
        if(isVowe(words[0])) dp[0]=1;
        for(int i=1;i<words.size();i++)
        {
            if(isVowe(words[i])) dp[i]=dp[i-1]+1;
            else dp[i]=dp[i-1]; 
        }
        for(int i=0;i<queries.size();i++)
        {
            int left=queries[i][0],right=queries[i][1];
            if(isVowe(words[left])) res.push_back(dp[right]-dp[left]+1);
            else res.push_back(dp[right]-dp[left]);
        }
        return res;
    }

    bool isVowe(string &str)
    {
        if(dict.count(str[0])&&dict.count(str[str.size()-1]))
            return true;
        return false;
    }
private:
    unordered_set<char> dict={'a','e','i','o','u'};
};