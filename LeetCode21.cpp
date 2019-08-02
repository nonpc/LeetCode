//21.合并两个有序链表
#if 0
/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4


执行用时 :20 ms, 在所有 C++ 提交中击败了25.66% 的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了96.62%的用户

思路分析 : 
		设置一个用来接收的链表fin , 分别遍历两个链表 , 将val小的插入链表 
		如果有一个链表遍历完毕 , 如果另一个还不为空 , 将不为空的链表插入fin之后(因为是有序的,可以直接插入)

分析:
	查看了用时少的代码 , 他们用的是递归的方法 , 代码基本是相同的 .
	而编者个人觉得 , 多余的用时是在遍历链表计算链表长度 . 而且他们的代码是直接对形参进行操作 , 不是用中间量代替进行,
	感觉有一些不严谨

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };


 执行用时为 12 ms 的范例
 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * prelist = new ListNode(-1);
        ListNode *result = prelist;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                prelist->next = l1;
                l1 = l1->next;
                prelist = prelist->next;
            } else {
                prelist->next = l2;
                l2 = l2->next;
                prelist = prelist->next;
            }
        }
        if(l1) prelist->next = l1;
        if(l2) prelist->next = l2;
        return result->next;
    }
};


 

 */


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution 
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		//出错 , 一个为空 , 一个不为空
		if (l1 == nullptr && l2 != nullptr)
			return l2;
		if (l1 != nullptr && l2 == nullptr)
			return l1;
		if (l1 == nullptr && l2 == nullptr)
			return nullptr;
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		int count1 = 1;
		int count2 = 1;
		//计算链表长度
		while (cur1->next != nullptr)
		{
			++count1;
			cur1 = cur1->next;
		}
		while (cur2->next != nullptr)
		{
			++count2;
			cur2 = cur2->next;
		}
		//完成选择最长链表
		if (count1 < count2)
		{
			cur1 = l2;
			cur2 = l1;
		}
		else
		{
			cur1 = l1;
			cur2 = l2;
		}
		//cur1 指向长链表 , cur2 指向短链表
		ListNode* fin = nullptr;
		ListNode* res = nullptr;

		if (cur1->val <= cur2->val)
		{
			fin = cur1;
			cur1 = cur1->next;
		}
		else
		{
			fin = cur2;
			cur2 = cur2->next;
		}
		res = fin;
		

		while (cur2 != nullptr && cur1 != nullptr)
		{
			if (cur1->val <= cur2->val)
			{
				fin->next = cur1;
				cur1 = cur1->next;
			}
			else
			{
				fin->next = cur2;
				cur2 = cur2->next;
			}
			fin = fin->next;
		}
		//长链表遍历完毕
		if (cur1 == nullptr)
		{
			fin->next = cur2;
		}
		else if(cur2 == nullptr)
		{

			fin->next = cur1;
		}
		return res;
	}
};

int main()
{
	ListNode* arr = nullptr;
	ListNode* brr = nullptr;

	ListNode* tmp1 = new ListNode(1);
	ListNode* tmp4 = new ListNode(4);
	ListNode* tmp6 = new ListNode(6);
	ListNode* tmp7 = new ListNode(7);
	ListNode* tmp8 = new ListNode(8);

	tmp7->next = tmp8;
	tmp6->next = tmp7;
	tmp4->next = tmp6;
	tmp1->next = tmp4;
	//14678
	arr = tmp1;
	ListNode* tmp2 = new ListNode(2);
	ListNode* tmp3 = new ListNode(3);
	ListNode* tmp5 = new ListNode(5);
	ListNode* _tmp6 = new ListNode(6);
	ListNode* _tmp8 = new ListNode(8);

	_tmp6->next = _tmp8;
	tmp5->next = _tmp6;
	tmp3->next = tmp5;
	tmp2->next = tmp3;
	//23568
	brr = tmp2;

	Solution p;
	ListNode* res =  p.mergeTwoLists(arr, brr);

	ListNode* ll = res;
	while (ll != nullptr)
	{
		cout << ll->val << "->";
		ll = ll->next;
	}
	cout << endl;

	

	return 0;

}


#endif