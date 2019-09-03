//392.判断子序列
#if 0
/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

示例 1:
s = "abc", t = "ahbgdc"

返回 true.

示例 2:
s = "axc", t = "ahbgdc"

返回 false.

class Solution {
public:
	bool isSubsequence(string s, string t) {

	}
};

解题思路 :
	依次遍历序列 , 如果s[k] == t[i] , 则++k;
	只要序列中有按照子序顺序出现的字符 , 则说明序列中存在子序
*/

class Solution 
{
public:
	bool isSubsequence(string s, string t)
	{
		int lenS = s.length();
		int lenT = t.length();

		if (lenS == 0 && lenT == 0)
			return true;
		if (lenS == 0 && lenT != 0)
			return true;
		int j = 0;
		for (int i = 0; i < lenT; ++i)
		{
			if (s[j] == t[i])
				++j;
			if (j == lenS)
				return true;
		}
		return false;
	}
};

#endif