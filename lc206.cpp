//leetcode 206. Reverse Linked List
//1. set a prev 
//2. set cur to head
//3. move head
//4. set cur->next to prev
//5. set prev to cur
//6. repeat until head == NULL
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
	ListNode* reverseList(ListNode* head) {
		if (!head) return NULL;
		ListNode* prev = NULL;
		ListNode* cur = head;
		while (head) {
			cur = head;
			head = head->next;
			cur->next = prev;
			prev = cur;
		}
		return prev;
	}
};