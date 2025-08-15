/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   三步问题.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:57:57 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/28 20:58:02 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    int waysToStep(int n) {
        long long int a = 1, b = 2, c = 4;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        for(int i=4; i<=n; i++) {
            int tmp = c;
            c = (c + b + a) % 1000000007;
            a = b;
            b = tmp;
            //cout << c << endl;
        }
        return c;
    }
};