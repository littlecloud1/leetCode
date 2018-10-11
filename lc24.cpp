//leetcode 24. Swap Nodes in Pairs
//set a dummy head
//set two pointers p and t, start from dummy
//t is the next node of p
//in the loop:
//let p->next = tail->next
//tail->next = tail->next->next 
// p->next->next = tail
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
	ListNode* swapPairs(ListNode* head) {
		if (!head) return head;
		ListNode* d = new ListNode(0);
		d->next = head;
		ListNode *p = d;
		while (p->next && p->next->next) {

			ListNode *t = p->next;
			p->next = t->next;
			t->next = t->next->next;
			p->next->next = t;
			p = t;

		}
		return d->next;
	}
};