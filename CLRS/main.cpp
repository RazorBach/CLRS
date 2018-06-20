#include "sort\heapsort_test.h"
#include "sort\quicksort_test.h"
#include "stringmatch\brutal_match_test.h"
#include "stringmatch\KMP_match_test.h"
#include "sort\countsort_test.h"
#include "DP\knapsack_test.h"
#include "disjoint_set\LCA.h"

int main() {
	CLRS::SortAlgorithm::HEAPSORTTEST::testCase1();
	CLRS::SortAlgorithm::QuickSortTest::testAllCases();
	CLRS::SortAlgorithm::CountSortTest::testAllCases();
	CLRS::StringMatchAlgorithm::Brutal_Test::testAllCases();
	CLRS::StringMatchAlgorithm::KMP_Test::testAllCases();
	CLRS::DpAlgorithm::KnapSackTest::testAllCases();
	CLRS::DisjointSet::main();
	system("pause");
	return 0;
}