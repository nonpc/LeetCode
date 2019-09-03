//50.pow
#if 0
/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000

示例 2:

输入: 2.10000, 3
输出: 9.26100

示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25

说明:

	-100.0 < x < 100.0
	n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。


解题思路：
根据 n 的二进制的表示 , 为1 的就需要乘 , 不为1 的就不需要乘
x 需要每一轮都乘  x *= x;
若n == 5;   5 == 101(2进制);  x == 2;
2^[(1*2^2) + (0*2^1) + (1*2^0)]  === 2^(1*2^2) * 2^(0*2^1) * 2^(1*2^0)
*/
int main()
{
	double x;
	long long n;
	cin >> x >> n;

	double tmp = x, res = 1.0;
	long long m = n;
	m = abs(m);
	while (m > 0)
	{
		if ((m & 1) == 1)
			res *= tmp;
		m >>= 1;
		tmp *= tmp;
	}
	if (n > 0)
		cout << setiosflags(ios::fixed) << setprecision(5) << res << endl;
	else
		cout << 1.0 / res << endl;

}

#endif