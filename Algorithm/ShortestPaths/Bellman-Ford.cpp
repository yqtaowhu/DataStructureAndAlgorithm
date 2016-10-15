//Author	: yqtao
//date		: 2016.10.14
//Email		: yqtao@whu.edu.cn
/*
  Bellman-Ford Algorithm
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
const int inf = 100;
int main() {
	int m, n;     //m为顶点数，n为边的数目
	cin >> m >> n;
	//注意这里用了三个u,v,w取代了邻接矩阵，u,v表示顶点w为权重
	vector<int> dis(m + 1,inf), u(n + 1), v(n + 1), w(n + 1);
	//读入边数据
	for (int i = 1; i <= n; i++)      //i表示为第几条边
		cin >> u[i] >> v[i] >> w[i];
	//初始化dis数组
	dis[1] = 0;          //这里表示要找出1到个顶点的距离

	int check=0, flag = 0;    //check用于提前退出，flag用于检测是否有
	//Bellman-Ford Algorithm算法核心代码
	for (int k = 1; k <= m- 1; k++) {       //进行m-1次边的松弛
		check = 0;
		for (int i = 1; i <= n; i++) {
			if (dis[v[i]] > dis[u[i]] + w[i]) {
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
			}
		}
		if (check == 0) break;
	}

	//检测是否有负权值
	for (int i = 1; i <= n; i++)
		if (dis[v[i] > dis[u[i]] + w[i]])
			flag = 1;
	if (flag == 1) cout << "有负权值" << endl;
	else {
		for (int i = 1; i <= m; i++)
			cout << dis[i] << "  " << endl;
	}
	cout << endl;
}