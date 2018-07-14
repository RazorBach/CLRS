#ifndef BRUTAL_MATCH_H
#define BRUTAL_MATCH_H
#include <vector>
namespace CLRS {
	namespace StringMatchAlgorithm {
		//返回所有匹配位置 ，未找到返回{}，如果pattern为空返回{0,1,2····T.size()}
		template <typename IteratorT, typename IteratorP>
		std::vector<int> match(const IteratorT iterT_begin, const IteratorT iterT_end,
			const IteratorP iterP_begin, const IteratorP iterP_end) {
			//T - 待匹配字符串 P - 模式
			typedef typename std::iterator_traits<IteratorT>::value_type T;
			typedef typename std::iterator_traits<IteratorP>::value_type P;
			static_assert(std::is_same<T,P>::value, "can only match same type!");
			int lenT = std::distance(iterT_begin, iterT_end);
			int lenP = std::distance(iterP_begin, iterP_end);
			if (lenT < 0)
				throw std::invalid_argument("iterT_begin > iterT_end");
			if (lenP < 0)
				throw std::invalid_argument("iterP_begin > iterP_end");
			std::vector<int> ret;
			for (int i = 0; i <= lenT - lenP; ++i) {
				//改变循环写法以处理lenP = 0 的情况
				int j = 0;
				for (; j < lenP && *(iterT_begin + i + j) == *(iterP_begin + j); ++j){
				}
				if (j == lenP) {
					ret.push_back(i);
				}
			}
			return ret;
		}
	}
}
#endif // !BRUTAL_MATCH_H
