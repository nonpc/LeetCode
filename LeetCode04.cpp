LeetCode04寻找两个有序数组的中位数   


给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5


/*
解题思路 : 
将两个容器合并 , 然后进行排序
根据元素的个数(奇数 , 偶数)的不同 , 进行中位数求解
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {		
        int size1 = nums1.size();    
	int size2 = nums2.size();
	vector<int> tmp;
	for(int i = 0 ; i < size1;++i)
	{
		tmp.push_back(nums1[i]);
	}
	for(int i = 0 ; i < size2;++i)
	{
		tmp.push_back(nums2[i]);
	}

	sort(tmp.begin(),tmp.end());
	int mid = tmp.size()%2;
	int index = tmp.size()/2;
    if(mid != 0)  
	{   
		//1234567
        return ((double)(tmp[index]));
	}
	else
	{
		//123 45 678 
		return ((double) (tmp[index-1] + tmp[index])/2);
	}
	return double(0);
	}
};