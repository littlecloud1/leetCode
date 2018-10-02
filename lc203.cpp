/**
//leetcode: 203. Remove Linked List Elements
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (!head) return head;
		while (head && head->val == val) head = head->next;
		ListNode* newhead = head;
		ListNode* prev = head;
		while (head != NULL) {
			if (head->val == val) {
				prev->next = head->next;
			}
			else prev = head;
			head = head->next;
		}
		return newhead;
	}
};