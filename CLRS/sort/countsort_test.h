#ifndef COUNTSORT_TEST_H
#define COUNTSORT_TEST_H
#include "countsort.h"
#include "..\header.h"
#include <cassert>
#include <string>

using CLRS::SortAlgorithm::count_sort;
namespace CLRS {
	namespace SortAlgorithm {
		namespace CountSortTest {
			void testCase1() {
				std::vector<int> data = { 10,9,8,7,6,5,4,3,2,1 };
				count_sort(data.begin(), data.end(), 10);
				assert(std::is_sorted(std::begin(data), std::end(data)));
			};


			void testCase2() {
				std::vector<int> data = { 10,10,8,7,5,5,4,3,2,1 };
				count_sort(data.begin(), data.end(), 10);
				assert(std::is_sorted(std::begin(data), std::end(data)));
			};

			void testCase3() {
				std::vector<int> data = {5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 0 };
				count_sort(data.begin(), data.end(), 5);
				assert(std::is_sorted(std::begin(data), std::end(data)));
			}
			void testAllCases() {
				testCase1();
				testCase2();
				testCase3();
				printf("CountSortTest done\n");
			}
		}
	}
}
#endif // !COUNTSORT_TEST_H
