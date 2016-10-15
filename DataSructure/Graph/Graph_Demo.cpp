#include "Graph.h"
int main() {
	int a[][5] = { 0,8,-1,5,-1,-1,0,3,-1,-1,-1,-1,0,-1,6,-1,9,-1,0,-1,-1,-1,-1,-1,0 };
	Graph<int> gra;
	//创建邻接矩阵
	gra.CreateMGraph(a, 5, 5);
	gra.DispMGraph();
	cout << endl;
	//创建邻接表
	gra.CreateALGraph(a, 5, 5);
	gra.DispALGraph();
	cout << endl;
}