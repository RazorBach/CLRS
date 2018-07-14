#ifndef KMP_MATCH_TEST_H
#define KMP_MATCH_TEST_H
#include "KMP_match.h"
#include <cassert>

namespace CLRS {
	namespace StringMatchAlgorithm {
		namespace KMP_Test {
			void testCase1() {
				std::string t = "acaabcaab";
				std::string p = "aab";
				assert(kmp_match(t.begin(), t.end(), p.begin(), p.end()) == std::vector<int>({ 2,6 }));
			}
			void testCase2() {
				std::string t = "acaabcaab";
				std::string p = "aabd";
				assert(kmp_match(t.begin(), t.end(), p.begin(), p.end()) == std::vector<int>({}));
			}

			void testCase3() {
				std::string t = "acaabcaab";
				std::string p = "";
				assert(kmp_match(t.begin(), t.end(), p.begin(), p.end()) == std::vector<int>({ 0,1,2,3,4,5,6,7,8,9 }));
			}
			void testCase4() {
				std::string t = "";
				std::string p = "aab";
				assert(kmp_match(t.begin(), t.end(), p.begin(), p.end()) == std::vector<int>({}));
			}

			void testCase5() {
				std::string t = "";
				std::string p = "";
				assert(kmp_match(t.begin(), t.end(), p.begin(), p.end()) == std::vector<int>({ 0 }));
			}


			void testAllCases() {
				testCase1();
				testCase2();
				testCase3();
				testCase4();
				testCase5();
				printf("KMP_Test done\n");
			}
		}
	}
}
#endif // !KMP_MATCH_TEST_H
