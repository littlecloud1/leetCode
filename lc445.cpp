//leetcode 445. Add Two Numbers II
//use stack
//push all nodes into stacks
//sum += stack1 top
//sum += stack2 top
//head->val += sum
//head->val % 10
//create a new node with inital value head->val /10
//move the head
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;

		stack<int> s1;
		stack<int> s2;
		while (l1) {
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2) {
			s2.push(l2->val);
			l2 = l2->next;
		}
		ListNode* head = new ListNode(0);
		while (!s1.empty() || !s2.empty()) {
			if (!s1.empty()) {
				head->val += s1.top();
				s1.pop();
			}
			if (!s2.empty()) {
				head->val += s2.top();
				s2.pop();
			}
			ListNode* tmp = new ListNode(head->val / 10);
			head->val = head->val % 10;
			tmp->next = head;
			head = tmp;

		}

		return head->val == 0 ? head->next : head;
	}
};