/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   108.将有序数组转换为二叉搜索树.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:08:11 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/04/16 21:10:54 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    // 此题明显的递归题目: 构建二叉搜索树，数组的[left, right]进行构建
    TreeNode* help(vector<int>& nums, int left, int right) {
        if(left > right) {
            return nullptr;
        }
        int mid = (left + right) >> 1; // 选择左中位数作为根节点
        //cout<<mid<<endl;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = help(nums, left, mid-1);
        root->right = help(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums, 0, nums.size()-1); 
    }
};
// @lc code=end

