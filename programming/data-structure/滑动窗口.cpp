
// 题目链接: https://www.acwing.com/problem/content/156/
#include <iostream>

using namespace std;

const int N=1e6+10;
int a[N], q[N];
int n,k;

int main() {
    cin >> n >> k;
    for(int i =0; i<n; i++) scanf("%d", &a[i]);
    int hh=0, tt=-1;
    
    //滑动窗口最小值，单调递增队列, 队列中存储索引
    for(int i =0; i<n; i++) {
        // 如果队列不空，并且队列长度大于k了
        if(hh <= tt && i-k+1 > q[hh]) {
            hh++; //删除队头
        }
        // 将比当前元素大的数出队，保持将其插入后是单调递增的队列
        while(hh <= tt && a[q[tt]] >= a[i]) {
            tt--;
        }
        q[++tt] = i; // 加入队尾
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    
    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ ) {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
        q[ ++ tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");
    
    return 0;
}