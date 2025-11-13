/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   65.有效数字.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:33:01 by taoyanqi          #+#    #+#             */
/*   Updated: 2025/11/13 17:33:02 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), i = 0, digits = 0, dots = 0;
        // 1. 去掉前导空格
        for (; i < n && isspace(s[i]); i++);
        // 2. 如果有符号，去掉
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        // 3. 接下来是.和数字都可以，统计点和数字的个数
        for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++) {
            isdigit(s[i]) ? digits++ : dots++;
        }
        // 没有数字或者.大于1个，则是错误的
        if (!digits || dots > 1) {
            return false;
        }
        // 4. 对e进行特殊处理
        if (s[i] == 'e' || s[i] == 'E') {
            i++;
            // 去掉符号
            if (s[i] == '+' || s[i] == '-') {
                i++;
            }
            digits = 0;
            for (; i < n && isdigit(s[i]); i++) {
                digits++;
            }
            // e后面必须加数字
            if (!digits) {
                return false;
            }
        }
        // 5. 去掉末尾空格
        for (; i < n && isspace(s[i]); i++);
        return i == n;
    }
};