//电话号码的字母组合
#if 0
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

解题思路 : (全排列的变形)
通过设置vector<string> tab;与9键进行对照 , 包括0 和 1 键;
通过digits[index] - '0' 计算出在tab中所对应的下标
设置string path 进行字符串的保存
对于tab[i][ ]进行递归调用 , 得到每一个字符所对应的全排列
最后将结果保存在 vector<string> res  上 , 进行返回

*/

class Solution 
{
public:
	//传入0和1是为了正好能通过digits[ ] - '0' 计算出所对应在tab中的下标
	vector<string> tab = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> letterCombinations(string digits)
	{
		if (digits.size() == 0)return {};
		vector<string> res;
		string path;
		dfs(res, digits, 0, path);
		return res;
	}
	void dfs(vector<string>& res, string digits, int di, string path)
	{
		if (di == digits.size())
		{
			res.push_back(path);
		}
		else
		{
			//计算出当前字符串中(digits)的数字所对应tab的下标
			int num = digits[di] - '0';
			//字符串全排列的变形
			for (int ti = 0; ti < tab[num].size(); ti++)
			{
				path.push_back(tab[num][ti]);
				di++;
				dfs(res, digits, di, path);
				di--;
				path.pop_back();
			}
		}
	}
};


int main()
{
	Solution a;
	vector<string>b = a.letterCombinations("23");
	for (int i = 0; i < b.size(); ++i)
	{
		cout << b[i] << endl;
	}

	return 0;
}

#endif
