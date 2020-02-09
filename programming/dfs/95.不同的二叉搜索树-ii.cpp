/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<TreeNode*> generateTrees(int n) {
	
	vector<TreeNode*> v;
	if (n==0) return v;  //i find add this can ac ,if do not add it is return wrong.
	v = generateTrees(1, n);  
	return v;
}

vector<TreeNode*> generateTrees(int low, int high) {
	vector<TreeNode*> v;
	if (low > high || low <= 0 || high <= 0) {
		v.push_back(NULL);
		return v;
	}
	if (low == high) {
		TreeNode* node = new TreeNode(low);
		v.push_back(node);
		return v;
	}
	//the i is root,and construct the left subtree and right subtree.
	for (int i = low; i <= high; i++) {
		vector<TreeNode*> vleft = generateTrees(low, i - 1);
		vector<TreeNode*> vright = generateTrees(i + 1, high);
		for (int l = 0; l<vleft.size(); l++) {
			for (int r = 0; r<vright.size(); r++) {
				TreeNode *root = new TreeNode(i);
				root->left = vleft[l];
				root->right = vright[r];
				v.push_back(root);
			}
		}
	}
	return v;
}
};
// @lc code=end

