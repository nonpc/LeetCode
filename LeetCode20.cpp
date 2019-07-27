//20.有效的括号
#if 0
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

	左括号必须用相同类型的右括号闭合。
	左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true

示例 2:

输入: "()[]{}"
输出: true

示例 3:

输入: "(]"
输出: false

示例 4:

输入: "([)]"
输出: false

示例 5:

输入: "{[]}"
输出: true


解题思路 : 
建立一个vector容器 (当作栈来试用) , 
如果匹配到'(' , '{' , '[' , 就入栈 
如果遇到')' , '}' , ']' , 就与栈顶元素相匹配 , 匹配成功 , 就出栈 ; 匹配失败 , 返回false
最后还要判断一下栈是否为空 , 例如 : '('


执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了89.13%的用户

*/
class Solution 
{
public:
	bool isValid(string s) 
	{
		if (s.empty())
			return true;
		vector<char> fin;
		int len = s.size();
		cout << len << endl;
		if (s[0] == ')' || s[0] == '}' || s[0] == ']')
			return false;
		fin.push_back(s[0]);
		vector<char>::iterator it = fin.end();
		for(int i = 1;i < len;++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				if (i + 1 == len)
					return false;
				fin.push_back(s[i]);
			}
			
			if (s[i] == ')')
			{
				it = fin.end();
				if (fin.empty())
					return false;
				if (*(--it) == '(')
				{
					fin.pop_back();
				}	
				else
				{
					return false;
				}
			}
			if (s[i] == '}')
			{
				it = fin.end();
				if (fin.empty())
					return false;
				if (*(--it) == '{')
				{
					fin.pop_back();
				}
				else
				{
					return false;
				}
			}
			if (s[i] == ']')
			{
				it = fin.end();
				if (fin.empty())
					return false;
				if (*(--it) == '[')
				{
					fin.pop_back();
				}
				else
				{
					return false;
				}
			}
		}
		if (!fin.empty())
		{
			return false;
		}
		return true;
	}
};

int main()
{
	Solution a;
	//if (a.isValid("(){}[]"))
	//if (a.isValid("([)]"))
	if (a.isValid(""))
		cout << "ok" << endl;
	else
		cout << "err" << endl;
	return 0;
}

#endif