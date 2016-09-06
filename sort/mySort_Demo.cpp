#include<iostream>
#include "mySort.h"
using namespace std;

int main()
{
	//insert sort test.
	vector<int> arr = { 9,4,6,10,12,15,3,7,4 };
	mySort<int>::insert_sort(arr);
	mySort<int>::print(arr);
	//merge sort test
	vector<int> arr1 = { 9,4,6,10,12,15,3,7,4 };
	mySort<int>::merge_sort(arr, 0, arr1.size() - 1);
	mySort<int>::print(arr);
	//shell srot test
	vector<int> arr2 = { 9,4,6,10,12,15,3,7,4,13,456,35};
	mySort<int>::shell_sort(arr2);
	mySort<int>::print(arr2);
	//quick sort test
	vector<int> arr3 = { 9,4,6,10,12,15,3,7,4,13,456,35,2,3,4,1,5,7,8,4 };
	mySort<int>::quick_sort(arr3,0,arr3.size()-1);
	mySort<int>::print(arr3);
	//bubble sort test
	vector<int> arr4 = { 35,2,3,4,1,5,7,8,4,4,5,6,2,1};
	mySort<int>::bubble_sort(arr4);
	mySort<int>::print(arr4);
	//select sort test
	vector<int> arr5 = { 35,2,3,4,1,5,7,8,4,4,5,6,2,1,234,56,134 };
	mySort<int>::select_sort(arr5);
	mySort<int>::print(arr5);
	//heap sort test
	vector<int> arr6 = { 0,2,3,4,1,5,7,8,4,4,5,6,2,1,234,56,134 };
	mySort<int>::heap_sort(arr6);
	mySort<int>::print(arr6);
	
	
    return 0;
}

