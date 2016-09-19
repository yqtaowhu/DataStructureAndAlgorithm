//Author	: yqtao
//date		: 2016.09.19
//Email		: yqtao@whu.edu.cn
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<iomanip>
using namespace std;
const int MaxL = 5;
/*
  图的邻接矩阵表示
  vertexType 为顶点的类型
  MGraph图的邻接矩阵表示
*/
struct VertexType     
{
	int no;
	char data[MaxL];     
};
template<typename T>
struct MGraph      
{
	T edges[MaxL][MaxL];
	int n, e;      //n is vertex,e is edge
	VertexType vexs[MaxL];   
};
/*
  图的邻接表的存储方法
  VNode 为表头的结点
  ArcNode 为边结点
*/
template<typename T>
struct ArcNode
{
	int adjvex;				//边的结点
	ArcNode<T> *nextarc;    //指向下一条边的指针 
	T weight;			    //权值
};
template<typename T>
struct VNode
{
	char data[MaxL];         //顶点信息
	ArcNode<T> *firstarc;    //指向第一条边的相邻顶点
};
template<typename T>
struct ALGraph
{
	VNode<T> adjlist[MaxL];
	int n, e;
};
/*
  implement class Graph
*/
template<typename T> class Graph
{
private:
	MGraph<T> g;             //图的邻接矩阵
	ALGraph<T> *G;           //图的邻接表
public:
	Graph() { G =nullptr; }
	void CreateMGraph(T a[][MaxL], int n, int e);    //通过边数组创建邻接矩阵
	void DispMGraph();
	void CreateALGraph(T a[][MaxL], int n, int e);
	void DispALGraph();
};
//
template<typename T>
void Graph<T>::CreateMGraph(T a[][MaxL], int n, int e) {
	g.n = n;
	g.e = e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			g.edges[i][j] = a[i][j];
	}
}
//
template<typename T>
void Graph<T>::DispMGraph() {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++)
			cout << setw(4) << g.edges[i][j];
		cout << endl;
	}
}
//
template<typename T>
void Graph<T>::CreateALGraph(T a[][MaxL], int n, int e) {
	G = new ALGraph<T>();
	G->n = n; G->e = e;
	ArcNode<T> *p;
	for (int i = 0; i < n; i++)			  //初始化表头
		G->adjlist[i].firstarc = nullptr;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] != 0 && a[i][j] != -1) {      //-1表示两者不相邻，权值为无穷
				p = new ArcNode<T>();     //创建节点
				p->adjvex = j;
				p->weight = a[i][j];
				p->nextarc = G->adjlist[i].firstarc;    //头插法
				G->adjlist[i].firstarc = p;

			}
		}
	}
}
//
template<typename T>
void Graph<T>::DispALGraph() {
	ArcNode<T> *p;
	for (int i = 0; i < G->n; i++) {
		cout << "[" << i << "]";
		p = G->adjlist[i].firstarc;
		if (p) cout << "->";
		while (p) {
			cout << " " << p->adjvex << "(" << p->weight << ")";
			p = p->nextarc;
		}
		cout << endl;
	}
}
#endif // !GRAPH_H

