- [树相关算法](#%e6%a0%91%e7%9b%b8%e5%85%b3%e7%ae%97%e6%b3%95)
  - [1. 二叉树的深度](#1-%e4%ba%8c%e5%8f%89%e6%a0%91%e7%9a%84%e6%b7%b1%e5%ba%a6)
    - [1.1 二叉树的最大深度](#11-%e4%ba%8c%e5%8f%89%e6%a0%91%e7%9a%84%e6%9c%80%e5%a4%a7%e6%b7%b1%e5%ba%a6)
    - [1.2 二叉树的最小深度](#12-%e4%ba%8c%e5%8f%89%e6%a0%91%e7%9a%84%e6%9c%80%e5%b0%8f%e6%b7%b1%e5%ba%a6)
  - [2. 两棵树直接的关系](#2-%e4%b8%a4%e6%a3%b5%e6%a0%91%e7%9b%b4%e6%8e%a5%e7%9a%84%e5%85%b3%e7%b3%bb)
    - [2.1 相同的树](#21-%e7%9b%b8%e5%90%8c%e7%9a%84%e6%a0%91)
    - [2.2 另一个数的子树](#22-%e5%8f%a6%e4%b8%80%e4%b8%aa%e6%95%b0%e7%9a%84%e5%ad%90%e6%a0%91)
  - [3. 二叉搜索树](#3-%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91)
    - [3.1 判断是否是二叉搜索树](#31-%e5%88%a4%e6%96%ad%e6%98%af%e5%90%a6%e6%98%af%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91)
    - [3.2 恢复二叉搜索树](#32-%e6%81%a2%e5%a4%8d%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91)


# 树相关算法

## 1. 二叉树的深度
### 1.1 二叉树的最大深度
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**递归算法**
```
int maxDepth(TreeNode* root) {
    return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1:0;
}
```
**迭代算法**
既然求解最大的深度，那么可以按层去遍历树，到达最后一层即可知道树的深度了，按层遍历是一定要会的算法。

```
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    
    queue<TreeNode*> que;
    que.push(root);
    int depth = 0;
    
    while(!que.empty()) {
        int size = que.size();
        depth++;
        // 将一层的节点全部取出
        for(int i=0; i<size; i++) {
            root = que.front();
            que.pop();
            if(root->left) {
                que.push(root->left);
            }
            if(root->right) {
                que.push(root->right);
            }
        }
    }
    return depth;
}
```
### 1.2 二叉树的最小深度

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

**递归方法**
```
int minDepth(TreeNode* root) {
    if(!root)  return 0;
    // 左右孩子都存在，找小的一个深度
    if(root->left && root->right)  //判断是否为叶子节点
        return min(minDepth(root->left),minDepth(root->right))+1;
    // 左右孩子只有一个存在，找大的一个
    else      
        return max(minDepth(root->left),minDepth(root->right))+1;
}

```
如果使用层序遍历法，则当一个节点左右孩子都为空的时候，就退出程序即可,代码和求二叉树最大深度的类似，略。

## 2. 两棵树直接的关系

### 2.1 相同的树

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

递归方法很好理解:
```
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr || q == nullptr) return p == q;
    return p->val == q->val && isSameTree(p->left, q->left) &&
        isSameTree(p->right, q->right);
}
```

### 2.2 另一个数的子树
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

对s的任意一个节点为t的开始根节点进行比较，两个是不是相同的树即可
```
class Solution {
public:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if(!s || !t) return s == t;
        return s->val == t->val && isSameTree(s->left, t->left) && 
            isSameTree(s->right, t->right);
    }

    bool dfs(TreeNode* s, TreeNode* t) {
        if (!s)
            return false;
        return isSameTree(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }
};
```

## 3. 二叉搜索树

### 3.1 判断是否是二叉搜索树
**递归方法**
```
//需要在遍历树的同时保留结点的上界与下界，在比较时不仅比较子结点的值，也要与上下界比较。

class Solution {
public:
    bool isValidBST(TreeNode*root, TreeNode* minNode, TreeNode* maxNode) {
        if(root == nullptr)
            return true;
        if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
            return false;
        }
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
};
```
根据二叉搜索树的中序遍历是有序的这一条件可以判断一个树是不是二叉搜索树。
```
bool isValidBST(TreeNode* root) {
	    stack<TreeNode*>st;
        long long pre = LONG_LONG_MIN;
        while (root || st.size()>0) {
		    if (root) {
			    st.push(root);
			    root = root->left;
		    }   
		    else {
				root = st.top();
				st.pop();
				
                if(root->val <= pre) {
                    return false;
                }
                pre = root->val;

				root = root->right;
			}
		}
        return true;
    }
```

### 3.2 恢复二叉搜索树

二叉搜索树中的两个节点被错误地交换,请在不改变其结构的情况下，恢复这棵树。

```
    3
   /   \
  4    1
   \
    2
中序遍历   4 2 3 1  -> 交换4 1
当遍历到2时，此时 pre > root, 记录
当遍历到1是，此时 pre > root, 记录
然后交换即可。
```


```
class Solution {
public:
    TreeNode *pre = new TreeNode(INT_MIN);
    TreeNode *first = nullptr, *second = nullptr;

    void dfs(TreeNode* root) {
        // 中序遍历
        if(!root) {
            return;
        }
        dfs(root->left);

        if(first == nullptr && pre->val > root->val) {
            first = pre;
        }
        if(first && pre->val > root->val) {
            second = root;
        }

        pre = root;

        dfs(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};
```