/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
class Solution {
public:
    /*
    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]
    */
    TreeNode* help(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj) {
        if(i>j || ii>jj) return nullptr;
        TreeNode* root = new TreeNode(preorder[i]); // 前序第一个元素就是根节点
        // 在中序遍历找到根节点的位置
        int index = 0;
        for(index = 0; index <= jj; index++) {
            if(inorder[index] == preorder[i]) {
                break;
            }
        }
        int dis = index - ii; //左子树的个数
        root->left = help(preorder, i+1, i+dis, inorder, ii, ii+dis-1);
        root->right = help(preorder, i+dis+1, j, inorder, ii+dis+1, jj);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return help(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
// @lc code=end

