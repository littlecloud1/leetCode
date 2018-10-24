//leetcode 669. Trim a Binary Search Tree
//if L <= root->val < R:
//trim left and right
//if root->val >= R: ( val of all left leaves > root's val)
//root = trim(root->left)
//if root->val < L:
//root = trim(root->right)
//return root

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
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) return NULL;
		if (root->val >= L && root->val <= R) {
			root->left = trimBST(root->left, L, R);
			root->right = trimBST(root->right, L, R);
		}
		else if (root->val > R) {
			root = trimBST(root->left, L, R);
		}
		else {
			root = trimBST(root->right, L, R);
		}
		return root;
	}

};