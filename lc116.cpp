//leetcode 116. Populating Next Right Pointers in Each Node
//similar to 117
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