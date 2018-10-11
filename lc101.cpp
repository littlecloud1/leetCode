//leetcode 101. Symmetric Tree
//split root L and R
//check L.val == R.val
//the recursive L.L and R.R
//and L.R and R.L
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
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return helper(root->left, root->right);
	}

	bool helper(TreeNode* left, TreeNode* right) {
		if (!left && !right) return true;
		if (!left || !right) return false;

		bool ll = helper(left->left, right->right);
		bool lr = helper(left->right, right->left);
		return (left->val == right->val) && ll && lr;

	}
};