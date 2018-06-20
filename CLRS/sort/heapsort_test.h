#ifndef HEAP_SORT_TEST_H
#define HEAP_SORT_TEST_H
#include "heapsort.h"
#include "..\header.h"
#include <cassert>

using CLRS::SortAlgorithm::HeapSort;
namespace CLRS {
	namespace SortAlgorithm {
		namespace HEAPSORTTEST {
			void testCase1() {
				int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
				HeapSort<int*> heap_sort;
				heap_sort(data, data + 10);
				//printarray(data, 10);
				assert(std::is_sorted(std::begin(data), std::end(data)));
			};

		}
	}
}
#endif // !HEAP_SORT_TEST_H
