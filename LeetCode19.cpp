//19.删除的链表的倒数第n个节点
#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (head == NULL)
			return nullptr;
		ListNode* cur1 = head;
		ListNode* cur2 = head;
		int count = 1;
		while (cur1->next != NULL)
		{
			count++;
			cur1 = cur1->next;
		}


		if (n < 0 || n > count)
		{
			return nullptr;
		}

		//[1,2] n==2
		if (n == count && count > 1)
		{
			head = head->next;
			return head;
		}

		cur1 = head;
		while (n > 0)
		{
			if (cur1->next != NULL)
			{
				cur1 = cur1->next;
				--n;
			}
			else
			{
				return nullptr;
			}
		}
		while (cur1->next != NULL)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		ListNode* tmp = cur2->next;
		cur2->next = tmp->next;

		return head;
	}
};

#endif