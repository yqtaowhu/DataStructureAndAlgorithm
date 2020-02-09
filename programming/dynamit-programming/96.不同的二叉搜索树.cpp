/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    //https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode/
	vector<int> cnts(n + 1, 0);
		cnts[0] = cnts[1] = 1;
		for (int i = 2;i <= n;i++)
			for (int j = 1;j <= i;j++) {
				cnts[i] += cnts[j - 1] * cnts[i - j];
			}
		return cnts[n];}
};
// @lc code=end

