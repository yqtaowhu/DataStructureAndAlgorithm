#include "String.h"
int main() {
	String s;
	cout << s<<endl;
	String s1 = "test";
	cout << s1 << endl;
	String s2(s1);
	cout << s2 << endl;
	s = s2;
	cout << s << endl;
	//String s3;
	//cout << "Please input a string" << endl;
	//cin >> s3;
	//cout << s3 << endl;

	//
	String s4 = "hello";
	String s5 = "world";
	String s6 = s4 + s5;
	cout << s6 << endl;
	s6 += s4;
	cout << s6 << endl;
	cout << (s6 == s4) << endl;
	String s7(s6);
	cout << (s6 == s7) << endl;
	//
	cout << (s4 > s5) << endl;
	cout << (s6 > s5) << endl;  //s6=helloworld,s5=world,因此此句应为false
	cout << (s6 > s4) << endl;
	return 0;
}