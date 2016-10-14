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
