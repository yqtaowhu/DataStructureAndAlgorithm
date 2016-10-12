//Author	: yqtao
//date		: 2016.09.19
//Email		: yqtao@whu.edu.cn
/*
  Some Search Algorithm
*/
/*First question
  求1-n的全排列
  例如： n=3   
  得到： 123,132,213,231,312,321
  思路： n=3时，有三个盒子，和三个数1，2，3分别填入3个盒子中，利用深搜的方法依次填入了
  1. 1 2 3
  2. 此时回溯 1 3 2
*/
//using dfs
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> v(10,0);
vector<bool> book(10, false);       //标记矩阵
void dfs(int step) {
	if (n+1== step) {
		//输出一种全排列
		for (int i = 1; i <= n; i++)
			cout << v[i];
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!book[i]) {            //未被标记
			v[step] = i;
			book[i] = true;
			dfs(step + 1);
			book[i] = false;       //回溯
		}
	}
}
int main() {
	cin >> n;
	dfs(1);
	return 0;
}
/*
  Seconde question
  求岛屿的面积,岛屿非0，海洋为0,给定一个位置，求这个位置的陆地面积
  1 2 1 0 0 
  3 0 2 0 1 
  1 2 0 2 1
  2 0 1 6 1
  4 1 0 2 0
  给定的位置为第4行，4列(6),其面积为7
  很明显此题用bfs比较简单，将其上下左右符合条件的加入队列中，依次广度搜索
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int m,n;                //m行,n列
	int startx, starty;     //需要搜索的开始点
	cin >> m >> n;
	cin >> startx >> starty;
	vector<vector<int>> map(m+1,vector<int>(n+1,0));     //存储地图
	vector<vector<int>> book(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };      //分别在上，下，左，右进行搜索
	queue<pair<int,int>> que;      //队列中记录的是x，y的坐标
	//初始化
	que.push(pair<int, int>(startx, starty));
	book[startx][starty] = 1;             
	int sum = 1;
	while (!que.empty()) {
		for (int k = 0; k < 4; k++) {
			int tx = que.front().first + next[k][0];
			int ty = que.front().second + next[k][1];
			if (tx<1 || tx>m || ty<1 || ty>n) continue;
			if (book[tx][ty] == 0 && map[tx][ty] > 0) {      //为标记，且它为陆地
				sum++;
				book[tx][ty] = 1;
				que.push(pair<int, int>(tx, ty));
			}
		}
		que.pop();
	}
	cout << sum << endl;
}


/*
  Third question
  炸弹人游戏
  #############
  #GG.GG##GGG.#
  ###.#G#G#G#G#
  #.......#..G#
  #G#.###.GGG.#
  ##G...G.....#
  #G#.#G##GG#G#
  #...G#GGG.GG#
  #G#.#G##G#G.#
  #GG.GGG#G.GG#
  #############
*/
#include<iostream>
#include <vector>
using namespace std;
int max = INT_MIN, mx, my,m,n;
//假设最大的方格为20*20
vector<vector<char>> map(21, vector<char>(21,'.'));     
vector<vector<int>> book(21, vector<int>(21, 0));
//统计放在x,y处消除的敌人数
int getsum(int x, int y) {
	int sum = 0;
	int i = x, j = y;
	while (i>=0&&map[i][j] != '#') {
		if (map[i][j] == 'G')
			sum++;
		i--;
	}
	i = x; j = y;
	while (i <m && map[i][j] != '#') {
		if (map[i][j] == 'G')
			sum++;
		i++;
	}
	i = x; j = y;
	while (j >= 0 && map[i][j] != '#') {
		if (map[i][j] == 'G')
			sum++;
		j--;
	}
	i = x; j = y;
	while (j <n && map[i][j] != '#') {
		if (map[i][j] == 'G')
			sum++;
		j++;
	}
	return sum;
}
void dfs(int x, int y) {
	int next[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
	int sum = getsum(x, y);
	if (sum>max) {       //满足条件更新
		max = sum;
		mx = x;
		my = y;
	}
	for (int i = 0; i < 4; i++) {
		int tx = x + next[i][0];
		int ty = y + next[i][1];
		if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
		if (book[tx][ty] == 0 && map[tx][ty] == '.') {
			book[tx][ty] = 1;      //标记
			dfs(tx, ty);
		}
	}
	return;
}
int main() {
	int startx, starty;
	cin >> m >> n>>startx>>starty;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	dfs(startx, starty);
	cout << max << endl;
	cout << mx << " " << my << endl;
}