//322.零钱兑换
#if 0
/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1

示例 2:

输入: coins = [2], amount = 3
输出: -1

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {

	}
};

解题思路 : 
	dp[i] , i 就代表所需要凑齐的钱数 .因为题目给出不能凑出的为 -1. 所以初始化dp的时候就为 -1.
	然后dp[0]表示 , 凑 0 所需要的硬币数 , 为 0;
	然后 , 凑dp[i] 的时候 , 就可以把问题分解为 , 从硬币堆中拿出一枚coins[j] , 然后所需要凑得就是 dp[i - coins[j]] , 就是说除去
	拿走的这一枚钱数 , 剩下的要凑的钱数(在钱数逐渐增长的过程中 , 凑dp[i-coins[j]] 肯定会再前面计算出来) , 
	然后就是比较 拿出的这枚硬币(coins[j]) 和 剩下要凑的钱数 dp[i - coins[j]] 一共所用的硬币数 , 
	哪个是最小的(因为硬币面额不同 ,所求得达到总共面额的硬币数量也会不同). 
	每拿出一种硬币 , 它所需要的硬币数为 dp[i-coins[j]] +1  . 后面这个 1 表示的就是你所拿出的这枚硬币
*/
#include<climits>
class Solution 
{
public:
	int coinChange(vector<int>& coins, int amount) 
	{
		vector<int> dp;
		dp.resize(amount + 1, -1);
		dp[0] = 0;
		int size = coins.size();
		for (int i = 1; i < amount+1; ++i)
		{
			int _min = INT_MAX;
			for (int j = 0; j < size; ++j)
			{
				if ((i - coins[j] >= 0) && (dp[i - coins[j]] != -1))
				{
					_min = min(_min, dp[i - coins[j]] + 1);
					dp[i] = _min;
				}
			}
		}
		return dp[amount];
	}
};

int main()
{
	vector<int> arr;
	/*arr.push_back(1);
	arr.push_back(3);
	arr.push_back(5);*/
	arr.push_back(2);

	Solution a;
	cout << a.coinChange(arr, 3) << endl;

	return 0;
}

#endif