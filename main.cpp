#include <iostream>
#include <algorithm>
#include "mysort.hpp"
#include "random_method.hpp"

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
void build_max_heapify(int * a, int size) {
	for(int i = size / 2 - 1; i >= 0; --i) {
		max_heapify(a, i, size);
	}
}
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

