//5.最长回文子串

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"

解题思路 : 
	中心扩展法 , 从中间向两边查找 
	分两类 :  abba  ,  aba 
	计算出回文串的长度 , 进行比较
	辨别是哪种字符串 
	然后计算始末位置 , 进行返回
*/

class Solution 
{
public:
	
	string longestPalindrome(string s)
	{
		if (s == " " || s.length() < 0)
			return  " ";
		int len = s.length();
		int fin = 0;
		int start = 0; 
		int end = 0;
		for (int i = 0; i < len; ++i)
		{
			int max1 = func(s, i, i);
			int max2 = func(s, i, i + 1);
			fin = max(max1, max2);
			if (fin > end - start)
			{
				if (fin % 2 == 0)
				{
					start = i - fin / 2 + 1;
					end = i + fin / 2;
				}
				else
				{
					start = i - fin / 2;
					end = i + fin / 2;
				}
			}
		}
		string _f;
		for (int i = start; i <= end; ++i)
			_f .push_back( s[i]);
		return _f;
	}
	int func(string s, int right, int left)
	{
		int len = s.length();
		while (left >= 0 && right <len && s[left] == s[right])
		{
			--left;
			++right;
		}
		//回文串的长度
		//退出循环之后 , left 和 right还要向两边移一位 , 实际长度要 R - L + 1 -2 ==> R-L-1
		return right - left - 1;
	}
};

int main()
{
	Solution a;
	string tmp = a.longestPalindrome("babad");
	cout << tmp<< endl;
	
	return 0;
}
