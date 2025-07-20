// bfs最好想，一定要会
// 在bfs的过程中，如果当前节点为偶数，则计算即孙子节点
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val % 2 == 0) {
                if (node->left) {
                    if (node->left->left) {
                        ans += node->left->left->val;
                    }
                    if (node->left->right) {
                        ans += node->left->right->val;
                    }
                }
                if (node->right) {
                    if (node->right->left) {
                        ans += node->right->left->val;
                    }
                    if (node->right->right) {
                        ans += node->right->right->val;
                    }
                }
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return ans;
    }
};

// dfs

class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root) {
        if(!root) return;
        //如果这个节点val是偶数 它的全部孙子val我要
        if(root->val%2==0){
            if(root->left!=nullptr){
                if(root->left->left!=nullptr)ans+=root->left->left->val;
                if(root->left->right!=nullptr)ans+=root->left->right->val;
            }
            if(root->right!=nullptr){
                if(root->right->left!=nullptr)ans+=root->right->left->val;
                if(root->right->right!=nullptr)ans+=root->right->right->val;
            }
        }
        dfs(root->left);
        dfs(root->right);
    }

    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return ans;
        
    }
};