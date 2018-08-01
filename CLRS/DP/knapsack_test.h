#ifndef KNAP_SACK_TEST_H
#define KNAP_SACK_TEST_H
#include "knapsack.h"
#include <cassert>

using CLRS::DpAlgorithm::KnapSack;
using CLRS::DpAlgorithm::knapsack01;

namespace CLRS {
	namespace DpAlgorithm {
		namespace KnapSackTest {
			
			void testCase1() {

				std::vector<KnapSack> kna = { KnapSack(1, 2), KnapSack(2, 4),KnapSack(3, 7),KnapSack(5, 11),KnapSack(7, 15),KnapSack(11, 23) };
				std::vector<int> ret;
				assert(knapsack01(kna, 20, ret) == 43);
				assert(ret == std::vector<int>({ 5,3,2,0 }));
			};
			void testCase2() {
				std::vector<KnapSack> kna = { KnapSack(1, 2), KnapSack(2, 4),KnapSack(3, 7),KnapSack(5, 11),KnapSack(7, 15),KnapSack(11, 23) };
				std::vector<int> ret;
				assert(knapsack_complete(kna, 20, ret) == 46);
				assert(ret == std::vector<int>({ 2, 2, 2, 2, 2, 2 ,0, 0}));
			};

			void testAllCases() {
				testCase1();
				//testCase2();
				testCase2();
				printf("KnapSackTest done\n");
			}
		}
	}
}
#endif // !HEAP_SORT_TEST_H
