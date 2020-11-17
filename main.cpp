#include <iostream>
#include <algorithm>
#include "mysort.hpp"
#include "random_method.hpp"

// 维护最大堆性质，d叉堆也是类似的方法
void max_heapify(int * a, int i, int size) {
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
// 建立一个最大堆
void build_max_heapify(int * a, int size) {
	for(int i = size / 2 - 1; i >= 0; --i) {
		max_heapify(a, i, size);
	}
}
// 使用二叉堆进行排序，对于任意d叉堆，也可以上面相似的方法
void heap_sort(int * a, int size) {
	for(;size >= 2; size--) {
		build_max_heapify(a, size);
		std::swap(a[0], a[size - 1]);
	}
}
int main() {
	int len = 10;
	double * a = new double[len];
	
	for(int i = 0; i < len; ++i) {
		a[i] = 100 * mtjrandom::randreal();
	}

#if 0
	mysort::myquicksort<int> sort;
	sort(a, 0, 7);
#endif
	mysort::myheapsort<double> sort;
	sort(a, 8);
	for(int i = 0; i < 8; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	delete []a;
	return 0;
}

// 优先队列的实现不一定是堆，也有可能是Young tableau（Young氏矩阵）
class priorityQueue {
protected:
	int * a;
	// 当前队列的长度
	int size;
	// 决定优先顺序的函数
	bool (*cmp) (int * , int *);

public:
	// 构造函数
	// _size表示优先队列的大小，如果空间不够，会自动扩展空间
	// op是决定优先顺序的
	priorityQueue(int _size, bool (*op) (int *, int *)):size(_size), cmp(op) {
		a = new int[size];
	}
	// 拷贝构造函数，防止浅拷贝
	priorityQueue(const priorityQueue& que):size(que.size), cmp(que.cmp) {
		a = new int[size];
	}
	// 析构函数
	~priorityQueue() {
		delete []a;
	}
	// 返回基本信息，当前优先队列的长度
	int len() {return size;}

public:
	// 返回当前最大元素
	int top() { return a[0];}

	// 去掉当前最大元素
	void pop();

	// 插入一个元素
	void push();
	
	// 将元素i的值增加到newkey，否则报错
	bool increase(int i, int newkey);

};

void priorityQueue::pop() {
	a[0] = -10000000;
}
