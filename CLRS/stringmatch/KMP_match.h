#ifndef KMP_MATCH_H
#define KMP_MATCH_H
#include <vector>
namespace CLRS {
	namespace StringMatchAlgorithm {
		//返回所有匹配位置 ，未找到返回{}，如果pattern为空返回{0,1,2····T.size()}
		template <typename IteratorT, typename IteratorP>
		std::vector<int> kmp_match(const IteratorT iterT_begin, const IteratorT iterT_end,
			const IteratorP iterP_begin, const IteratorP iterP_end) {
			//T - 待匹配字符串 P - 模式
			typedef typename std::iterator_traits<IteratorT>::value_type T;
			typedef typename std::iterator_traits<IteratorP>::value_type P;
			static_assert(std::is_same<T, P>::value, "can only match same type!");
			int lenT = std::distance(iterT_begin, iterT_end);
			int lenP = std::distance(iterP_begin, iterP_end);
			if (lenT < 0)
				throw std::invalid_argument("iterT_begin > iterT_end");
			if (lenP < 0)
				throw std::invalid_argument("iterP_begin > iterP_end");
			//todo lenP为0应该如何处理 暂时返回vector<int>(0,1,2,···,T.size())
			if (!lenP)
				return match(iterT_begin, iterT_end, iterP_begin, iterP_end);
			std::vector<int> ret;
			if (lenT < lenP)
				return ret;
			std::vector<int> prefix = compute_prefix_fuction(iterP_begin, iterP_end);
			int m = 0;
			for (int i = 0; i < lenT; ++i) {
				while (m > 0 && *(iterP_begin + m) != *(iterT_begin + i))
					m = prefix[m - 1];
				if (*(iterP_begin + m) == *(iterT_begin + i))
					m++;
				if (m == lenP) {
					ret.push_back(i - m + 1);
					m = prefix[m - 1];
				}
			}
			return ret;
		}


		//计算P的前缀函数
		template <typename IteratorP>
		std::vector<int> compute_prefix_fuction(const IteratorP iterP_begin, const IteratorP iterP_end) {
			int lenP = std::distance(iterP_begin, iterP_end);
			std::vector<int> prefix(lenP, 0);
			int m = 0;
			for (int i = 1; i < lenP; ++i) {
				while (m > 0 && *(iterP_begin + m) != *(iterP_begin + i))
					m = prefix[m - 1];
				if (*(iterP_begin + m) == *(iterP_begin + i))
					m++;
				prefix[i] = m;
			}
			return prefix;
		}

	}
}
#endif // !KMP_MATCH_H
