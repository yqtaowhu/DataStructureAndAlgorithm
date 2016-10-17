//Author	: yqtao
//date		: 2016.10.17
//Email		: yqtao@whu.edu.cn
/*
  最小生成树的Kruskal算法
  以权值排序边
  输入数据：
  6 9
  2 4 11
  3 5 13
  4 6 3
  5 6 4
  2 3 6
  4 5 7
  1 2 1
  3 4 9
  1 3 2
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//创建结构体，方便对边进行排序
struct edge {
	int u;
	int v;
	int w;
};
edge e[10];       //假设只有9条边
int n, m;
int f[10];        //并查集
//
int getf(int v) {
	if (v == f[v])
		return f[v];
	else {
		f[v] = getf(f[v]);
		return f[v];
	}
}
int merge(int u, int v) {
	int t1 = getf(u);
	int t2 = getf(v);
	if (t1 != t2) {   //不在一个集合中
		f[t2] = t1;
		return 1;
	}
	return 0;
}
//快速排序
void quick_sort(int low, int high) {
	int i, j;
	edge pivot;
	if (low < high) {
		pivot = e[low]; i = low; j = high;
		while (i < j) {
			while (i<j&&e[j].w>pivot.w)
				j--;
			e[i] = e[j];
			while (i < j&&e[i].w < pivot.w)
				i++;
			e[j] = e[i];
		}
		e[i] = pivot;
		quick_sort(low, i - 1);
		quick_sort(i + 1, high);
	}
}
int main() {
	//读入n,m，其中n为顶点个数，m为边的个数
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	//对边进行排序
	quick_sort(1, m);
	/*for (int i = 1; i <= m; i++) {
		cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
	}*/
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	//Kruskal核心算法
	int count = 0, sum = 0;
	for (int i = 1; i <= m; i++) {
		if (merge(e[i].u, e[i].v)) {        //如果这两个点不在一个集合中
			count++;
			sum += e[i].w;
		}
		if (count == n - 1) break;
	}
	cout << sum << endl;
	return 0;
}