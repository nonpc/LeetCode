//206. 反转链表
#if 0
/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {

	}
};

解题思路 : 
	保存当前节点作为父节点 , 向下递归 , 直到最后一个节点 . 
	将最后一个节点作为头节点保存 , 返回其地址 . 
	回退中 , 接收前节点 , 并将其next指向 , 已保存的父节点 . 返回父节点作为退回的接收节点
	在这中间要设置计数器 , 当回退到最后一个节点时 , 要返回链表的头结点


执行用时 :16 ms, 在所有 C++ 提交中击败了51.14% 的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了10.59%的用户

*/

 struct ListNode
 {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

 int _count = 0;
 ListNode* fin = nullptr;
class Solution 
{
public:
	ListNode* reverseList(ListNode* head) 
	{
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
		{
			fin = head;
			return head;
		}
		else
		{
			ListNode* par = head;
			head = head->next;
			par->next = nullptr;
			++_count;
			ListNode* tmp = reverseList(head);
			--_count;
			tmp->next = par;
			if (_count != 0)
				return par;
			else
				return fin;
		}
	}
};

int main()
{
	ListNode* tmp1 = new ListNode(1);
	ListNode* tmp2 = new ListNode(2);
	ListNode* tmp3 = new ListNode(3);
	ListNode* tmp4 = new ListNode(4);
	ListNode* tmp5 = new ListNode(5);
	tmp1->next = tmp2;
	tmp2->next = tmp3;
	tmp3->next = tmp4;
	tmp4->next = tmp5;

	Solution a;
	ListNode* arr = a.reverseList(tmp1);
	while (arr != nullptr)
	{
		cout << arr->val << " ";
		arr = arr->next;
	}
	cout << endl;


	return 0;
}

#endif