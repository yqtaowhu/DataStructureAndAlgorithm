#include "Stack.h"
#include<iostream>
#include<vector>
using namespace std;
//测试一个一个序列是否是出栈序列
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	Stack<int> st;
	int len = pushV.size();
	int i = 0, j = 0;
	while (i<len&&j<len) {
		if (pushV[i] == popV[j]) {
			i++; j++;
		}
		else if (st.Size()>0 && st.GetTop() == popV[j]) {
			st.Pop();
			j++;
		}
		else {
			st.Push(pushV[i]);
			i++;
		}
	}
	while (j<len) {
		if (st.GetTop() != popV[j]) return false;
		j++;
		st.Pop();
	}
	return true;
}
int main() {
	vector<int> push = { 1,2,3,4,5 };
	vector<int> pop = { 4,5,3,2,1 };
	cout << boolalpha<<IsPopOrder(push, pop) << endl;
}