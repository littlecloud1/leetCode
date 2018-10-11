//leetcode 19. Remove Nth Node From End of List
//go through the linked list to get the len
//then go through the linked list again and reach len-n and point to next next;

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n == 0) return head;
		if (!head) return head;
		ListNode* d = new ListNode(0);
		d->next = head;
		//count the length
		int len = 0;
		while (head) {
			len++;
			head = head->next;
		}
		if (len == 1) return head;
		head = d;
		for (int i = 0; i < len - n; i++) {
			head = head->next;
		}
		head->next = head->next->next;
		return d->next;
	}
};

//follow up:  do this in one pass
//use two pointer, the distance between 2 pointers is n
//then move both pointer until faster pointer reach the end
//set slower point next to next next.
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (n == 0 || !head) return head;
		ListNode* d = new ListNode(0); //assign dummies
		d->next = head;
		ListNode* f = d, *s = d;
		for (int i = 0; i < n; i++) f = f->next;
		while (f->next) {
			f = f->next;
			s = s->next;
		}
		s->next = s->next->next;
		return d->next;
	}

};