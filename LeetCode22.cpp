//22.括号生成
#if 0
/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

思路:
我们可以生成所有 2^{2n} 个 '(' 和 ')' 字符构成的序列。然后，我们将检查每一个是否有效。

算法 : 
为了生成所有序列，我们使用递归。长度为 n 的序列就是 '(' 加上所有长度为 n-1 的序列，以及 ')' 加上所有长度为 n-1 的序列。
为了检查序列是否为有效的，我们会跟踪 平衡，也就是左括号的数量减去右括号的数量的净值。如果这个值始终小于零或者不以零结束，该序列就是无效的，否则它是有效的。

解题思路：

这道题给定一个数字n，让生成共有n个括号的所有正确的形式，对于这种列出所有结果的题首先还是考虑用递归来解。

由于字符串只有左括号和右括号两种字符，而且最终结果必定是左括号3个，右括号3个，
所以我们定义两个变量left和right分别表示剩余左右括号的个数。

如果在某次递归时，左括号的个数大于右括号的个数，说明此时生成的字符串中右括号的个数大于左括号的个数，
即会出现')('这样的非法串，所以这种情况直接返回，不继续处理。

如果left和right都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，则存入结果中后返回。

如果以上两种情况都不满足，若此时left大于0，则调用递归函数，
注意参数的更新，若right大于0，则调用递归函数，同样要更新参数。

*/

class Solution 
{
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> res;
		string out;
		func(n, n, out, res);
		return res;
	}
	void func(int left, int right, string out, vector<string>& res)
	{
		//出现 ')''(' 这样的情况 , 递归结束条件
		if (left > right)
			return;
		//正常匹配完成 , 压入容器
		if (left == 0 && right == 0)
			res.push_back(out);
		else
		{
			if (left > 0)
				func(left - 1, right, out+'(', res);
			if (right > 0)
				func(left, right - 1, out+')', res);
		}
	}
};

int main()
{
	Solution  a;
	vector<string> fin = a.generateParenthesis(3);
	
	while (!fin.empty())
	{
		cout << fin.back() << endl;
		fin.pop_back();
	}
	return 0;
}

#endif