//Author	: yqtao
//date		: 2016.10.14
//Email		: yqtao@whu.edu.cn
/*
  Dijkstra Algorithm
  单源最短路径问题.
  //第一个数为顶点，第二个数为边数
  //下面的为 从顶点i,到顶点j 和权值 w ,即从1到2的权值为2
  6 9
  1 2 1
  1 3 12
  2 3 9
  2 4 3
  3 5 5
  4 3 4
  4 5 13
  4 6 15
  5 6 4
*/
#include<iostream>
#include<vector>
using namespace std;
int m, n,u;
const int inf = 100;
//map表示邻接矩阵，i表示求第i个点到其余每个点的距离
vector<int> Dijkstra(vector<vector<int>> &map, int beg) {
	vector<int> book(m + 1, 0);    //标记矩阵，为0表示未确定是否是最小值
	vector<int> dis(m + 1, 0);     //返回矩阵
	book[beg] = 1;                   //即当前的点已经确认为最近点
	for (int i = 1; i <= m; i++)
		dis[i] = map[beg][i];
	//Dijkstra 核心算法
	for (int i = 1; i <= m - 1; i++) {   //m-1次边的松弛
		int min = inf;
		for (int j = 1; j <= m; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;         //记录位置点
			}
		}
		book[u] = 1;           //已经确认的从beg到u最近点
		for (int v = 1; v <= m; v++) {       //每个与u相近的点v
			if (map[u][v] < inf) {
				if (dis[v] > dis[u] + map[u][v])    //即尝试看能否经过u中转得到更小的距离
					dis[v] = dis[u] + map[u][v];
			}
		}
	}
	return dis;
}
int main() {
	cin >> m >> n;
	//空间复杂度O(M^2),可以进一步优化
	vector<vector<int>> map(m + 1, vector<int>(m + 1, 0));    //邻接矩阵												  //初始化矩阵
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			if (i != j)
				map[i][j] = inf;
	//读入数据
	int t1, t2, t3;
	for (int i = 1; i <= n; i++) {
		cin >> t1 >> t2 >> t3;
		map[t1][t2] = t3;
	}
	vector<int>dis = Dijkstra(map, 1);      //第一个点
	for (int i = 1; i <= m; i++)
		cout << dis[i] << " ";
	cout << endl;
}

/*
  一个实例：http://hihocoder.com/problemset/problem/1081
*/
#include<iostream>
#include<vector>
using namespace std;
const int n_max = 10010;
const int inf = 1 << 30;
int n, m, s, t, u;
//这里声明全局变量会超出内存限制，要注意
//vector<vector<int>> map(n_max, vector<int>(n_max, inf));
vector<int> Dijkstra(vector<vector<int>>&map, int s) {          //s为入口
	vector<int> dis(n + 1, inf);
	vector<int> book(n + 1, 0);
	for (int i = 1; i <= n; i++)        //初始化dis矩阵
		dis[i] = map[s][i];
	dis[s] = 0;
	book[s] = 1;
	for (int i = 1; i <= n - 1; i++) {   //n-1次边的松弛
		int min = inf;
		//找一个最近点
		for (int j = 1; j <= n; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;         //记录位置点
			}
		}
		if (min == inf) break;
		book[u] = 1;           //已经确认的从s到u最近点
		for (int v = 1; v <= n; v++) {       //每个与u相近的点v
			if (map[u][v] < inf) {
				if (dis[v] > dis[u] + map[u][v] && book[v] == 0)    //即尝试看能否经过u中转得到更小的距离
					dis[v] = dis[u] + map[u][v];
			}
		}
	}
	return dis;
}
int main() {
	cin >> n >> m >> s >> t;
	vector<vector<int>> map(n + 1, vector<int>(n + 1, inf));
	for (int i = 1; i <= m; i++) {    //注意m是边,n是顶点
		int a, b, c;
		cin >> a >> b >> c;
		if (c < map[a][b])          //特别注意选择最小的路径
			map[a][b] = map[b][a] = c;
	}
	vector<int>dis = Dijkstra(map, s);
	cout << dis[t] << endl;
	return 0;
}
