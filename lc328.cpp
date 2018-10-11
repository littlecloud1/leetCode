//leetcode 328. Odd Even Linked List
//use a pointer to record the odd list and another pointer to record the even list
//also, one more pointer to keep track on the tail.
//everytime check if tail next exits
//if true then set odd next to tail next
//set tail next to next next
//update the pointer
//if false, the it reach the end,
//odd next set to even start
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
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* d = new ListNode(0);
		d->next = head;
		ListNode* po = head, *pe = head->next, *tail = head;
		while (tail->next) {
			tail = tail->next;
			if (tail->next) {
				po->next = tail->next;
				tail->next = tail->next->next;
				po = po->next;
			}
		}
		po->next = pe;
		return d->next;
	}
};