//leetcode 117. Populating Next Right Pointers in Each Node II
//create a childhead and childtail pointer
//everytime link left and right node by childpointer,
//move the root within the same level by moving it to root next
//when the root next is null, which means it has finished this level
//move root to childhead.

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	void connect(TreeLinkNode *root) {
		while (root) {
			TreeLinkNode* childhead = new TreeLinkNode(0);
			TreeLinkNode* childtail = childhead;
			while (root) {
				if (root->left) {
					childtail->next = root->left;
					childtail = childtail->next;
				}
				if (root->right) {
					childtail->next = root->right;
					childtail = childtail->next;
				}
				root = root->next;
			}
			root = childhead->next;
		}
	}
};