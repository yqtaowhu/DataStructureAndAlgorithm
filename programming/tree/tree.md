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
    - [3.3 将有序数组转换成二叉搜索树](#33-%e5%b0%86%e6%9c%89%e5%ba%8f%e6%95%b0%e7%bb%84%e8%bd%ac%e6%8d%a2%e6%88%90%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91)
    - [3.4 将有序链表转换成二叉搜索树](#34-%e5%b0%86%e6%9c%89%e5%ba%8f%e9%93%be%e8%a1%a8%e8%bd%ac%e6%8d%a2%e6%88%90%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91)
  - [4. 树的特征](#4-%e6%a0%91%e7%9a%84%e7%89%b9%e5%be%81)
    - [4.1 对称二叉树](#41-%e5%af%b9%e7%a7%b0%e4%ba%8c%e5%8f%89%e6%a0%91)
  - [5. 前序，中序构造二叉树](#5-%e5%89%8d%e5%ba%8f%e4%b8%ad%e5%ba%8f%e6%9e%84%e9%80%a0%e4%ba%8c%e5%8f%89%e6%a0%91)
  - [6. 平衡二叉树](#6-%e5%b9%b3%e8%a1%a1%e4%ba%8c%e5%8f%89%e6%a0%91)
    - [6.1 判断一棵树是不是平衡二叉树](#61-%e5%88%a4%e6%96%ad%e4%b8%80%e6%a3%b5%e6%a0%91%e6%98%af%e4%b8%8d%e6%98%af%e5%b9%b3%e8%a1%a1%e4%ba%8c%e5%8f%89%e6%a0%91)
  - [7. 路径和](#7-%e8%b7%af%e5%be%84%e5%92%8c)
    - [7.1 判断是否存在从根节点到叶子节点的路径和为指定值](#71-%e5%88%a4%e6%96%ad%e6%98%af%e5%90%a6%e5%ad%98%e5%9c%a8%e4%bb%8e%e6%a0%b9%e8%8a%82%e7%82%b9%e5%88%b0%e5%8f%b6%e5%ad%90%e8%8a%82%e7%82%b9%e7%9a%84%e8%b7%af%e5%be%84%e5%92%8c%e4%b8%ba%e6%8c%87%e5%ae%9a%e5%80%bc)
    - [7.2 找出所有的路径](#72-%e6%89%be%e5%87%ba%e6%89%80%e6%9c%89%e7%9a%84%e8%b7%af%e5%be%84)
  - [8. 二叉树和链表](#8-%e4%ba%8c%e5%8f%89%e6%a0%91%e5%92%8c%e9%93%be%e8%a1%a8)
    - [8.1 二叉树展开为链表](#81-%e4%ba%8c%e5%8f%89%e6%a0%91%e5%b1%95%e5%bc%80%e4%b8%ba%e9%93%be%e8%a1%a8)


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

### 3.3 将有序数组转换成二叉搜索树
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树

选择中位数为根节点，然后左右递归建立节点。
```
class Solution {
public:
    // 构建二叉搜索树，数组的[left, right]进行构建
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
```

### 3.4 将有序链表转换成二叉搜索树

简单的方法如上，转数组，直接可以构造，如果不用数组，则使用快慢指针找到当前链表的中间位置

```
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
    TreeNode * buildTree(ListNode* head, ListNode * tail){
        if(head == tail) return nullptr;
        ListNode* slow = head, *fast = head;
        // 快慢指针找中间节点
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        root->left = buildTree(head, slow);
        root->right = buildTree(slow->next, tail);
        return root;
    }
};
```

## 4. 树的特征

### 4.1 对称二叉树

// 递归思路
```
class Solution {
public:
	bool isSymmetric(TreeNode *p, TreeNode *q) {
        if(!p || !q) {
            return p == q;
        }

		return (p->val == q->val) && isSymmetric(p->left, q->right) && 
            isSymmetric(p->right, q->left);
	}
	bool isSymmetric(TreeNode* root) {
		return isSymmetric(root, root);
	}
};
```
// 迭代的思路也很简单,使用队列进行层序的变量
```
bool isSymmetric(TreeNode* root) {
      if(!root) return true;
      queue<TreeNode*> que;
      que.push(root->left);
      que.push(root->right);
      while(!que.empty()) {
          TreeNode* p1 = que.front();
          que.pop();
          TreeNode* p2 = que.front();
          que.pop();

          // 判断
          if(p1 == nullptr && p2 == nullptr) continue;
          if(p1==nullptr || p2 == nullptr) return false;
          if(p1->val != p2->val) return false;

          que.push(p1->left);
          que.push(p2->right);
          que.push(p1->right);
          que.push(p2->left);
      }
      return true;
}
```

## 5. 前序，中序构造二叉树

递归方法，很好理解，同理，给中序后续构造二叉树一样的方法。
```
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
```

## 6. 平衡二叉树

### 6.1 判断一棵树是不是平衡二叉树

平衡二叉树: 一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1。
```
class Solution {
public:
    int depth(TreeNode* root) {
        return root ? max(depth(root->left), depth(root->right)) + 1 : 0;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        return abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
```

## 7. 路径和

### 7.1 判断是否存在从根节点到叶子节点的路径和为指定值
```
bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
```
### 7.2 找出所有的路径

```
class Solution {
public:
    void dfs(vector<vector<int> > &res, vector<int>& path, int exp, TreeNode* root) {
        if(!root) {
            return;
        }
        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && root->val == exp) {
            res.push_back(path);
        }

        dfs(res, path, exp-root->val, root->left);
        dfs(res, path, exp-root->val, root->right);
        
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(res, path, sum, root);
        return res;
    }
};
```

## 8. 二叉树和链表

### 8.1 [二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

1. 很简单的一种做法是将先序遍历的结果存储到数组中，然后进行组合成链表。
2. 参考: https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/

```
class Solution {
public:
    /*
        1.将左子树插入到右子树的地方
        2.将原来的右子树接到左子树的最右边节点
        3.考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null
    */
    void flatten(TreeNode* root) {
        while(root) {
            // 找到左子树的最右节点
            if(root->left == nullptr) {
                root = root->right;
            } else {
                // 找到左子树的最右节点
                TreeNode* pre = root->left;
                while(pre->right) {
                    pre = pre->right;
                }
                // 原先的右子树加到左子树的最右节点
                pre->right = root->right;
                // 左子树变成当前节点的右子树
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};
```
