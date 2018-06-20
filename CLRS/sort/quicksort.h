#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iterator>
namespace CLRS {
	namespace SortAlgorithm {
		template <typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
		void quick_sort(const Iterator begin, const Iterator end, CompareType compare = CompareType()) {
			int size = std::distance(begin, end);
			if (size <= 1)
				return;
			const Iterator pivot = end - 1;
			Iterator p = partition(begin, end, pivot, compare);
			quick_sort(begin, p, compare);
			quick_sort(p + 1, end, compare);
		}

		template <typename Iterator, typename CompareType = std::less<std::iterator_traits<Iterator>::value_type>>
		Iterator partition(const Iterator begin, const Iterator end, const Iterator pivot, CompareType compare = CompareType()) {
			auto size = std::distance(begin, end);
			//size为变量 不能用static assert
			//static_assert(size >= 0, "qsort partion():begin >= end!");
			assert(size >= 0);
			assert(std::distance(begin, pivot) >= 0 && std::distance(pivot, end) > 0);
			int p = 0;
			for (int i = 0; i < size; ++i) {
				if (compare(*(begin + i), *pivot)) {
					std::swap(*(begin + i), *(begin + p));
					p++;
				}
			}
			std::swap(*(begin + p), *pivot);
			return begin + p;
		}
	}
}
#endif // !QUICKSORT_H
