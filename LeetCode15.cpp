//三数之和
#if 0
/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

时间复杂度为O(n2)，外面一层for循环，以每个元素 nums[i] 作为三元组重的一个元素，
然后从剩余的元素中找出二者之和满足0-nums[i]的两个元素。通过一层while循环，
从剩余所有元素的首位两个元素开始找，不断向中间逼近。

过滤重复：因为已经对数组进行排序，所以相同的整数一定会连在一起。
当使用for循环进行遍历时，如果当前指向元素 nums[i] 与 nums[i-1]相同，
则可跳出本次循环，执行 i++，从而达到过滤重复的目的。

*/
class solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		//排序
		sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int length = nums.size();
        for(int i = 0; i < length - 1; i++) 
		{
			//去重 , 下一个得出的结果肯定和前一个相同
            if(i != 0 && nums[i] == nums[i - 1]) 
				continue;
			//后两个数需满足 == 0 - nums[i]
            int target = 0 - nums[i];
			//两数中的前一个
            int left = i + 1;
			//两数中的后一个
            int right = length - 1;
            while(left < right) 
			{
                if(left != i + 1 && nums[left] == nums[left - 1]) 
				{
                    left++;
                    continue;
                }

				if(right != length - 1 && nums[right] == nums[right + 1]) 
				{
                    right--;
                    continue;
                }
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    left++;
                    right--;
                }
                else if(sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result;
    }
};

//144ms , 完成代码(高端玩家) 
#if 0
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> m;
        int arraylen = nums.size();
        
        int left,right;
        
        sort(nums.begin(),nums.end());
        
        if(nums.empty()) return m;
        if(nums[0]>0||nums[arraylen-1]<0) return m;
        
        for(int i=0;i<arraylen;i++)
        {
            left = i+1;
            right = arraylen-1;
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1])    continue;
            while(left<right)
            {   
                if(nums[i]==0-nums[left]-nums[right])
                {
                    if(left==i+1||right==arraylen-1)
                    {
                        m.push_back(vector<int>{nums[i],nums[left],nums[right]});
                        left++;
                        right--;
                    } 
                    else if(nums[left]==nums[left-1]) left++;
                    else if(nums[right]==nums[right+1]) right++;
                    else 
                    {
                        m.push_back(vector<int>{nums[i],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                }
                else if(nums[i]>0-nums[left]-nums[right]) right--;
                else left++;   
            }
        }
        return m;
        
        
    }
};
#endif

int main()
{
	vector<int>nums ;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);

	solution tmp;
	vector<vector<int>> aa = tmp.threeSum(nums);
	
	return 0;
}

#endif