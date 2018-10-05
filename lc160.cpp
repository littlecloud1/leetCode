//leetcode 160. Intersection of Two Linked Lists
//use two pointer go through listNode A and B
//util they are same
//if A/B are null
// switch to another head
//if there are no intersections, both of them are equal to null and end the loop
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		ListNode* a = headA;
		ListNode* b = headB;

		while (a != b) {
			a = a == NULL ? headB : a->next;
			b = b == NULL ? headA : b->next;
		}
		return a;
	}
};