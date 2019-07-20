//成最多水的容器
#if 0
/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49

*/
class solution 
{
public:
    int maxArea(vector<int>& height) 
	{
		/*
		方法二的另一种写法
		用时 16ms
		*/
		int max=0;
        for(int left=0, right=height.size()-1 ; left<right; )
        {
            int temp=min(height[left],height[right]) * (right-left); //计算当前面积
            if(max< temp)
                max=temp;
            if(height[left]<height[right])
                left++;
            else
                right--;
            
        }
        return max;

#if 0
		/*
		方法二 , 双迭代器法
		一个在头 , 一个在尾
		面积受短的高度影响 , 所以将短的逐渐向高的靠近 , 计算大小 , 并更新
		*/
		vector<int>::iterator it1 = height.begin();
		vector<int>::iterator it2 = height.end();
		int Max = 0;
		--it2;
		while(it1 != it2)
		{
			/*int high = *it1>*it2?*it2:*it1;
			int width = it2 - it1;
			Max = max(Max,high*width);*/
			//vs 上可以用 , 实际提交的时候就报错 , 郁闷
			//Max = max(Max,min(*it1,*it2) * (it2 - it1));
			Max = max(Max,(*it1>*it2?*it2:*it1) * (it2 - it1));
			if(*it1 > *it2)
				--it2;
			else
				++it1;
		}
		return Max;
#endif

#if 0
		/*
		方法一 , 暴力法
		提交失败 , 原因 , 超时
		48/50 测试用例
		*/
		//最大容量
        int Max = 0;
		int len = height.size();
		if(len == 0)
			return 0;
		//宽
		int width = 0;
		//高
		int high = 0;
		for(int i = 0;i < len-1;++i)
		{
			for(int j =i+1;j < len;++j)
			{
				Max = max(Max, min(height[i], height[j]) * (j - i));
			}
		}
		return Max;
#endif
    }
};

int main()
{
	solution tmp ;
	vector<int> height ;
	height.push_back(1);
	height.push_back(8);
	height.push_back(6);
	height.push_back(2);
	height.push_back(5);
	height.push_back(4);
	height.push_back(8);
	height.push_back(3);
	height.push_back(7);
	// {1,8,6,2,5,4,8,3,7};
	
	cout<<tmp.maxArea(height)<<endl;


	return 0;
}

#endif