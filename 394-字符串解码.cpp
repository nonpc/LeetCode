
//394.字符串解码
/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".


class Solution {
public:
	string decodeString(string s) {

	}
};
解题思路：
这题看到括号的匹配，首先应该想到的就是用栈来解决问题。

其次，读完题目，要我们类似于制作一个能使用分配律的计算器。想象：如3[a2[c]b] 使用一次分配律-> 3[accb] 再使用一次分配律->accbaccbaccb

使用栈对次数和所对应的字符串进行保存res
遇到 '[' 就将所记录的字符串和次数进行压栈
遇到 ']' 就从栈顶获取次数 , 将保存字符串栈的栈顶累加 所记录的字符串res , 完成后将栈顶字符串赋给res , 用于嵌套.

*/

class Solution 
{
public:
	string decodeString(string s) 
	{
		string res = "";
		stack<int> nums;
		stack<string> str;
		int len = s.length();
		int num = 0;
		for (int i = 0; i < len; ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
				num = num * 10 + s[i] - '0';
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				res += s[i];
			else if (s[i] == '[')
			{
				nums.push(num);
				str.push(res);
				num = 0;
				res = "";
			}
			else
			{
				//s[i] == ']'
				int times = nums.top();
				nums.pop();
				for (int j = 0; j < times; ++j)
					str.top() += res;
				res = str.top();  //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                                        //若是左括号，res会被压入strs栈，作为上一层的运算
				str.pop();
			}
		}
		return res;
	}
};


int main()
{
	string n;
	cin >> n;
	Solution a;
	cout<<a.decodeString(n)<<endl;

	return 0;
}


