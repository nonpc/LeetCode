//72.编辑距离(动态规划)
#if 0
/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

	插入一个字符
	删除一个字符
	替换一个字符

示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释:
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

class Solution {
public:
	int minDistance(string word1, string word2) {

	}
};

并不知道这题如何处理，官方题解让我见识了什么叫从1+1到微积分。在leetcode网站上看到了jianchao-li写的题解，感觉很棒，简单搬运和修改了一下。

题解：为应用动态规划，我们定义 dp[i][j] 为从 word1[0..i) 到word2[0..j)转换的的最小次数。

对于基本的情况，将一个字符串转换为一个空的字符串，所需操作的最小值就是字符串长度本身，因此很明显： dp[i][0]=i,dp[0][j]=j
对于一般情况，从 word1[0..i) 到 word2[0..j) ，假设我们已知了从 word1[0..i-1) 到 word2[0..j-1) 转换的次数，可以分两种情况讨论。

	if word1[i] == word2[j]
	此时的的情况就不用多讲，直接dp[i][j]=dp[i-1][j-1]就可以了。
	if word1[i] != word2[j]
	此时的情况比较复杂，有以下三种可能性。
	(1) 替换。如ror和ros，此时进行替换操作，r->s，此时dp[i][j]=dp[i-1][j-1] + 1;
	(2) 删除。如ross和ros，此时进行删除操作，delete s,此时dp[i][j]=dp[i-1][j] + 1
	(3) 插入。如ro和ros，此时进行插入操作，insert s,此时dp[i][j]=dp[i][j-1] + 1

此时可以看出当word1[i] != word2[j] ，dp[i][j] = min(dp[i][j]=dp[i-1][j-1] , dp[i][j]=dp[i][j-1] , dp[i][j]=dp[i-1][j]) + 1

自底向上的解法


*/

class Solution 
{
public:
	int minDistance(string word1, string word2) 
	{
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++) 
			dp[i][0] = i;
		for (int j = 1; j <= n; j++) 
			dp[0][j] = j;
		
		for (int i = 1; i <= m; i++) 
		{
			for (int j = 1; j <= n; j++) 
			{
				if (word1[i - 1] == word2[j - 1]) 
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else 
				{
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				}
			}
		}
		return dp[m][n];
	}
};

int main()
{
	Solution a;

	return 0;
}

#endif