//leetcode 138. Copy List with Random Pointer
//first create a new head for clone node
//1.generate clone node as the next postion for the original node:  o->c->o->c
//2.go through the list, o->next->random = o->random->next
//3.seperate clone node from original node
/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)return head;
		//step one clone node
		RandomListNode* newhead = head;
		while (head) {
			RandomListNode* clone = new RandomListNode(head->label);
			clone->next = head->next;
			head->next = clone;
			head = clone->next;
		}
		head = newhead;
		//step two clone random
		while (head && head->next) {
			head->next->random = (head->random == NULL) ? NULL : head->random->next;
			head = head->next->next;
		}
		//step 3 seperate original and clone
		head = newhead;
		newhead = newhead->next;
		while (head && head->next) {
			RandomListNode* nexto = head->next;
			head->next = head->next->next;
			if (head->next) nexto->next = head->next->next;
			head = head->next;

		}

		return newhead;
	}
};