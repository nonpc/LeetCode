02两数加和

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807


/*
解题思路 :
为了节约空间 , 将加和的结果存放在两个链表中最长的那个中
拿到最长的链表 
逐位进行加和 , 满10 进一.
当最短的链表遍历完成之后 , 会出现如下情况 , 
两个链表等长 , 考虑进位 , 如果有进位 , 要将新建的节点插入尾部
两个链表不等长 , 对长链表的下一位进行进位判断 
*/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr)
            return nullptr;
      
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        int count1 = 0;
        int count2 = 0;
		//计算链表长度
        while(tmp1 != NULL)
        {
            count1++;
            tmp1 = tmp1->next;
        }
        while(tmp2 != NULL)
        {
            count2++;
            tmp2 = tmp2->next;
        }
                
		//得到长链表
        if(count1 < count2)
        {
            ListNode *tmp = l1;
            l1 = l2;
            l2 = tmp;
        } 
                
        tmp1 = l1;
        tmp2 = l2;
        
        ListNode *par = nullptr;
		//进位标识符
        bool flag = false;
        while(tmp2 != NULL)
        {
            if(flag)
            {
				//有进位
                tmp1->val += tmp2->val + 1;
                flag = false;
            }
            else
            {
				//无进位
                tmp1->val += tmp2->val;
                flag = false;
            }
            if(tmp1->val >= 10)
            {
				//满10进1
                tmp1->val -= 10;
                flag = true;
            }
            par = tmp1;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;   
        }
        
		//两个链表不等长
        while(tmp1 != NULL)
        {
            if(flag)
            {
                tmp1->val += 1;
                flag = false;
            }
            if(tmp1->val >= 10)
            {
                tmp1->val -= 10;
                flag = true;
            }
            par = tmp1;
            tmp1 = tmp1->next;
        }
		//两个链表等长 , 但是有进位
        if(tmp1 == NULL)
        {
            if(flag)
            {
                tmp1 = par;
                //tmp1->val -= 10;
                ListNode *p = new ListNode(1);
                tmp1->next = p;
            }
        }
        return l1;
    }
    
};