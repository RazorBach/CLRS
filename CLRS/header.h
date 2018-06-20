#ifndef HEADERH
#define HEADERH
#include<algorithm>
#include<memory>
#include<vector>
#include<iostream>
namespace CLRS {
	namespace SortAlgorithm {
		template <typename T> void printarray(T* array, size_t N) {
			for (size_t i = 0; i != N; ++i) {
				std::cout << *(array + i) << " ";
			}
			std::cout << std::endl;
		}
	}
}

#endif // !
