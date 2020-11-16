#ifndef RANDOM_METHOD_HPP
#define RANDOM_METHOD_HPP
#include <random>
#include <functional>
#include <chrono>

namespace mtjrandom {
	// gennerate number in [m, n]
	int randint(int m, int n);
	// randomize an array with length of len
	void randmize_array(int * a, int len);
	// return a random number in [0, 1)
	double randreal();
};

namespace mtjrandom {
	// return random number between m and n, both included
	// if m > n return m
	int randint(int m, int n) {
		static std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
		if (m >= n) {
			return m;
		}
		std::uniform_int_distribution<int> di(m, n);
		return di(dre);
	}

};

namespace mtjrandom {
	// randomize an array with len elements
	void randmize_array(int *a, int len)
	{
		for (int i = 0; i < len; ++i)
		{
			auto index = randint(i, len - 1);
			std::swap(a[i], a[index]);
		}
	}
};

namespace mtjrandom {
	// return a random number in [0, 1)
	double randreal() {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		static std::default_random_engine dre(seed);
		std::uniform_real_distribution<double> di;
		return di(dre);
	}
};
#endif