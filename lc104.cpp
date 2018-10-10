//leetcode 104. Maximum Depth of Binary Tree
//dfs

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
	int maxDepth(TreeNode* root) {
		int maxd = 0;
		dfs(root, 1, maxd);
		return maxd;

	}
	void dfs(TreeNode* root, int depth, int& maxd) {
		if (!root) return;
		if (root->left)dfs(root->left, depth + 1, maxd);
		maxd = max(maxd, depth);
		if (root->right)dfs(root->right, depth + 1, maxd);

	}
};