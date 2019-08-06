//23.合并k个排序链表
#if 0
/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6



 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 解题思路 : 
		找了一个投机的方法 , 将链表中的所有元素都放在容器中
		用sort()对它们进行排序 
		将排序后的结果插入到链表中


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
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		if (lists.empty())
			return nullptr;

		vector<int> arr;
		vector<ListNode*>::iterator it = lists.end();
		vector<ListNode*>::iterator it2 = lists.begin();
		int size = it - it2;
	
		for (int i = 0; i < size; ++i)
		{
			while (lists[i] != nullptr)
			{
				arr.push_back(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}
		//空链表
		if (arr.empty())
			return nullptr;
		vector<int>::iterator a1 = arr.begin();
		vector<int>::iterator a2 = arr.end();

		sort(a1,a2);

		ListNode* fin = new ListNode(arr[0]);
		ListNode* res = fin;
		for (int i = 1; i < arr.size(); ++i)
		{
			res->next = new ListNode(arr[i]);
			res = res->next;
		}
		return fin;
	}
};

int main()
{
	vector<ListNode*> arr;

	ListNode *tmp1 = new ListNode(1);
	ListNode* tmp3 = new ListNode(3);
	ListNode* tmp5 = new ListNode(5);
	tmp3->next = tmp5;
	tmp1->next = tmp3;
	arr.push_back(tmp1);

	ListNode* tmp2 = new ListNode(2);
	ListNode* tmp4 = new ListNode(4);
	ListNode* tmp6 = new ListNode(6);
	tmp4->next = tmp6;
	tmp2->next = tmp4;
	arr.push_back(tmp2);

	ListNode* _tmp1 = new ListNode(1);
	ListNode* _tmp7 = new ListNode(7);
	ListNode* _tmp9 = new ListNode(9);
	_tmp7->next = _tmp9;
	_tmp1->next = _tmp7;
	arr.push_back(_tmp1);

	/*vector<ListNode*>::iterator it = arr.end();
	vector<ListNode*>::iterator it2 = arr.begin();
	int size = it - it2;
	cout << "size : " << size << endl;*/

	Solution a;
	ListNode*res = a.mergeKLists(arr);
	
	while (res != nullptr)
	{
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;

	return 0;
}

#endif