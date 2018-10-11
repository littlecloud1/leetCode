//leetcode 110. Balanced Binary Tree
//dfs the maxd of left and right tree
//if abs(l-r) > 1 then it is false and break
//return the max(l,r) to parent tree

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
	bool isBalanced(TreeNode* root) {
		bool valid = true;
		dfs(root, 0, valid);
		return valid;
	}

	int dfs(TreeNode* root, int depth, bool& valid) {
		if (!root) return depth;
		int l = dfs(root->left, depth + 1, valid);
		int r = dfs(root->right, depth + 1, valid);
		if (abs(l - r) > 1) valid = false;
		return max(l, r);
	}
};