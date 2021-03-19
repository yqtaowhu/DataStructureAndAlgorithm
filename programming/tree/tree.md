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
    - [3.5 不同的二叉搜索树](#35-%e4%b8%8d%e5%90%8c%e7%9a%84%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91)
    - [3.6 二叉搜索树的后序遍历序列](#36-%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91%e7%9a%84%e5%90%8e%e5%ba%8f%e9%81%8d%e5%8e%86%e5%ba%8f%e5%88%97)
  - [3.7二叉搜索树的第k大节点](#37%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91%e7%9a%84%e7%ac%ack%e5%a4%a7%e8%8a%82%e7%82%b9)
  - [4. 树的特征](#4-%e6%a0%91%e7%9a%84%e7%89%b9%e5%be%81)
    - [4.1 对称二叉树](#41-%e5%af%b9%e7%a7%b0%e4%ba%8c%e5%8f%89%e6%a0%91)
  - [5. 前序，中序构造二叉树](#5-%e5%89%8d%e5%ba%8f%e4%b8%ad%e5%ba%8f%e6%9e%84%e9%80%a0%e4%ba%8c%e5%8f%89%e6%a0%91)
  - [6. 平衡二叉树](#6-%e5%b9%b3%e8%a1%a1%e4%ba%8c%e5%8f%89%e6%a0%91)
    - [6.1 判断一棵树是不是平衡二叉树](#61-%e5%88%a4%e6%96%ad%e4%b8%80%e6%a3%b5%e6%a0%91%e6%98%af%e4%b8%8d%e6%98%af%e5%b9%b3%e8%a1%a1%e4%ba%8c%e5%8f%89%e6%a0%91)
  - [7. 路径](#7-%e8%b7%af%e5%be%84)
    - [7.1 判断是否存在从根节点到叶子节点的路径和为指定值](#71-%e5%88%a4%e6%96%ad%e6%98%af%e5%90%a6%e5%ad%98%e5%9c%a8%e4%bb%8e%e6%a0%b9%e8%8a%82%e7%82%b9%e5%88%b0%e5%8f%b6%e5%ad%90%e8%8a%82%e7%82%b9%e7%9a%84%e8%b7%af%e5%be%84%e5%92%8c%e4%b8%ba%e6%8c%87%e5%ae%9a%e5%80%bc)
    - [7.2 找出所有的路径](#72-%e6%89%be%e5%87%ba%e6%89%80%e6%9c%89%e7%9a%84%e8%b7%af%e5%be%84)
    - [7.3 二叉树的直径](#73-%e4%ba%8c%e5%8f%89%e6%a0%91%e7%9a%84%e7%9b%b4%e5%be%84)
    - [7.4 二叉树的最大路径和](#74-%e4%ba%8c%e5%8f%89%e6%a0%91%e7%9a%84%e6%9c%80%e5%a4%a7%e8%b7%af%e5%be%84%e5%92%8c)
  - [8. 二叉树和链表](#8-%e4%ba%8c%e5%8f%89%e6%a0%91%e5%92%8c%e9%93%be%e8%a1%a8)
    - [8.1 二叉树展开为链表](#81-%e4%ba%8c%e5%8f%89%e6%a0%91%e5%b1%95%e5%bc%80%e4%b8%ba%e9%93%be%e8%a1%a8)
    - [8.2 二叉搜索树转成双向链表](#82-%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91%e8%bd%ac%e6%88%90%e5%8f%8c%e5%90%91%e9%93%be%e8%a1%a8)
  - [9. 最近公共祖先](#9-%e6%9c%80%e8%bf%91%e5%85%ac%e5%85%b1%e7%a5%96%e5%85%88)
    - [9.1 二叉搜索树的最近公共祖先](#91-%e4%ba%8c%e5%8f%89%e6%90%9c%e7%b4%a2%e6%a0%91%e7%9a%84%e6%9c%80%e8%bf%91%e5%85%ac%e5%85%b1%e7%a5%96%e5%85%88)
    - [9.2 二叉树的最近公共祖先](#92-%e4%ba%8c%e5%8f%89%e6%a0%91%e7%9a%84%e6%9c%80%e8%bf%91%e5%85%ac%e5%85%b1%e7%a5%96%e5%85%88)
  - [10 重建二叉树](#10-%e9%87%8d%e5%bb%ba%e4%ba%8c%e5%8f%89%e6%a0%91)
    - [10.1 给定前序和中序遍历，重建二叉树](#101-%e7%bb%99%e5%ae%9a%e5%89%8d%e5%ba%8f%e5%92%8c%e4%b8%ad%e5%ba%8f%e9%81%8d%e5%8e%86%e9%87%8d%e5%bb%ba%e4%ba%8c%e5%8f%89%e6%a0%91)
  - [镜像二叉树](#%e9%95%9c%e5%83%8f%e4%ba%8c%e5%8f%89%e6%a0%91)
  - [序列化二叉树](#%e5%ba%8f%e5%88%97%e5%8c%96%e4%ba%8c%e5%8f%89%e6%a0%91)


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

注意和此题的不同:https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/submissions/
主要是判断条件的不同
```
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    
    bool dfs(TreeNode* A, TreeNode* B) {
        if (!B) return true; 
        if (!A) return false;
        return A->val == B->val && dfs(A->left, B->left) && dfs(A->right, B->right);
    }
}
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
### 3.5 不同的二叉搜索树
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

```
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
```

### 3.6 [二叉搜索树的后序遍历序列](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)

判断一个数组是不是二叉搜索树的后续遍历, 递归解法

```
class Solution {
public:
    bool dfs(vector<int>& postorder, int i, int j) {
        if(i > j ) return true;
        // 找到左右子树的分界点
        int m = i;
        while(postorder[m] < postorder[j]) m++; //左子树满足小于根节点
        int n = m;
        while(postorder[n] > postorder[j]) n++; // 找到右子树边界
        return n == j && dfs(postorder, i, m-1) && dfs(postorder, m, j-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size() - 1);
    }
};
```

## 3.7[二叉搜索树的第k大节点](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/)

二叉搜索树的中序遍历是递增(左根右)， 那么右根左就是递减的序列了，因此此题需要用右根左的方式遍历。
```
class Solution {
public:
    void dfs(TreeNode* root, int &k, int &res) {
        // 提取结束
        if(!root) {
            return;
        }
        // 右
        dfs(root->right, k, res);
        // 特殊处理，根
        if(k == 0) {
            return;
        }
        k -= 1;
        if(k == 0) {
            res = root->val;
        }
        // 左
        dfs(root->left, k, res);
    }

    int kthLargest(TreeNode* root, int k) {
        if(!root) return -1;
        int res = INT_MIN;
        dfs(root, k, res);
        return res;
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

## 7. 路径

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

### [7.3 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

```
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        // 仅仅多这一行，相比于求解树的深度
        res = max(res, left + right);
        // 以当前节点为根节点树的深度
        return max(left, right) + 1;
    }
};
```

### [7.4 二叉树的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

此题和二叉树的直径非常类似，考虑经过某一节点为根节点的最大路径和，然后进行递归

```
class Solution {
public:
    int max_sum = INT_MIN;
    int max_gain(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left_gain = max(max_gain(root->left), 0);
        int right_gain = max(max_gain(root->right), 0);
        int sum = root->val + left_gain + right_gain;
        max_sum = max(max_sum, sum);

        //维护以前的路径
        return root->val + max(left_gain, right_gain);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
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
### 8.2 二叉搜索树转成双向链表

很简单的中序遍历题目，因为要转成排序的双向链表，很容易想到中序遍历是有序的数组，因此在遍历是改变指针的方向即可

```
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
       // 排序双向链表，因此使用中序遍历
       stack<Node*> st;
       Node* pre=nullptr, *head=root;
       while(root || !st.empty()) {
           if(root) {
               st.push(root);
               cout<<root->val<<endl;
               root = root->left;
           } else {
               root = st.top();
               st.pop();
               
               // 具体处理过程，其他的都是中序遍历的模板
               if(pre == nullptr) {
                   pre = root;
                   head = root;  // 此时是最小值
               } else {
                   // 更新节点
                   pre->right = root;
                   root->left = pre;
                   pre = root;
               }

               root = root->right;
           }
       }
       // 连接收尾元素
       pre->right = head;
       head->left = pre;
       return head; 
    }
};
```

## 9. 最近公共祖先

### 9.1 二叉搜索树的最近公共祖先

```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(root->val > p->val && root->val > q->val) {
         return lowestCommonAncestor(root->left, p, q);
     } 
     if(root->val < p->val && root->val < q->val) {
         return lowestCommonAncestor(root->right, p, q);
     }
     return root;
 }
```

### 9.2 二叉树的最近公共祖先

**如何求解根节点到指定节点的路径**

```
bool dfs(TreeNode* root, TreeNode* des, vector<TreeNode*> &path) {
    if (root == nullptr)
        return false;
    if (root == des) {
        path.push_back(root);
        return true;
    }
    if (dfs(root->left, des, path) || dfs(root->right, des, path)) {
        path.push_back(root);
        return true;
    }
    return false;
}
```
找到根节点到指定节点的路径后，即可回溯完成:

```
TreeNode* lowestCommonAncestorCommonTree(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path_p, path_q;
    dfs(root, p, path_p);
    dfs(root, q, path_q);
    reverse(path_p.begin(), path_p.end());
    reverse(path_q.begin(), path_q.end());

    int n = min(path_p.size(), path_q.size());
    for (int i = n - 1; i >= 0; i--)
        if (path_p[i] == path_q[i])
            return path_p[i];

    return nullptr;
}
```

**一种简单的思路:**
```
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(root == nullptr || root == p || root == q){ 
         return root; 
     }
     TreeNode* left=lowestCommonAncestor(root->left,p,q);
     TreeNode* right=lowestCommonAncestor(root->right,p,q);
     if (left&&right) return root;
     return left ? left:right; 
    }
```

## 10 重建二叉树

### 10.1 给定前序和中序遍历，重建二叉树

简单的题目，递归的去建立
```
class Solution {
public:
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
}
```


## 镜像二叉树

```
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root) {
            swap(root->left, root->right);
            mirrorTree(root->left);
            mirrorTree(root->right);
        }
        return root;
    }
};
```

## 序列化二叉树

序列化为 "[1,2,3,null,null,4,5]"

```
class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root) {
		if (!root) {
			return "[]";
		}
		queue<TreeNode *> q;
		q.push(root);
		stringstream ss;
		while (!q.empty()) {
			root = q.front();
			q.pop();
			if (root) {
				q.push(root->left);
				q.push(root->right);
				ss << to_string(root->val) << ",";
			}
			else {
				ss << "null,";
			}
		}

		string data = ss.str();
		data = trimRightNulls(data, "null,");		// 去掉最后一层之后多余的 null
		data = data.substr(0, data.size() - 1); // 去掉最后一个 ,
		return "[" + data + "]";
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string input) {
		input = input.substr(1, input.length() - 2);
		if (!input.size()){
			return nullptr;
		}

		string item;
		stringstream ss;
		ss.str(input);

		getline(ss, item, ',');
		TreeNode *root = new TreeNode(stoi(item));
		queue<TreeNode *> nodeQueue;
		nodeQueue.push(root);

		while (true) {
			TreeNode *node = nodeQueue.front();
			nodeQueue.pop();

			if (!getline(ss, item, ',')) {
				break;
			}

			if (item != "null") {
				int leftNumber = stoi(item);
				node->left = new TreeNode(leftNumber);
				nodeQueue.push(node->left);
			}

			if (!getline(ss, item, ',')) {
				break;
			}

			if (item != "null") {
				int rightNumber = stoi(item);
				node->right = new TreeNode(rightNumber);
				nodeQueue.push(node->right);
			}
		}
		return root;
	}

	string trimRightNulls(string data, string target) {
		int size = target.size();
		while (data.size() > size && data.substr(data.size() - size, size) == target) {
			data = data.substr(0, data.size() - size);
		}
		return data;
	}
};
```