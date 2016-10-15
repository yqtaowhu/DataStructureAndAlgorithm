#include "myVector.h"
#include <string>
#include <vector>
using namespace std;
int main()
{
	myVector<float>v;
	cout << "测试默认构造函数" << endl;
	cout << v.size() << " " << v.capacity() << endl;
	cout << "测试构造函数，构造10个1元素" << endl;
	myVector<int> v1(10, 1);				
	for (int i = 0; i < v1.size(); i++)	
		cout << v1[i] <<"  ";			 //操作符重载[]成功   
	cout << endl;
	cout << "得到头和尾的值" << endl;
	cout <<v1.front()<<"  "<<v1.back() << endl;  //测试函数
	cout << endl;
	cout << "测试复制构造函数" << endl;
	myVector<int> vcopy(v1);
	for (int i = 0; i < vcopy.size(); i++)
		cout << vcopy[i] <<"  ";
	cout << endl;


	cout << "测试赋值操作符" << endl;
	myVector<int>vv;
	vv = v1;
	for (int i = 0; i < vv.size(); i++)
		cout << vv[i] << "  ";
	cout << endl;
	

	cout << "测试构造函数,构造n个0元素" << endl;
	myVector<float>v2(10);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "  ";	
	cout << "测试是否为空" << endl;
	cout <<boolalpha<< v2.empty() << endl;
	cout << "测试push_back()" << endl;
	v2.push_back(3);
	cout << v2.size() << "  " << v2.capacity() << "  " << v2[1] << endl;
	cout << "测试pop_back()" << endl;
	v2.pop_back();
	cout << v2.size() << "  " << v2.capacity() << "  " << v2[10] << endl;
	cout << "测试erase(fisrt,last)" << endl;
	for (int i = 0; i < v2.size(); i++) {
		v2[i] += i; cout << v2[i] << "  ";
	}
	cout << endl;
	v2.erase(v2.begin(), v2.begin() + 2);    //从开始，删除两个元素
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "  ";
	cout << endl;
	cout << "测试erase(positon)" << endl;
	v2.erase(v2.begin() + 2);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "  ";
	cout << endl;
	
	//测试重要的函数insert()
	cout << "测试insert(iterator positon, size_type n, const T& x)" << endl;
	myVector<string>vec(5, "test");
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "  " ;
	cout << endl;
	vec.insert(vec.begin() + 2, 7, "program");   //加入7个相同字符
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "  ";
	cout << endl;
	cout << vec.size() << "  " << vec.capacity() << endl;

	cout << "测试迭代器" << endl;
	myVector<string> str(10, "test");
	auto it = str.begin();          //auto位c++11关键字，判断类型
	for (; it != str.end(); ++it)
		cout << *it << " ";
	cout << endl;

	cout << "使矩阵给容器赋初值" << endl;
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	myVector<int> v4(a, a + sizeof(a)/sizeof(a[0]));
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << "  ";
	cout << endl;
	

}