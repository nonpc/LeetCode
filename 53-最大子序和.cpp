//53.最大子序和
#if 0
/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

	}
};

解题思路：
		依次遍历数组 , 当发现加上一个数nums[i] <= nums[i] , 就说明下一个数nums[i+1]加上前面这些数没有增益效果
		所以舍去 , 从这个数nums[i]从新开始
		遍历一个数 , 就记录最大值 , 最后返回即可
*/

class Solution 
{
public:
	int maxSubArray(vector<int>& nums) 
	{
		int size = nums.size();
		if (size == 1)
			return nums[0];
		int sum = nums[0];
		int res = nums[0];
		for (int i = 1; i < size; ++i)
		{
			if (sum + nums[i] <= nums[i])
				sum = nums[i];
			else
				sum += nums[i];
			res = max(res, sum);
		}
		return res;
	}
};
int main()
{
	//输入: [-2,1,-3,4,-1,2,1,-5,4],
	vector<int> arr;
	arr.push_back(-2);arr.push_back(1);arr.push_back(-3);
	arr.push_back(4);arr.push_back(-1);arr.push_back(2);
	arr.push_back(1);arr.push_back(-5);arr.push_back(4);

	Solution a;
	cout<<a.maxSubArray(arr)<<endl;

	return 0;
}

#endif