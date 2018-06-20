#ifndef COUNTSORT_H
#define COUNTSORT_H
#include <vector>
namespace CLRS {
	namespace SortAlgorithm {
		template <typename Iterator>
		//计数排序：基于整数排序 需要提供上界
		void count_sort(const Iterator begin, const Iterator end, const typename std::iterator_traits<Iterator>::value_type& max_val) {
			typedef typename std::iterator_traits<Iterator>::value_type T;
			static_assert(std::is_integral<T>::value, " must be integers");
			int size = std::distance(begin, end);
			if (size <= 1)
				return;
			std::vector<T> countV(max_val + 1, 0);
			std::vector<T> retV(size, 0);
			for (int i = 0; i < size; ++i) {
				countV[*(begin + i)]++;
			}
			for (int i = 1; i <= max_val; ++i) {
				countV[i] += countV[i - 1];
			}
			//错误
			/*for (int i = max_val ; i >= 1; --i) {
				while (countV[i] > countV[i - 1]) {
					retV[countV[i] - 1] = i;
					countV[i]--;
				}
			}*/
			for (int i = size - 1; i >= 0; --i) {
				//countV[*(begin+i)]为<=*(begin+i)的元素个数，下标要-1
				retV[countV[*(begin + i)] - 1] = *(begin + i);
				countV[*(begin + i)]--;
			}
			std::copy(retV.begin(), retV.end(), begin);
		}
	}
}
#endif // !COUNTSORT_H
