//700. Search in a Binary Search Tree
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
	TreeNode* searchBST(TreeNode* root, int val) {
		TreeNode* res = NULL;
		if (val == root->val) res = root;
		else if (val < root->val && root->left) res = searchBST(root->left, val);
		else if (root->right) res = searchBST(root->right, val);
		return res;
	}
};