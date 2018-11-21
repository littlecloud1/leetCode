//leetcode 148. Sort List
//1. cut the list into two half
//2. recursively cut the reset of lit into two half
//3. apply merge sort to merge two link lists back. (merge two sorted linked list)


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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;

		//divide into two
		ListNode* p1 = head, *p2 = head->next;
		while (p2 && p2->next) {
			p1 = p1->next;
			p2 = p2->next->next;
		}
		p2 = p1->next;
		p1->next = NULL;
		p1 = head;
		p1 = sortList(p1);
		p2 = sortList(p2);

		return merge(p1, p2);
	}

	ListNode* merge(ListNode* p1, ListNode* p2) {
		if (!p1) return p2;
		if (!p2) return p1;

		ListNode* head = new ListNode(0);
		ListNode* tail = head;
		while (p1 && p2) {
			if (p1->val < p2->val) {
				tail->next = p1;
				p1 = p1->next;
			}
			else {
				tail->next = p2;
				p2 = p2->next;
			}
			tail = tail->next;
		}
		if (p1) tail->next = p1;
		if (p2) tail->next = p2;

		return head->next;

	}


};