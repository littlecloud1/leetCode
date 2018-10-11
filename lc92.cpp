//leetcode 92. Reverse Linked List II
//set a dummy value
//start from dummy, get p
//set the tail to p->next
//reverse mth node to n-1 node:
//set tmp to tail->next
//set tail->next to tmp->next
//set tmp->next to prev
//set p->next to tmp;
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head) return head;
		if (m == n)return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* p = dummy;
		for (int i = 1; i < m; i++)   p = p->next;
		ListNode* tail = p->next;
		for (int i = m; i < n; i++) {
			ListNode* tmp = tail->next;
			tail->next = tmp->next;
			tmp->next = p->next;
			p->next = tmp;
		}
		return dummy->next;
	}
};