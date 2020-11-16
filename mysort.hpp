#ifndef MYSORT_H
#define MYSORT_H
#include <random>
#include <algorithm>

namespace mysort {
	template<class T> class myquicksort;
	// 使用堆排序，同时包含建立二叉堆函数build_max_heapify
	// 维护二叉堆函数max_heapify
	template<class T> class myheapsort;
};
template<class T>
class mysort::myquicksort {
	protected:
		void exchang(T & a, T & b) {
			T tmp = a;
			a = b;
			b = tmp;
		}
		std::default_random_engine dre;
	public:
		void operator() (T a[], int i, int j) {
			if(i < j) {
				int m = partition(a, i, j);
				operator()(a, i, m - 1);
				operator()(a, m + 1, j);
			}
		}

		int partition(T a[], int i, int j);


};

template<class T>
int  mysort::myquicksort<T>::partition(T a[], int p, int r) {
	// 为了使递归树划分的尽可能均匀，
	// 需要每次从序列中随机地选择一个数
	std::uniform_int_distribution<int> di(p, r);
	exchang(a[r], a[di(dre)]);
	T x = a[r];
	int i = p - 1;
	for(int j = p; j < r; ++j) {
		if(a[j] <= x) {
			++i;
			exchang(a[i], a[j]);
		}
	}
	exchang(a[i + 1], a[r]);
	return i + 1;
}

template<class T>
class mysort::myheapsort {
public:
	// 维护一个最大堆
	void max_heapify(T * a, int i, int size);
	// 建立二叉堆
	void build_max_heapify(T * a, int size);
	// 堆排序
	void operator()(T * a, int size);
};
template<class T>
void mysort::myheapsort<T>::max_heapify(T * a, int i, int size) {
	int largest = i;
	while(i < size) {
		largest = i;
		if(2 * i + 1 < size && a[2 * i + 1] > a[largest]) {
			largest = 2 * i + 1;
		}
		if(2 * i + 2 < size && a[2 * i + 2] > a[largest]) {
			largest = 2 * i + 2;
		}
		if(largest == i) {
			break;
		} else {
			std::swap(a[i], a[largest]);
			i = largest;
		}
	}
}

template<class T>
void mysort::myheapsort<T>::build_max_heapify(T * a, int size) {
	for(int i = size / 2 - 1; i >= 0; --i) {
		max_heapify(a, i, size);
	}
}

template<class T>
void mysort::myheapsort<T>::operator()(T* a, int size) {
	for(;size >= 2; size--) {
		build_max_heapify(a, size);
		std::swap(a[0], a[size - 1]);
	}
}

#endif

