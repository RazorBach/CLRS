#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <vector>
#include <algorithm>
namespace CLRS {
	namespace DpAlgorithm {
		
	struct KnapSack {
		KnapSack(int we = 0,int val = 0):weight(we),value(val){}

		int weight;
		int value;
	};

	/*int knapsack01(std::vector<KnapSack> knapsack, int maxweight, std::vector<int>& ret) {
		int n = knapsack.size();
		if (!n) return 0;
		std::vector<std::vector<int>> mat(n + 1, std::vector<int>(maxweight + 1, 0));
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < maxweight + 1; ++j) {
				if (j < knapsack[i - 1].weight)
					mat[i][j] = mat[i - 1][j];
				else
					mat[i][j] = std::max(mat[i - 1][j], mat[i - 1][j - knapsack[i - 1].weight] + knapsack[i - 1].value);
			}
		}
		int i = n, j = maxweight;
		while (j > 0) {
			if (mat[i][j] == mat[i - 1][j])
				i--;
			else {
				ret.push_back(--i);
				j = j - knapsack[i].weight;
			}
		}
		return mat[n][maxweight];
	}*/

	//01背包，每个物品只能拿一次
	int knapsack01(std::vector<KnapSack> knapsack, int maxweight, std::vector<int>& ret) {
		int n = knapsack.size();
		std::vector<int> cnt(maxweight + 1, 0);
		//储存当weight = i时，第一次拿走的物品下标！
		std::vector<int> tmp(maxweight + 1, -1);
		//可以把O(n*maxweight)的空间复杂度减小到O(2*maxweight) 如果不需要下标的话就只用O(maxweight)即可
		for (int i = 0; i < n; ++i) {
			//注意体会和完整背包问题的区别
			for (int j = maxweight; j >= knapsack[i].weight; --j) {
				if (knapsack[i].value + cnt[j - knapsack[i].weight] > cnt[j]) {
					cnt[j] = knapsack[i].value + cnt[j - knapsack[i].weight];
					tmp[j] = i;
				}
			}
		}
		//把完整拿走的物品下标输出出来
		int k = maxweight;
		while (k > 0) {
			ret.push_back(tmp[k]);
			k -= knapsack[tmp[k]].weight;
		}
		return cnt[maxweight];
	}

	//完全背包，每个物品随便拿
	int knapsack_complete(std::vector<KnapSack> knapsack, int maxweight, std::vector<int>& ret) {
		int n = knapsack.size();
		std::vector<int> cnt(maxweight + 1, 0);
		std::vector<int> tmp(maxweight + 1, -1);
		for (int i = 0; i < n; ++i) {
			//注意体会和01背包问题的区别。参照S15.1钢条切割问题
			for (int j = knapsack[i].weight; j <= maxweight; ++j) {
				if (knapsack[i].value + cnt[j - knapsack[i].weight] > cnt[j]) {
					cnt[j] = knapsack[i].value + cnt[j - knapsack[i].weight];
					tmp[j] = i;
				}
			}
		}
		int k = maxweight;
		while (k > 0) {
			ret.push_back(tmp[k]);
			k -= knapsack[tmp[k]].weight;
		}
		return cnt[maxweight];
	}
	}
}
#endif // !KNAPSACK_H
