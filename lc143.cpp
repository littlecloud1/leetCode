//leetcode 143. Reorder List
//1. find the middle node
//2. reverse the second half
//3. merge two list


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
	void reorderList(ListNode* head) {
		if (!head || !head->next) return;
		ListNode* p1 = head, *p2 = p1->next;
		while (p2 && p2->next) {
			p1 = p1->next;
			p2 = p2->next->next;
		}

		//reverse the second half
		p2 = p1->next;
		ListNode* prev = p1;
		while (p2->next) {
			ListNode* tmp = p2->next;
			p2->next = tmp->next;
			tmp->next = prev->next;
			prev->next = tmp;
		}

		//merge two linkelist
		p2 = p1->next;
		p1->next = NULL;
		p1 = head;
		while (p1) {
			ListNode* tmp = p1->next;
			p1->next = p2;
			p1 = p2;
			p2 = tmp;
		}



	}
};