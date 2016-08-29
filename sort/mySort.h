//Author	: yqtao
//date		: 2016.08.28
//Email		: yqtao@whu.edu.cn
#ifndef MY_SORT_H
#define MY_SORT_H
#include<vector>
using namespace std;
template <typename T> 
class mySort {
public:
	/*
	Insert Sort
	@param arr is the arry to be sort
	*/
	static void insert_sort(vector<T>& arr) {			//声明成静态函数，可以直接以类名调用
		if (arr.empty()) return;
		int n = arr.size(),j;
		for (int i = 1; i < n; i++) {
			int temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		}
	}
	/*
	Shell Sort
	*/
	static void shell_sort(vector<T> & arr) {
		int i, j,n=arr.size();
		for (int d = n / 2; d >= 1; d = d / 2){ //定义步长{
			for (i = d; i < n; i++)	{			//一趟插入排序，当d=1时与插入排序完全相同
				int temp = arr[i];				//哨兵
				for (j =i - d; j >= 0 && temp < arr[j]; j -= d)
					arr[j + d] = arr[j];
				arr[j + d] = temp;
			}
		}
	}
	/*
	Quick Sort
	@param l is left index of array
	@param r is right index of array
	*/
	static void quick_sort(vector<T>& arr, int l, int r) {
		if (l < r) {
			int k = partion(arr, l, r);
			quick_sort(arr, l, k - 1);
			quick_sort(arr, k + 1, r);
		}
	}
	
	/*
	Merge sort
	@param l is left element of array
	@param r is right element of array
	@arr is the array to be sort
	*/
	static void merge_sort(vector<T>& arr, int l, int r) {
		if (l < r) {
			int m = (l + r) >> 1;
			merge_sort(arr, l, m);
			merge_sort(arr, m + 1, r);
			merge(arr, l, m, r);
		}
	}
private:
	/*
	merge function ,is to be use of merge_sort
	*/
	static void merge(vector<T>& arr, int l, int m, int r) {
		int i = l, j = m + 1,k=0;
		vector<T>temp(r - l + 1);
		while (i <= m&&j <= r) {
			if (arr[i] <= arr[j]) temp[k++] = arr[i++];
			else temp[k++] = arr[j++];
		}
		while (i <= m) temp[k++] = arr[i++];
		while (j <= r) temp[k++] = arr[j++];
		for (int i = 0; i < k; i++) arr[l + i] = temp[i];
	}
	/*
	partion : is to be use of quick sort
	*/
	static int partion(vector<T> & arr, int l, int r) {
		int i = l, j = r, pivot = arr[l];
		while (i < j) {
			while (i < j&&arr[j] >= pivot) j--;
			arr[i] = arr[j];
			while (i < j&&arr[i] <= pivot) i++;
			arr[j] = arr[i];
		}
		arr[i] = pivot;
		return i;
	}
public:
	static void print(vector<T>& arr) {
		for (auto c : arr)
			cout << c << " ";
		cout << endl;
	}
};
#endif // !MY_SORT_H
