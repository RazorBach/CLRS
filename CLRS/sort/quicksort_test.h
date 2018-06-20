#ifndef QUICKSORT_TEST_H
#define QUICKSORT_TEST_H
#include "quicksort.h"
#include "..\header.h"
#include <cassert>
#include <string>
#include <list>

using CLRS::SortAlgorithm::quick_sort;
namespace CLRS {
	namespace SortAlgorithm {
		namespace QuickSortTest {
			void testCase1() {
				int data[10] = { 10,9,8,7,6,5,4,3,2,1};
				quick_sort(data, data + 10);
				assert(std::is_sorted(std::begin(data), std::end(data)));
			};


			void testCase2() {
				int data[10] = { 10,10,8,7,5,5,4,3,2,1 };
				quick_sort(data, data+10);
				assert(std::is_sorted(std::begin(data), std::end(data)));
			};
			
			void testCase3() {
				
				int data[10] = { 1,2,3,4,5,6,7,8,9,10};
				quick_sort(data, data + 10);
				assert(std::is_sorted(std::begin(data), std::end(data)));
			}

			void testCase4() {
				std::list<int> slist = { 1,2,4,5,6,10,3,7 };
				//quick_sort(slist.begin(), slist.end());
				auto l1 = ++slist.begin();
				std::swap(*l1,*slist.begin());

			}
			void testAllCases() {
				testCase1();
				testCase2();
				testCase3();
				testCase4();
				printf("QuickSortTest done\n");
			}
		}
	}
}
#endif // !QUICK_SORT_TEST_H
