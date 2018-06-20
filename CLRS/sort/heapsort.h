#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <iterator>
namespace CLRS {
	namespace SortAlgorithm {

	template <typename Iterator, typename CompareType = std::less<typename std::iterator_traits<Iterator>::value_type>>
	class HeapSort
	{
	public:
		//typedef typename std::iterator_traits<Iterator>::value_type T;
		void operator() (const Iterator from,const Iterator end,CompareType compare = CompareType()) {
			size_ = std::distance(from, end);
			from_ = from;
			setupHeap(compare);
			while (size_ > 0) {
				std::swap(*from_, *(from + size_ - 1));
				size_--;
				heapify(0, compare);
			}
		}
	protected:
		void setupHeap(CompareType compare = CompareType()) {
			if (size_ <= 1)
				return;
			for (int index = (size_ - 1) / 2; index >= 0; --index) {
				heapify(index, compare);
			}
		}
		
		void heapify(std::size_t index, CompareType compare = CompareType()) {
			if (index >= size_)
				//todo 是否要throw
				//throw std::out_of_range("Out Of Range");
				return;
			auto max_i = index;
			auto left_i = left(index);
			auto right_i = right(index);
			if (left_i && compare(*(from_ + max_i) ,*(from_ + left_i)))
				max_i = left_i;
			if (right_i && compare(*(from_ + max_i) , *(from_ + right_i)))
				max_i = right_i;
			if (max_i != index) {
				std::swap(*(from_ + index), *(from_ + max_i));
				heapify(max_i, compare);
			}
		}

		inline std::size_t parent(std::size_t index) {
			if (index < 0 || index >= size_)
				throw std::invalid_argument("index error");
			if (!index) return 0;
			return (index - 1) / 2;
		}

		inline std::size_t left(std::size_t index) {
			if (index < 0 || index >= size_)
				throw std::invalid_argument("index error");
			if (size_ < 2 || index >(size_ - 2) / 2)
				//0代表没有左孩子
				return 0;
			return 2 * index + 1;
		}

		inline std::size_t right(std::size_t index) {
			if (index < 0 || index >= size_)
				throw std::invalid_argument("index error");
			if (size_ < 3 || index >(size_ - 3) / 2)
				return 0;
			return  2 * index + 2;
		}

	private:
		Iterator from_; //堆根节点位置
		std::size_t size_; //堆大小 注意与index切换
	};

	}
}

#endif