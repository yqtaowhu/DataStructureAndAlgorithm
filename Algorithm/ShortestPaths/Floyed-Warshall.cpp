//Author	: yqtao
//date		: 2016.09.19
//Email		: yqtao@whu.edu.cn
/*
  Floyed-Warshall Algorithm
  多源最短路径问题
  输入格式：
  4 8             //第一个数为顶点，第二个数为边数
  1 2 2           //下面的为 从顶点i,到顶点j 和权值 w ,即从1到2的权值为2
  1 3 6
  1 4 4
  2 3 3
  3 1 7
  3 4 1
  4 1 5
  4 3 12
*/

#include <iostream>
#include<vector>
const int inf = 100;
using namespace std;
int main() {
	int m, n;           //m是顶点的个数，n边的个数
	cin >> m >> n;
	vector<vector<int>> map(m + 1, vector<int>(m + 1, 0));    //邻接矩阵表示图
	//初始化矩阵
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
	//Floyed-Warshall Algorithm核心代码，三个for循环
	for (int k= 1; k<= m; k++) {        //分别以顶点1...m为中转点
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {                
				if (map[i][j] > map[i][k] + map[k][j])	// k = 2时，例如1->3的距离如果大于1->2->3则更新
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	//输出结果
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map[i][j] << "  ";
		}
		cout << endl;
	}
}
/*
  一个实例：
  http://hihocoder.com/problemset/problem/1089?sid=943791
*/
#include<iostream>
#include<vector>
using namespace std;
int n, m;  //n顶点
const int inf = 10010;
int main() {
	cin >> n >> m;
	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) map[i][j] = inf;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (map[a][b]>c)
			map[a][b] = map[b][a] = c;
	}
	//核心语句
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][j]>map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
	//输出
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}
