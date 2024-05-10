/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   合法二叉搜索树.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taoyanqi <taoyanqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:39:49 by taoyanqi          #+#    #+#             */
/*   Updated: 2024/05/10 20:40:04 by taoyanqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Solution {
public:
    // 中序遍历即可
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long int min_value = -1e10;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(root->val <= min_value) {
                return false;
            }
            min_value = root->val;
            root = root->right;
        }
        return true;

    }
};