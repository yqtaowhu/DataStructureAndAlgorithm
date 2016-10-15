//Author	: yqtao
//date		: 2016.10.14
//Email		: yqtao@whu.edu.cn
/*
  寻找犯罪团伙
  第一行为m=小偷人数和n=警察收集到的信息
  第二行到最后为n条团伙信息
  求共有多少个团伙
  10 9         
  1 2
  3 4
  5 2
  4 6
  2 6
  8 7
  9 7
  1 6
  2 4
*/
#include<iostream>
#include<vector>
using namespace std;
int m,n;
vector<int> f(101, 0);   //假设最多100个小偷
//初始化的过程，刚开始他们的团伙仅有自己
void init() {
	for (int i = 1; i <= m; i++)
		f[i] = i;
}
//查找祖先的过程，直到找到祖先位置
int getf(int v) {
	if (v == f[v])     //它的祖先是自己
		return v;
	else {
		//路径压缩的过程，每次函数返回时，顺便修改其集合
		f[v] = getf(f[v]);
		return f[v];
	}
}
//合并两个子集的过程
void merge(int v,int u) {
	int t1, t2;
	t1 = getf(v);   //查找祖先的过程
	t2 = getf(u);
	if (t1 != t2) {     //两者祖先不一样，但是又是同一团伙，则合并
		f[t2] = t1;
	}
}
//
int main() {
	cin >> m >> n;
	init();
	int x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		merge(x, y);
	}
	//检查有多少个犯罪团伙
	int sum = 0;
	for (int i = 1; i <= m; i++)
		if (i == f[i])
			sum++;
	cout << sum << endl;
}

/*
  一个实例：
  http://hihocoder.com/problemset/problem/1066?sid=943717
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
 using namespace std;
 map< string, int > s;
 int father[100001];
 int find_set(int x) {
	 if (x == father[x])
		 return x;
	 else {
		 father[x] = find_set(father[x]);
		 return father[x];
	 }

 }
 void Union(int a, int b) {
		 int x = find_set(a);
	     int y = find_set(b);
	     if (x != y) father[x] = y;
}
int main() {
	     int n, c = 1;
	     bool ok;
	     cin >> n;
	     for (int i = 0; i <= n; ++i)     //初始化的过程
		         father[i] = i;
	     while (n--) {
		       string a, b;
		       cin >> ok >> a >> b;
		       if (s[a] == 0)  s[a] = c++;
		       if (s[b] == 0)  s[b] = c++;
			   if (ok) {
			       if (find_set(s[a]) == find_set(s[b]))
		              cout << "yes" << endl;
    	           else cout << "no" << endl;
			   }
		      else {
			       Union(s[a], s[b]);
		       }
	    }
	     return 0;
 }