//leetcode 285. Inorder Successor in BST
//successor should always > p's value
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!root || !p) return NULL;
		TreeNode* suc = NULL;
		while (root) {
			if (root->val > p->val) {
				suc = root;
				root = root->left;
			}
			else {
				root = root->right;
			}

		}

		return suc;
	}

};