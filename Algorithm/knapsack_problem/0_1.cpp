/*
https://www.acwing.com/problem/content/2/
动态规划： f[i][j] : 第i个物品，重量j时最大的价值
1）当前背包容量不够，为前i-1个物品最优解： f[i][j] = f[i-1][j]
2）当前背包容量够，判断选与不选第i个物品
选：f[i][j] = f[i-1][j-w[i]] + v[i]
不选：f[i][j] = f[i-1][j]

优化方式：因为i只与i-1状态有关
状态转移方程为：f[j]=max(f[j],f[j-w[i]]+v[i]
for(int i = 1; i <= n; ++i)
{
    for(int j = m; j>=0; --j)
        if(j>=w[i])
            f[j] = max(f[j], f[j-w[i]]+v[i]);
}

*/

# include<iostream>
using namespace std;

const int MAXN=1010;
int w[MAXN], v[MAXN]; //重量和价值
int f[MAXN][MAXN];  // f[i][j], j重量下前i个物品的最大价值 

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            f[i][j] = f[i-1][j]; //不选
            if (j >= w[i]) //当前容量能否装下
                f[i][j] = max(f[i][j], f[i-1][j-w[i]] + v[i]);
            //cout << f[i][j] << " ";
        }
        //cout << endl;
    }
    cout << f[n][m] <<endl;
    return 0;
}
