//779.第K个语法符号
/*
在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）

例子:
输入: N = 1, K = 1
输出: 0

输入: N = 2, K = 1
输出: 0

输入: N = 2, K = 2
输出: 1

输入: N = 4, K = 5
输出: 1

解释:
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001

0110100110010110


注意：

	N 的范围 [1, 30].
	K 的范围 [1, 2^(N-1)].

*/

//超时方法
/*
思路 : 
	将所求行的字符串补全 , 然后得到所要的第K个字符
*/
#if 0
class Solution 
{
public:
	int kthGrammar(int N, int K) 
	{
		if (N < 1 || N > 30)
			return 0;
		if (K< 1 || K>(int)pow(2.0, (N - 1)))
			return 0;
		int count = 1;
		string arr = "0";
		int fin = func(N, K, count, arr) - '0';
		return fin;
	}
	int func(int N, int K, int count,string arr)
	{
		if (count == N)
		{
			//cout << arr << endl;
			//cout << arr[K-1] << endl;
			return arr[K - 1];
		}
		//cout << arr << endl;
		string::iterator it1 = arr.begin();
		string::iterator it2 = arr.end();
		int len = arr.size();
		for (int i = 0 ; i < len ; ++i)
		{
			if (*it1 == '0')
			{
				if (it1 + 1 != it2)
				{
					it1 = arr.insert(it1+1, '1');
					it2 = arr.end();
					++it1;
					continue;
				}
				if(it1 + 1 == it2)
				{
					arr.push_back('1');
					it2 = arr.end();
					continue;
				}
			}
			if (*it1 == '1')
			{
				if (it1 + 1 != it2)
				{
					it1 = arr.insert(it1 + 1, '0');
					it2 = arr.end();
					++it1;
					continue;
				}
				if (it1 + 1 == it2)
				{
					arr.push_back('0');
					it2 = arr.end();
				}
			}
		}
		++count;
		 return func(N, K, count, arr);
	}
};

int main()
{
	Solution a;
	cout<<a.kthGrammar(30, 98)<<endl;
	
	return 0;
}

#endif

//正确方法:
/*
思路分析 :
	首先基于用例对第 N 行进行分析：

	我们可以发现第 N 行由两部分组成：N - 1 行的序列构成 N 行的左半部分，N - 1 行序列取反构成 N 行的右半部分。
	直接对上面的观察进行模拟会导致位运算溢出问题，下面考虑直接对第 K 位进行分析

	对于第 N 行的第 K 个数，我们可以分析如下：

	第 N 行的长度为 2^(N-1)
	若 K <= N 行长度的一半 ，则其等于 N-1 行的第 K 个数
	反之，则其等于 N - 1 行的第  K - (N-1 行长度的一半) 个数取反

	基于上面的分析我们可以设计如下的递归算法：

	目标函数为输入 N 行 K 位直接输出该位的值，我们可以直接利用
	递归关系式就是上面分析的结论
	递归基选择了第一行和第二行的结果，共三种输出

*/

class Solution {
public:
	int kthGrammar(int N, int K) {
		if (N == 1) return 0;
		if (N == 2) return K == 1 ? 0 : 1;

		// 计算上一行的长度（本行长度折半）
		int prevLen = (1 << (N - 1)) / 2;
	

		cout << (1 << 3) << endl;

		if (K <= prevLen)
			// 位于前半段，则等价于上一行同样位置的值
			return kthGrammar(N - 1, K);
		else
			// 位于后半段，则等价于上一行相应位置的值取反
			// 返回值非 0 即 1，因此直接用 1 去减即可
			return 1 - kthGrammar(N - 1, K - prevLen);
	}
};

int main()
{
	Solution a;
	cout<<a.kthGrammar(4,7)<<endl;

	return 0;
}
