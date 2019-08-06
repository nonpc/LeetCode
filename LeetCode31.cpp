//31.下一个排序
#if 0
/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

54312
43512

解题思路 : 

大前提 , 假设序列是按照逆序(从大到小) 排列的

1.如果数组长度为1或者为0
			  直接返回
	   2.如果数组长度为2
			  直接交换数组中两个值的位置
			  返回
	   3.从最后一个值开始向前查找（循环1）
				 如果[这个值(i)]比[前一个值(i-1)]大(判断) , 记录index1
		 再从最后往前查找截止到[这个值]（循环2）		   
				 如果出现有值大于[前一个值(i-1)] (判断) , 记录index2 , 设置标志位
		检查标志位 , 若为真
			   交换这两个值(index1,index2)的位置
			   然后将[这个值(i)]之后的序列逆置

	   4.排除前面三种情况，说明排序已经最大的序列
		  遍历从前到中间的位置(循环)
				 数字从两边分别交换数值，一直到中间

例子 : 原序列  158 476 531
                             4     5    (上方序列中要交换的两个数)
						index   index2
交换之后 		  158 576 431
                             5 (之后的都要逆置)


*/


class Solution 
{
public:
	void nextPermutation(vector<int>& nums)
	{
		//为空
		if (nums.empty())
			return;
		int size = nums.size();
		if (size == 1)
		{
			//cout << nums[0];
			return;
		}
			
		int index1 = -1;
		int index2 = -1;
		bool flag = false;
		//情况2
		if (size == 2)
		{
			/*cout << nums[0] << "," << nums[1] << "->";*/
			swap(nums[0], nums[1]);
			/*cout << nums[0] << "," << nums[1] ;*/
			return;
		}
		//情况三 , 找到后一个比前一个大的数
		int i = size - 1;
		for (i = size - 1; i > 0; --i)
		{
			if (nums[i] > nums[i - 1])
			{
				index1 = i - 1;
				break;
			}
		}
		//最大值在头 , 要做处理 , 不然接下来会越界
		if (i == 0)
			i = 1;
		//从后往前找 , 找到比[前一个值]大的数
		for (int j = size - 1; j >= i; --j)
		{
			if (nums[j] > nums[i - 1])
			{
				index2 = j;
				flag = true;
				break;
			}
		}
		//判断标志位
		if (flag)
		{
			/*for (int k = 0; k < size; ++k)
				cout << nums[k] << ",";
			cout << "->";*/
			swap(nums[index1], nums[index2]);
			int m = index1+1;
			int n = size - 1;
			//控制循环的次数
			//将[前一个值]之后的全部逆置 , 例如 : 158 476 531  [4和5互换 , 换完之后要将5以后的逆置 ]
			for(int z = 0 ; z < (size-index1)/2 ; ++z)
			{
				swap(nums[m++], nums[n--]);
			}
			/*for(int k = 0 ; k < size ; ++k)
				cout << nums[k] << ",";
			cout << endl;*/
			return;
		}

		//说明是最大排序(从大到小)
		vector<int>::iterator it1 = nums.begin();
		vector<int>::iterator it2 = nums.end();
		/*for (int k = 0; k < size; ++k)
			cout << nums[k] << ",";
		cout << "->";*/
		
		//逆置
		for (int k = 0, p = size - 1 ; k < size / 2; ++k , --p)
		{
			swap(nums[k], nums[p]);
		}
		/*for (int k = 0; k < size; ++k)
			cout << nums[k] << ",";
		cout << endl;*/
	}
};

int main()
{
	Solution a;
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(1);

	a.nextPermutation(arr);

	return 0;
}

#endif